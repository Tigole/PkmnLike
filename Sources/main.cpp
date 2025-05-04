#include <iostream>
#include <array>

#include "PokemonDefinition.hpp"
#include "PokemonMove.hpp"
#include "PokemonFightHelper.hpp"

#include <fstream>
#include <sstream>

int main(int argc, char** argv)
{
    Pokemon l_Bulbasaur;
    Pokemon l_Charmander;
    Move l_Move;

    PokemonDefinition::sm_Definitions[0].m_Name = "Bulbizarre";
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Hit_Point = 45;
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Physical_Attack = 49;
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Physical_Defense = 49;
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Special_Attack = 65;
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Special_Defense = 65;
    PokemonDefinition::sm_Definitions[0].m_Base_State.m_Struct.m_Speed = 45;
    PokemonDefinition::sm_Definitions[0].m_Types[0] = Type::Grass;
    PokemonDefinition::sm_Definitions[0].m_Types[1] = Type::Poison;

    PokemonDefinition::sm_Definitions[1].m_Name = "Salamèche";
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Hit_Point = 39;
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Physical_Attack = 52;
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Physical_Defense = 43;
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Special_Attack = 60;
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Special_Defense = 50;
    PokemonDefinition::sm_Definitions[1].m_Base_State.m_Struct.m_Speed = 65;
    PokemonDefinition::sm_Definitions[1].m_Types[0] = Type::Fire;
    PokemonDefinition::sm_Definitions[1].m_Types[1] = Type::None;

    l_Bulbasaur.m_Level = 5;
    l_Bulbasaur.m_Id = 0;
    fn_Update_Current_Stat(l_Bulbasaur);

    l_Charmander.m_Level = 5;
    l_Charmander.m_Id = 1;
    fn_Update_Current_Stat(l_Charmander);

    l_Move.m_Power = 40;
    l_Move.m_Type = Type::Normal;
    l_Move.m_Target_Count = 1;

    std::cout << "damages: " << fn_Compute_Damages(l_Charmander, l_Bulbasaur, l_Move) << '\n';

    //system("PAUSE");

    return 0;
}
