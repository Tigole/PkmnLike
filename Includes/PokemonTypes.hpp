#ifndef _POKEMON_TYPES_HPP
#define _POKEMON_TYPES_HPP 1

#include <array>

enum class Type
{
    None = 0,
    Normal = 1,
    Fire = 2,
    Water = 3,
    Electric = 4,
    Grass = 5,
    Ice = 6,
    Fighting = 7,
    Poison = 8,
    Ground = 9,
    Flying = 10,
    Psychic = 11,
    Bug = 12,
    Rock = 13,
    Ghost = 14,
    Dragon = 15,
    Steel = 16,
    Dark = 17,
    Fairy = 18,

    COUNT
};


class TypeTable
{
public:
    static TypeTable& smt_Get();

    float mt_Get_Factor(Type move_type, Type pokemon_type);

private:
    TypeTable();

    void mt_Set_Factor(Type move_type, Type pokemon_type, float factor);
    std::array<std::array<float ,static_cast<std::size_t>(Type::COUNT)>, static_cast<std::size_t>(Type::COUNT)> m_Look_Up_Table;
};


#endif // _POKEMON_TYPES_HPP
