#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP
#include <QObject>
#include <memory>
#include <utility>
#include <vector>
#include "piece.hpp"

enum Turn {b = 0, w = 1};
/**
 * @brief The Gameboard class
 */
class Gameboard : public QObject{
    Q_OBJECT
public:
    Gameboard(QObject *parent = nullptr);
    /**
     * @brief getLegalMoves Gets the legal moves of the given piece.
     * @param x X coordinate
     * @param y Y coordinate
     * @returns _legalMoves
     */
    std::vector<std::pair<int,int>> getLegalMoves(int x, int y);
    /**
     * @brief isMoveLegal Checks if the recieved move from the network/GUI is legal.
     * @param x X coordinate
     * @param y Y coordinate
     * @return bool
     */
    bool isMoveLegal(int x, int y);
    /**
     * @brief move Moves piece from location to destination.
     * @param fromX past X coordinate
     * @param fromY past Y coordinate
     * @param toX X coordinate of destination
     * @param toY Y coordinate of destination
     */
    void move(int fromX, int fromY, int toX, int toY);
    /**
     * @brief isKingChecked After a move checks whether the opposing king is in check.
     */
    void isKingChecked();
    /**
     * @brief hasCastled Checks if the move was a castling move, if so calls the castle() function.
     * @param fromY Y coordinate of the king.
     * @param x X coordinate of destination
     * @param y Y coordinate of destination
     * @return True if castled.
     */
    bool hasCastled(int fromY, int x,int y);
    /**
     * @brief hasGameEnded Checks the state of the game.
     */
    void hasGameEnded();
    /**
     * @brief enPassant Checks if a pawn has the option to capture "En passant".
     * @param fromX Past X coordinate of opposing piece.
     * @param fromY Past Y coordinate of opposing piece.
     * @param toX Final X coordinate of opposing piece.
     * @param toY Final Y coordinate of opposing piece.
     */
    void getThreats();
    /**
     * @brief getVirtualThreats Creates the virtual threat grid for opposing for the next move,
     * this allows to determine if a move is legal.
     */
    void getVirtualThreats();
    /**
     * @brief getKingPosition Saves the kings position for the player on turn.
     * Essential to determine legal moves, since logic does'nt
     */
    void getKingPosition();
    /**
     * @brief promote Signals the GUI a promotionn happened, so that the prompt is showed to select the piece to promote.
     * @param x X coordinate of promotion.
     * @param y Y coordinate of promotion.
     */
    void promote(int x, int y);
    /**
     * @brief castle Moves the rook for castles.
     * @param type Used to determine castling type.(Black short, Black long, White short, White long)
     */
    void castle(int type);
    /**
     * @brief changeTurn Changes the turn.
     */
    void changeTurn(void);
    /**
     * @brief resetThreatGrid Clears threat grid, every turn.
     */
    void resetThreatGrid();
    /**
     * @brief resetVirtualGrid Clears the virtual grid, allow new calculations.
     */
    void resetVirtualGrid();
    void clearGameboard();
    /**
     * @brief pawnMoves Checks the legal moves for pawn.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void pawnMoves(int x, int y);
    /**
     * @brief knightMoves Checks the legal moves for knight.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void knightMoves(int x,int y);
    /**
     * @brief bishopMoves Checks the legal moves for bishop.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void bishopMoves(int x,int y);
    /**
     * @brief rookMoves Checks the legal moves for rook.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void rookMoves(int x, int y);
    /**
     * @brief queenMoves Checks the legal moves for queen.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void queenMoves(int x, int y);
    /**
     * @brief kingMoves Checks the legal moves for king.
     * @param x X coordinate
     * @param y Y cooridnate
     */
    void kingMoves(int x, int y);
    /**
     * @brief pawnThreatens Checks where the opponents pawns control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void pawnThreatens(int x, int y,bool grid[8][8]);
    /**
     * @brief knightThreatens Checks where the opponents knights control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void knightThreatens(int x,int y,bool grid[8][8]);
    /**
     * @brief bishopThreatens Checks where the opponents bishop control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void bishopThreatens(int x,int y,bool grid[8][8]);
    /**
     * @brief rookThreatens Checks where the opponents rooks control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void rookThreatens(int x, int y, bool grid[8][8]);
    /**
     * @brief queenThreatens Checks where the opponents queen control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void queenThreatens(int x, int y, bool grid[8][8]);
    /**
     * @brief kingThreatens Checks where the opponents king control on the board.
     * @param x X coordinate
     * @param y Y cooridnate
     * @param grid It can be called for threatGrid and virtualGrid.
     */
    void kingThreatens(int x, int y, bool grid[8][8]);

    int playerColor;
    bool networkPromotion;



public slots:
    /**
     * @brief initGameboard Initializes the gameboard after the start signal from network.
     */
    void initGameboard();
    /**
     * @brief getClick Recieves click from GUI and interprets. Game manager so to say.
     * @param x X coordinate
     * @param y Y coordinate
     */
    void getClick(int x, int y);
    /**
     * @brief getPromotion Recieves the selected piece from the GUI for promotion.
     * @param type Piece type
     */
    void getPromotion(int type);
    /**
     * @brief setPlayerColor Setter for player, network decides.
     * @param color
     */
    void setPlayerColor(int color);
    /**
     * @brief networkInput Comms with network
     * @param fromX
     * @param fromY
     * @param toX
     * @param toY
     * @param promotionType
     * @param consequence Defined in network protocol.
     */
    void networkInput(int fromX, int fromY, int toX, int toY, int promotionType, int consequence);

signals:
    void initGui(int turn);
    void sendMove(int fromX, int fromY, int toX, int toY);
    void sendLegalMoves(std::vector<std::pair<int,int>> _legalMoves, int _fromX, int _fromY);
    void sendNotLegal();
    void networkSendMove(quint8 cmd, quint8 startRow, quint8 startColumun,
                         quint8 targetRow, quint8 targetColumn, quint8 promotionType,quint8 consequence, quint8 status);
    void sendPromotion(int x);
    void sendCheck(int x, int y);
    void hasPromoted(int x, int y, int type);
    void getPromotionType(int type);
    void logicTurn(int _turn);
    void guiChecked();
    void sendCastle();
    void endGame(int type, int turn);


private:
    std::shared_ptr <Piece> board[8][8];
    bool threatGrid[8][8];
    bool virtualGrid[8][8];
    std::vector<std::pair<int,int>> _legalMoves;
    std::vector<std::pair<int,int>> _whiteThreats;
    std::vector<std::pair<int,int>> _blackThreats;

    bool _firstClick = true;
    int _fromX;
    int _fromY;
    Turn _turn;
    int _promX;
    int _promY;
    bool _kingChecked;
    int _castleType;
    bool _captured;
    std::pair<int,int> _kingPosition;
    bool _enpassant;
    bool _gameEnded;


};

#endif //GAMEBOARD_HPP
