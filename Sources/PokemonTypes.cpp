#include "PokemonTypes.hpp"

TypeTable& TypeTable::smt_Get()
{
    static TypeTable ls_Singleton;

    return ls_Singleton;
}

float TypeTable::mt_Get_Factor(Type move_type, Type pokemon_type)
{
    return m_Look_Up_Table[static_cast<std::size_t>(move_type)][static_cast<std::size_t>(pokemon_type)];
}

TypeTable::TypeTable()
{
    Type l_Move_Type;

    for (std::size_t l_Move_Type_Index = 0; l_Move_Type_Index < m_Look_Up_Table.size(); l_Move_Type_Index++)
    {
        for (std::size_t l_Pokemon_Type_Index = 0; l_Pokemon_Type_Index < m_Look_Up_Table[l_Move_Type_Index].size(); l_Pokemon_Type_Index++)
        {
            m_Look_Up_Table[l_Move_Type_Index][l_Pokemon_Type_Index] = 1.0f;
        }
    }

    l_Move_Type = Type::Steel;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Water, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Electric, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ice, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 2.0f);

    l_Move_Type = Type::Fighting;
    mt_Set_Factor(l_Move_Type, Type::Steel, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ice, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Normal, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Psychic, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 0.5f);

    l_Move_Type = Type::Dragon;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dragon, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 0.0f);

    l_Move_Type = Type::Water;
    mt_Set_Factor(l_Move_Type, Type::Dragon, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Water, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 2.0f);

    l_Move_Type = Type::Electric;
    mt_Set_Factor(l_Move_Type, Type::Dragon, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Water, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Electric, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 0.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 2.0f);

    l_Move_Type = Type::Fairy;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fighting, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Dragon, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 2.0f);

    l_Move_Type = Type::Fire;
    mt_Set_Factor(l_Move_Type, Type::Steel, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Dragon, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Water, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ice, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 0.5f);

    l_Move_Type = Type::Ice;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dragon, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Water, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ice, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 2.0f);

    l_Move_Type = Type::Bug;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fighting, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Psychic, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 0.5f);

    l_Move_Type = Type::Normal;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 0.0f);

    l_Move_Type = Type::Grass;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dragon, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 0.5f);

    l_Move_Type = Type::Poison;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.0f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 0.5f);

    l_Move_Type = Type::Psychic;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fighting, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Psychic, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 0.0f);

    l_Move_Type = Type::Rock;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fighting, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ice, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ground, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 2.0f);

    l_Move_Type = Type::Ground;
    mt_Set_Factor(l_Move_Type, Type::Steel, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Electric, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Fire, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Poison, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Flying, 0.0f);

    l_Move_Type = Type::Ghost;
    mt_Set_Factor(l_Move_Type, Type::Normal, 0.0f);
    mt_Set_Factor(l_Move_Type, Type::Psychic, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 0.5f);

    l_Move_Type = Type::Dark;
    mt_Set_Factor(l_Move_Type, Type::Fighting, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fairy, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Psychic, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Ghost, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Dark, 0.5f);

    l_Move_Type = Type::Flying;
    mt_Set_Factor(l_Move_Type, Type::Steel, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Fighting, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Electric, 0.5f);
    mt_Set_Factor(l_Move_Type, Type::Bug, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Grass, 2.0f);
    mt_Set_Factor(l_Move_Type, Type::Rock, 0.5f);
}

void TypeTable::mt_Set_Factor(Type move_type, Type pokemon_type, float factor)
{
    m_Look_Up_Table[static_cast<std::size_t>(move_type)][static_cast<std::size_t>(pokemon_type)] = factor;
}
