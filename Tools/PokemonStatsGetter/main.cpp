#include "PokemonGetter.hpp"

void fn_Load_Pokemon_Data()
{
    PokemonGetter l_Pokemon_Getter;
    const char* l_Temp_File = "result.txt";

    l_Pokemon_Getter.mt_Get_Pokemon("salameche", "platine", l_Temp_File);
}

int main()
{
    fn_Load_Pokemon_Data();

    return 0;
}
