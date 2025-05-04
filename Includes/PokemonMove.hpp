#ifndef _POKEMON_MOVE_HPP
#define _POKEMON_MOVE_HPP 1

#include "PokemonTypes.hpp"

enum class DamageType
{
    Physical,
    Special,
    Status
};

struct Move
{
    int m_Power = 0;
    Type m_Type = Type::None;
    int m_Target_Count = 0;
};

#endif // _POKEMON_MOVE_HPP
