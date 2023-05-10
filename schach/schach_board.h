#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QFrame>
#include <QLabel>
#include <utility>
#include <array>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class Board; }
QT_END_NAMESPACE
/**
 * @brief The Board class
 */
class Board : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Sets the pieces on the board Saves the QPushbuttons and QLabels created in the designer to an array.
     *
     * @param parent QWidget. Defaults to nullptr.
     */
    Board(QWidget *parent = nullptr);
    ~Board();

private:
    /**
     * @brief Pointer to the user interface
     */
    Ui::Board *ui;

    /**
    * @brief button 8x8 Array for iterating over QPushButtons and QLabels on the chessboard.
    *
    * Index of QPushButtons/QLabels correlates to index within the chessboard.
    * All QLabels are Empty PNGs in the ui.
    */
   std::array<std::array<std::pair<QPushButton*, QLabel*>, 8>, 8> button;

   /**
    * @brief QPixmap pictures of all the required chess pieces.
    *
    *Nul0 is used a lot for moving and capturing pieces.
    *The rest are used to set the QLabels on the chessboard at the start of the game.
    */
    QPixmap Nul0 = QPixmap(":/Chess pieces/Empty_Field.png");  //Empty PNG
    QPixmap WKing = QPixmap(":/Chess pieces/Chess_WKing.png");
    QPixmap WQueen = QPixmap(":/Chess pieces/Chess_WQueen.png");
    QPixmap WRook = QPixmap(":/Chess pieces/Chess_WRook.png");
    QPixmap WBishop = QPixmap(":/Chess pieces/Chess_WBishop.png");
    QPixmap WKnight = QPixmap(":/Chess pieces/Chess_WKnight.png");
    QPixmap WPawn = QPixmap(":/Chess pieces/Chess_WPawn.png");
    QPixmap BKing = QPixmap(":/Chess pieces/Chess_BKing.png");
    QPixmap BQueen = QPixmap(":/Chess pieces/Chess_BQueen.png");
    QPixmap BBishop = QPixmap(":/Chess pieces/Chess_BBishop.png");
    QPixmap BKnight = QPixmap(":/Chess pieces/Chess_BKnight.png");
    QPixmap BRook = QPixmap(":/Chess pieces/Chess_BRook.png");
    QPixmap BPawn = QPixmap(":/Chess pieces/Chess_BPawn.png");

    /**
     * @brief StyleSheets for painting the frames of the chessboard at the start.
     */
   QString hellsetting = "QFrame{background-color: rgb(181, 136, 99);}\n";
   QString darksetting = "QFrame{background-color: rgb(240, 217, 181);}\n";
   /**
    * @brief StyleSheets for highlighting the frames of a chosen chess piece and the frames that piece can move to.
    */
   QString highLit = "QFrame{background-color: rgb(179, 138, 100); border: 2px solid blue}";
   QString darkLit = "QFrame{background-color: rgb(242, 219, 183); border: 2px solid blue}";
   /**
    * @brief StyleSheet for the QPushButton. Makes them transparent even when pressed.
    */
   QString invisButt = "QPushButton:pressed{background-color: rgba(255, 165, 137, 0); border: none;}";

   /**
    * @brief framers. Vector that saves the positions of highlighted fields on the chessboard.
    */
   std::vector<std::pair<int,int>> framers;
   /**
    * @brief lightUp. Helper function that highlights or de-highlights the frames if already highlighted.
    *
    * Uses button array to access the frames that are parent widgets of the QPushButtons/QLabels.
    * @param x. Row of field on the chessboard
    * @param y. Colomn of frame on the chessboard
    */
   void lightUp(int x, int y);

   /**
    * @brief m_highlighted. True if fields on the chessboard are highlighted.
    */
   bool m_highlighted = false;

   /**
    * @brief initTurn. Shows if game is in first round. Used by gameplay display prompt.
    */
   bool initTurn = true; //for the game display
   /**
    * @brief checkedKing. True if King is in check. Used by gameplay display prompt.
    */
   int checkedKing = false;



public slots:
   /**
     * @brief startBoard. Initializes the chessboard at the start of the game.
     *
     * Iterates over the button array.
     * It flips the coordinates of the QPushButtons/QLabels based on if player is black.
     * Sets the pieces on the Board and colours the frames of the Board accordingly.
     * Sets the starting game display prompts and hides other game prompts and buttons.
     * Connects  the QPushButtons to a lambda function that send the position of a clicked piece.
     *
     * @param type. Receives from Network. Determines if player is Black or White.
     */
    void startBoard(int type); //switches Board in case of starting Black. Receives type from Network

    /**
     * @brief moveLabel
     *
     * Called by Logic and receives the coordinates as a signal.
     *  De-higlights frames in the framers vector and clears the vector.
     *
     * @param fromX. Row of selected piece.
     * @param fromY. Column of selected piece.
     * @param toX.  Row of selected field.
     * @param toY.  Column of selected field.
     */
    void moveLabel(int fromX, int fromY, int toX, int toY); //moves Pieces on GUI

    /**
     * @brief uses lightUp method to highlights frames and saves highlighted frames in framers vector.
     *
     *Called by Logic and receives vector as well as the position of the selected piece as a signal.
     *  @param moves. vector that contains positons the piece can move to.
     *  @param fromX. Row of selected piece.
     *  @param fromY. Column of selected piece.
     */
    void highLite(std::vector<std::pair<int,int>> moves, int fromX, int fromY); //highlights fields on GUI

    /**
     * @brief NoMove. Removes highlights in case of no or invalid movement.
     * Called by Logic.
     * Iterates over framers vectors and clears vector.
     */
    void NoMove(); //removes highlight in case of no movement

    /**
     * @brief promptShow. Shows Prompt for promoting Pawn.
     *
     * Called by Logic and recieves Row signal.
     * Uses Row coordinate to determine whether to display prompt for White or Black promotion.
     * @param x. Row of pawn. Either 0 or 7 depending on black or white.
     */
    void promptShow(int x);

    /**
      * @brief Promote Changes Pawn to Queen, Bishop, Knight or Rook.
      *
      * Called by Logic and receives parameters as signals.
      * Hides the promotion prompt afterwards.
      * @param x. Row of Pawn to promote. Uses Row to determine if black or white.
      * @param y. Column of Pawn to promote.
      * @param type. Type of piece to promote to as integer with 4 = Queen, 3=Rook, 2=Knight and 1=Bishop.
      */
     void Promote(int x, int y, int type);

     /**
      * @brief gamePrompts. Changes the gameplay display prompt to showcase whose turn it is
      * or if king is in Check (uses checkedKing)
      * or Checkmate or Draw.
      * Called by logic when turn changes.
      *
      * @param turn. 0=Black's turn, 1=White's turn
      */
     void gamePrompts(int turn); //miscellanous prompts during gameplay like Check, Checkmate, Black Turn, White turn....

     /**
      * @brief checkedPrompt, sets checkKing to true if King is in check.
      */
     void checkedPrompt();
    void matePrompt(int type, int turn);

     /**
     * @brief reSetted. Resets the Board upon disconnection and reconnection.
     */
    //void reSetted();



public: signals:
    /**
      * @brief Buttonpos. sends position of clicked piece on the chessboard ui to Logic.
      *
      * @param x. Row of clicked piece.
      * @param y. Column of clicked piece.
      */
     void Buttonpos(int x, int y); //signal of clicked positions.

     /**
      * @brief mustPromote sends type of piece that player clicked on the promotion prompt to Logic
      *
      * @param type. Type of piece to promote to as integer with 4 = Queen, 3=Rook, 2=Knight and 1=Bishop.
      */
     void mustPromote(int type); //signal of piece that Pawn promotes to.


private slots:
     /**
      * @brief Buttons of the Promotion prompt. Send mustPromote signal.
      */
     void on_fb_WBurg_clicked();
     void on_fb_WPope_clicked();
     void on_fb_WKrieg_clicked();
     void on_fb_WBae_clicked();
     void on_fb_BBae_clicked();
     void on_fb_BKrieg_clicked();
     void on_fb_BPope_clicked();
     void on_fb_BBurg_clicked();



};
#endif // BOARD_H
