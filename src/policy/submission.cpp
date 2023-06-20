#include <cstdlib>

#include "../state/state.hpp"
#include "./alphabeta.hpp"


/**
 * @brief Randomly get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
//int max(int a, int b) {return a > b ? a : b;}
//int min(int a, int b) {return a < b ? a : b;}

Move AlphaBeta::get_move(State *state, int depth, bool minimaxplayer){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  if(minimaxplayer){
      int value = -1e9;
      Move bestnext;
      for(Move next : state->legal_actions){
        State *child = state->next_state(next);
        int child_value = alphabeta(child, depth-1 , false, -1e9, 1e9);

        if(child_value > value) {
            value = child_value;
            bestnext = next;
        }
          delete child;
      }
        return bestnext;
  } else {
      int value = 1e9;
      Move worstnext;

      for(auto next : state->legal_actions){
        State *child = state->next_state(next);
        int child_value = alphabeta(child, depth-1 , true, -1e9, 1e9);

        if(child_value < value){
          value = child_value;
          worstnext = next;
        }
          delete child;
      }
        return worstnext;
  }
}

int AlphaBeta::alphabeta(State *state, int depth, bool minimaxplayer, int alpha, int beta){
  //if((depth == 0 || !state->legal_actions.size()) && minimaxplayer)
    //return state->evaluate1();
  //if((depth == 0 || !state->legal_actions.size()) && !minimaxplayer)
    //return state->evaluate2();
    //role = Minimax::role;
    if((depth == 0 || !state->legal_actions.size()))
      return state->evaluate1();
  
  if(minimaxplayer){
    int value = -1e9;
    
    for(Move next : state->legal_actions){
      State *child = state->next_state(next);
      value = std::max(value,alphabeta(child, depth - 1, false, alpha, beta));
      alpha = std::max(alpha,value);
      delete child;
        if(alpha >= beta) break;
    }
      return value;
  } else {
    int value = 1e9;

    for(Move next : state->legal_actions){
      State* child = state->next_state(next);
      value = std::min(value,alphabeta(child, depth - 1, true, alpha, beta));
      beta = std::min(beta,value);
      delete child;
        if(beta <= alpha) break;
    }
      return value;
  }
}