#ifndef PAWN_HPP
#define PAWN_HPP
#include "piece.hpp"
#include <utility>
#include <vector>
#include <memory>

class Pawn: public Piece{
public:
    Pawn(Color color, Type type = pawn);
    
    void move(int fromX, int fromY, int toX, int toY);
    bool isOnRankEight(int rank);
    std::vector<std::pair<int,int>> pawnLegalMoves(int x, int y,
                                          const std::shared_ptr <Piece> board[8][8]);
    friend class Piece;
private:
    bool _hasMoved;

};

#endif //PAWN_HPP
