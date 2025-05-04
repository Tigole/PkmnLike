#include "PokemonFightHelper.hpp"
#include "PokemonDefinition.hpp"
#include "PokemonMove.hpp"

void fn_Update_Current_Stat(Pokemon& p)
{
    int iv = 0;
    int ev = 0;
    int nature = 1;
    auto l_fn_Stat = [](int level, int base, int iv, int ev, int nature)
    {
        return (((2 * base + iv + ev/4) * level / 100) + 5) * nature;
    };
    const PokemonStatStruct& l_Base_State = PokemonDefinition::sm_Definitions[p.m_Id].m_Base_State.m_Struct;

    p.m_Current_Stat.m_Struct.m_Hit_Point = ((2 * l_Base_State.m_Hit_Point + iv + ev/4) * p.m_Level / 100.0f) + p.m_Level + 10;
    p.m_Current_Stat.m_Struct.m_Physical_Attack = l_fn_Stat(p.m_Level, l_Base_State.m_Physical_Attack, iv, ev, nature);
    p.m_Current_Stat.m_Struct.m_Physical_Defense = l_fn_Stat(p.m_Level, l_Base_State.m_Physical_Defense, iv, ev, nature);
    p.m_Current_Stat.m_Struct.m_Special_Attack = l_fn_Stat(p.m_Level, l_Base_State.m_Special_Attack, iv, ev, nature);
    p.m_Current_Stat.m_Struct.m_Special_Defense = l_fn_Stat(p.m_Level, l_Base_State.m_Special_Defense, iv, ev, nature);
    p.m_Current_Stat.m_Struct.m_Speed = l_fn_Stat(p.m_Level, l_Base_State.m_Speed, iv, ev, nature);
}


float fn_Compute_Targets_Factor(int move_target_count)
{
    return move_target_count > 1 ? 0.75f : 1.0f;
}

float fn_Compute_STAB_Factor(Type move_type, const std::array<Type, 2>& pokemon_types)
{
    const float l_Type_0 = (move_type == pokemon_types[0]) ? 1.5f : 1.0f;
    const float l_Type_1 = (move_type == pokemon_types[1]) ? 1.5f : 1.0f;

    return l_Type_0 * l_Type_1;
}

float fn_Compute_Burn_Factor(bool burned)
{
    return burned ? 0.5f : 1.0f;
}

int fn_Compute_Damages(const Pokemon& attacker, const Pokemon& defender, const Move& move)
{
    const float l_Level = (2 * attacker.m_Level) / 5 + 2;
    const float l_Main = (l_Level * move.m_Power * attacker.m_Current_Stat.m_Struct.m_Physical_Attack / defender.m_Current_Stat.m_Struct.m_Physical_Defense) / 50.0f + 2.0f;
    const float l_Targets_Factor = fn_Compute_Targets_Factor(move.m_Target_Count);
    const float l_Weather_Factor = 1.0;
    const float l_Critical_Factor = 1.0f;
    const float l_Random_Factor = 1.0f;
    const float l_STAB_Factor = fn_Compute_STAB_Factor(move.m_Type, PokemonDefinition::sm_Definitions[attacker.m_Id].m_Types);
    const float l_Type_Factor = TypeTable::smt_Get().mt_Get_Factor(move.m_Type, PokemonDefinition::sm_Definitions[defender.m_Id].m_Types[0]) * TypeTable::smt_Get().mt_Get_Factor(move.m_Type, PokemonDefinition::sm_Definitions[defender.m_Id].m_Types[1]);
    const float l_Burn_Factor = 1.0f;
    const float l_Other_Factor = fn_Compute_Burn_Factor(attacker.m_Flags.m_Burned);
    const int l_Ret = l_Main * l_Targets_Factor * l_Weather_Factor * l_Critical_Factor * l_Random_Factor * l_STAB_Factor * l_Type_Factor * l_Burn_Factor * l_Other_Factor;

    return l_Ret;
}

