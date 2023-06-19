#include <cstdlib>

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief Minimax get a legal action
 * 
 * @param state next state
 * @param depth You may need this for other policy 
 * @return Move 
 */

int max(int a, int b) {return a > b ? a : b;}
int min(int a, int b) {return a < b ? a : b;}

Move Minimax::get_move(State *state, int depth, bool minimaxplayer){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  if(minimaxplayer){
      int value = -1e9;
      Move bestnext;
      for(Move next : state->legal_actions){
        State *child = state->next_state(next);
        int child_value = minimax(child, depth-1 , false);

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
        int child_value = minimax(child, depth-1 , true);

        if(child_value < value){
          value = child_value;
          worstnext = next;
        }
          delete child;
      }
        return worstnext;
  }
}

int Minimax::minimax(State *state, int depth, bool minimaxplayer){
  //if((depth == 0 || !state->legal_actions.size()) && minimaxplayer)
    //return state->evaluate1();
  //if((depth == 0 || !state->legal_actions.size()) && !minimaxplayer)
    //return state->evaluate2();
    //role = Minimax::role;
    if((depth == 0 || !state->legal_actions.size()))
      return state->evaluate2();
  
  if(minimaxplayer){
    int value = -1e9;
    
    for(Move next : state->legal_actions){
      State *child = state->next_state(next);
      value = std::max(value,minimax(child, depth - 1, false));
      delete child;
    }
      return value;
  } else {
    int value = 1e9;

    for(Move next : state->legal_actions){
      State* child = state->next_state(next);
      value = std::min(value,minimax(child, depth - 1, true));
      delete child;
    }
      return value;
  }
}