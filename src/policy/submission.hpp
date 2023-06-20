#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class AlphaBeta{
public:
  static Move get_move(State *state, int depth, bool player);
  static int alphabeta(State *state, int depth, bool player, int alpha, int beta);
};