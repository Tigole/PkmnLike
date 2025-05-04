#ifndef _POKEMON_GETTER_HPP
#define _POKEMON_GETTER_HPP 1

#include <string>
#include <vector>
#include <array>

class PokemonGetter
{
public:
    PokemonGetter();
    ~PokemonGetter();

    void mt_Get_Pokemon(const char* pokemon, const char* version, const char* file_path);

private:

    static void smt_Create_Request(const char* pokemon, const char* version, std::string& request);
    static size_t smt_On_Receive(char* buffer, size_t size, size_t nmemb, void* userp);

    void* m_Curl = nullptr;
    std::string m_Buffer = {};
    std::string m_Request = {};

    std::array<int, 6> m_Characteristics = {};
    void mt_Extract_Characteristics(void);
    std::array<std::string, 2> m_Types = {};
    void mt_Extract_Types(void);
    int m_Id;
    std::string m_Name;
    void mt_Extract_Identification(void);

    void mt_Write_To_File(const char* file_path);
};

#endif // _POKEMON_GETTER_HPP
