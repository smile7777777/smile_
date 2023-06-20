#ifndef __STATE_H__
#define __STATE_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>

#include "../config.hpp"


typedef std::pair<size_t, size_t> Point;
typedef std::pair<Point, Point> Move;
class Board{
  public:

    double Pawn_Values[2][6][5] = {{
      //white
    { 5,  5,  5,  5,  5 },
    { 2,  2,  2,  2,  2 },
    { 1.5,  2,  1.5,  2,  1.5 },
    { 1.5,  1.5,  1.5,  1,  1 },
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 },},{
      //black
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1.5,  1.5,  1.5 },
    { 1.5,  2,  1.5,  2,  1.5 },
    { 2,  2,  2,  2,  2 },
    { 5,  5,  5,  5,  5 }
    }
  };
  int bishop_Values[2][6][5] = {{
      //white
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 },
    { 1,  2,  1,  2,  1 },
    { 2,  1,  2,  1,  2 },
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 },},{
      //black
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 },
    { 2,  1,  2,  1,  2 },
    { 1,  2,  1,  2,  1 },
    { 1,  1,  1,  1,  1 },
    { 1,  1,  1,  1,  1 }
    }
  };
  int queen_Values[2][6][5] = {{
      //white
    { 0,  0,  0,  0,  0 },
    { 0,  30,  30,  30,  0 },
    { 50,  100,  150,  30,  20 },
    { 20,  100,  150,  30,  20 },
    { 0,  30,  30,  30,  0 },
    { 0,  0,  0,  0,  0 },},{
      //black
    { 0,  0,  0,  0,  0 },
    { 0,  30,  30,  30,  0 },
    { 50,  30,  150,  100,  50 },
    { 50,  30,  150,  100,  50 },
    { 0,  30,  30,  30,  0 },
    { 0,  0,  0,  0,  0 }
    }
  };
  int knight_Values[2][6][5] = {{
      //white
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },
    { 200,  0,  200,  0,  0 },
    { 0,  0,  0,  200,  0 },
    { 0,  0,  0,  0,  0 },},{
      //black
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },
    { 200,  0,  200,  0,  0 },
    { 0,  0,  0,  200,  0 },
    { 0,  0,  0,  0,  0 }
    }
  };
  int rook_Values[2][6][5] = {{
      //white
    { 0,  0,  0,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  0,  0,  0 },},{
      //black
    { 0,  0,  0,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  50,  0,  0 },
    { 0,  0,  0,  0,  0 }
    }
  };
    int king_Values[2][6][5] = {{
      //white
    { 20,  20,  20,  20,  20 },
    { 20,  20,  20,  20,  20 },
    { 15,  15,  15,  15,  15 },
    { 1,  1,  1,  1,  1 },
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },},{
      //black
    { 0,  0,  0,  0,  0 },
    { 0,  0,  0,  0,  0 },
    { 1,  1,  1,  1,  1 },
    { 15,  15,  15,  15,  15 },
    { 20,  20,  20,  20,  20 },
    { 20,  20,  20,  20,  20 }
    }
  };   

    char board[2][BOARD_H][BOARD_W] = {{
      //white
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1},
      {2, 3, 4, 5, 6},
    }, {
      //black
      {6, 5, 4, 3, 2},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0},
    }};
};

enum GameState {
  UNKNOWN = 0,
  WIN,
  DRAW,
  NONE
};


class State{
  public:
    //You may want to add more property for a state
    GameState game_state = UNKNOWN;
    Board board;
    int player = 0;
    std::vector<Move> legal_actions;
    
    State(){};
    State(int player): player(player){};
    State(Board board): board(board){};
    State(Board board, int player): board(board), player(player){};
    
    int evaluate1();
    int evaluate2();
    State* next_state(Move move);
    void get_legal_actions();
    std::string encode_output();
    std::string encode_state();
};

#endif