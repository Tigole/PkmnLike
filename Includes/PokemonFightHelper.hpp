#ifndef _POKEMON_FIGHT_HELPER_HPP
#define _POKEMON_FIGHT_HELPER_HPP 1

#include "PokemonTypes.hpp"

struct Pokemon;
struct Move;

void fn_Update_Current_Stat(Pokemon& p);

float fn_Compute_Targets_Factor(int move_target_count);

float fn_Compute_STAB_Factor(Type move_type, const std::array<Type, 2>& pokemon_types);

float fn_Compute_Burn_Factor(bool burned);

int fn_Compute_Damages(const Pokemon& attacker, const Pokemon& defender, const Move& move);


#endif // _POKEMON_FIGHT_HELPER_HPP
