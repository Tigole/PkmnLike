#include "PokemonGetter.hpp"
#include <curl/curl.h>
#include <iostream>


PokemonGetter::PokemonGetter()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);

    m_Curl = curl_easy_init();

    curl_easy_setopt(m_Curl, CURLOPT_WRITEFUNCTION, &PokemonGetter::smt_On_Receive);
    curl_easy_setopt(m_Curl, CURLOPT_WRITEDATA, this);
}

PokemonGetter::~PokemonGetter()
{
    curl_easy_cleanup(m_Curl);
    curl_global_cleanup();
}

void PokemonGetter::mt_Get_Pokemon(const char* pokemon, const char* version, const char* file_path)
{
    CURLcode l_Result_Code;

    m_Buffer.clear();
    smt_Create_Request(pokemon, version, m_Request);

    curl_easy_setopt(m_Curl, CURLOPT_URL, m_Request.c_str());
    l_Result_Code = curl_easy_perform(m_Curl);

    std::cout << "Return code: " << l_Result_Code << '\n';
    if (l_Result_Code == CURLcode::CURLE_OK)
    {
        mt_Extract_Characteristics();
        mt_Extract_Types();
        mt_Extract_Identification();


        mt_Write_To_File(file_path);

        /*char* l_Result_Content;

        l_Result_Code = curl_easy_getinfo(m_Curl, CURLINFO_CONTENT_TYPE, &l_Result_Content);

        if (l_Result_Code == CURLcode::CURLE_OK)
        {
            std::cout << l_Result_Content << '\n';
        }*/
    }
}

void PokemonGetter::smt_Create_Request(const char* pokemon, const char* version, std::string& request)
{
    request = "https://www.pokebip.com/pokedex/";
    request += version;
    request += "/pokemon/";
    request += pokemon;
}

size_t PokemonGetter::smt_On_Receive(char* buffer, size_t size, size_t nmemb, void* userp)
{
    PokemonGetter* l_This = static_cast<PokemonGetter*>(userp);

    l_This->m_Buffer += buffer, size * nmemb;

    return size * nmemb;
}

void PokemonGetter::mt_Extract_Characteristics(void)
{
    std::size_t l_Start_Pos = m_Buffer.find(">PV</td>");

    for (std::size_t ii = 0; ii < m_Characteristics.size(); ii++)
    {
        l_Start_Pos = m_Buffer.find("<strong>", l_Start_Pos + 1);
        l_Start_Pos += strlen("<strong>");
        std::string l_Charac_Value = m_Buffer.substr(l_Start_Pos, m_Buffer.find("</strong>", l_Start_Pos));
        m_Characteristics[ii] = std::stoi(l_Charac_Value);
    }
}

void PokemonGetter::mt_Extract_Types(void)
{
    //"<p><img src='/pokedex-images/types/"
    //m_Types
}

void PokemonGetter::mt_Extract_Identification()
{
    const std::string l_Name_String = "<a href=\"" + m_Request + "\">";
    std::size_t l_Name_Start_Pos = m_Buffer.find(l_Name_String);
    std::size_t l_Name_End_Pos = m_Buffer.find("", l_Name_Start_Pos);
    constexpr const char* l_Id_Start_String = "<td>National</td>";
    std::size_t l_Id_Start_Pos = m_Buffer.find(l_Id_Start_String);
    std::size_t l_Id_End_Pos = m_Buffer.find("</td>", l_Id_Start_Pos + strlen(l_Id_Start_String));

    m_Id = 0;
    m_Name = m_Buffer.substr(l_Name_Start_Pos, l_Name_End_Pos - l_Name_Start_Pos);
}


#include <TinyXML_Boosted/tinyxml.h>
void PokemonGetter::mt_Write_To_File(const char* file_path)
{
    TiXmlDocument l_Document;
    TiXmlElement* l_Root;

    if (l_Document.LoadFile(file_path) == false)
    {
        l_Root = new TiXmlElement("PokemonDescription");
        l_Document.LinkEndChild(l_Root);
    }

    l_Document.SaveFile(file_path);
}