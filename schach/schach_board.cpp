#include "schach_board.h"
#include "ui_schach_board.h"
#include <QPainter>
#include <QTransform>

Board::Board(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);

    //saves the QPushbuttons and QLabels to an array so that we can iterate over them.
    button[0][0] = std::pair<QPushButton*, QLabel*>(ui->fb_0,ui->P_0);
    button[0][1] = std::pair<QPushButton*, QLabel*>(ui->fb_1,ui->P_1);
    button[0][2] = std::pair<QPushButton*, QLabel*>(ui->fb_2,ui->P_2);
    button[0][3] = std::pair<QPushButton*, QLabel*>(ui->fb_3,ui->P_3);
    button[0][4] = std::pair<QPushButton*, QLabel*>(ui->fb_4,ui->P_4);
    button[0][5] = std::pair<QPushButton*, QLabel*>(ui->fb_5,ui->P_5);
    button[0][6] = std::pair<QPushButton*, QLabel*>(ui->fb_6,ui->P_6);
    button[0][7] = std::pair<QPushButton*, QLabel*>(ui->fb_7,ui->P_7);
    button[1][0] = std::pair<QPushButton*, QLabel*>(ui->fb_8,ui->P_8);
    button[1][1] = std::pair<QPushButton*, QLabel*>(ui->fb_9,ui->P_9);
    button[1][2] = std::pair<QPushButton*, QLabel*>(ui->fb_10,ui->P_10);
    button[1][3] = std::pair<QPushButton*, QLabel*>(ui->fb_11,ui->P_11);
    button[1][4] = std::pair<QPushButton*, QLabel*>(ui->fb_12,ui->P_12);
    button[1][5] = std::pair<QPushButton*, QLabel*>(ui->fb_13,ui->P_13);
    button[1][6] = std::pair<QPushButton*, QLabel*>(ui->fb_14,ui->P_14);
    button[1][7] = std::pair<QPushButton*, QLabel*>(ui->fb_15,ui->P_15);
    button[2][0] = std::pair<QPushButton*, QLabel*>(ui->fb_16,ui->P_16);
    button[2][1] = std::pair<QPushButton*, QLabel*>(ui->fb_17,ui->P_17);
    button[2][2] = std::pair<QPushButton*, QLabel*>(ui->fb_18,ui->P_18);
    button[2][3] = std::pair<QPushButton*, QLabel*>(ui->fb_19,ui->P_19);
    button[2][4] = std::pair<QPushButton*, QLabel*>(ui->fb_20,ui->P_20);
    button[2][5] = std::pair<QPushButton*, QLabel*>(ui->fb_21,ui->P_21);
    button[2][6] = std::pair<QPushButton*, QLabel*>(ui->fb_22,ui->P_22);
    button[2][7] = std::pair<QPushButton*, QLabel*>(ui->fb_23,ui->P_23);
    button[3][0] = std::pair<QPushButton*, QLabel*>(ui->fb_24,ui->P_24);
    button[3][1] = std::pair<QPushButton*, QLabel*>(ui->fb_25,ui->P_25);
    button[3][2] = std::pair<QPushButton*, QLabel*>(ui->fb_26,ui->P_26);
    button[3][3] = std::pair<QPushButton*, QLabel*>(ui->fb_27,ui->P_27);
    button[3][4] = std::pair<QPushButton*, QLabel*>(ui->fb_28,ui->P_28);
    button[3][5] = std::pair<QPushButton*, QLabel*>(ui->fb_29,ui->P_29);
    button[3][6] = std::pair<QPushButton*, QLabel*>(ui->fb_30,ui->P_30);
    button[3][7] = std::pair<QPushButton*, QLabel*>(ui->fb_31,ui->P_31);
    button[4][0] = std::pair<QPushButton*, QLabel*>(ui->fb_32,ui->P_32);
    button[4][1] = std::pair<QPushButton*, QLabel*>(ui->fb_33,ui->P_33);
    button[4][2] = std::pair<QPushButton*, QLabel*>(ui->fb_34,ui->P_34);
    button[4][3] = std::pair<QPushButton*, QLabel*>(ui->fb_35,ui->P_35);
    button[4][4] = std::pair<QPushButton*, QLabel*>(ui->fb_36,ui->P_36);
    button[4][5] = std::pair<QPushButton*, QLabel*>(ui->fb_37,ui->P_37);
    button[4][6] = std::pair<QPushButton*, QLabel*>(ui->fb_38,ui->P_38);
    button[4][7] = std::pair<QPushButton*, QLabel*>(ui->fb_39,ui->P_39);
    button[5][0] = std::pair<QPushButton*, QLabel*>(ui->fb_40,ui->P_40);
    button[5][1] = std::pair<QPushButton*, QLabel*>(ui->fb_41,ui->P_41);
    button[5][2] = std::pair<QPushButton*, QLabel*>(ui->fb_42,ui->P_42);
    button[5][3] = std::pair<QPushButton*, QLabel*>(ui->fb_43,ui->P_43);
    button[5][4] = std::pair<QPushButton*, QLabel*>(ui->fb_44,ui->P_44);
    button[5][5] = std::pair<QPushButton*, QLabel*>(ui->fb_45,ui->P_45);
    button[5][6] = std::pair<QPushButton*, QLabel*>(ui->fb_46,ui->P_46);
    button[5][7] = std::pair<QPushButton*, QLabel*>(ui->fb_47,ui->P_47);
    button[6][0] = std::pair<QPushButton*, QLabel*>(ui->fb_48,ui->P_48);
    button[6][1] = std::pair<QPushButton*, QLabel*>(ui->fb_49,ui->P_49);
    button[6][2] = std::pair<QPushButton*, QLabel*>(ui->fb_50,ui->P_50);
    button[6][3] = std::pair<QPushButton*, QLabel*>(ui->fb_51,ui->P_51);
    button[6][4] = std::pair<QPushButton*, QLabel*>(ui->fb_52,ui->P_52);
    button[6][5] = std::pair<QPushButton*, QLabel*>(ui->fb_53,ui->P_53);
    button[6][6] = std::pair<QPushButton*, QLabel*>(ui->fb_54,ui->P_54);
    button[6][7] = std::pair<QPushButton*, QLabel*>(ui->fb_55,ui->P_55);
    button[7][0] = std::pair<QPushButton*, QLabel*>(ui->fb_56,ui->P_56);
    button[7][1] = std::pair<QPushButton*, QLabel*>(ui->fb_57,ui->P_57);
    button[7][2] = std::pair<QPushButton*, QLabel*>(ui->fb_58,ui->P_58);
    button[7][3] = std::pair<QPushButton*, QLabel*>(ui->fb_59,ui->P_59);
    button[7][4] = std::pair<QPushButton*, QLabel*>(ui->fb_60,ui->P_60);
    button[7][5] = std::pair<QPushButton*, QLabel*>(ui->fb_61,ui->P_61);
    button[7][6] = std::pair<QPushButton*, QLabel*>(ui->fb_62,ui->P_62);
    button[7][7] = std::pair<QPushButton*, QLabel*>(ui->fb_63,ui->P_63);

    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; j++){
            button[i][j].second->setPixmap(Nul0);
        } }

}

Board::~Board()
{
    delete ui;
}

//Flips the Board depending on if Client or Server is Black. Gets type from Client or Server.
void Board::startBoard(int type){
    if(type == 1) {
        ui->Display->setCurrentIndex(1);
        ui->Rows->setCurrentIndex(1);
        for (int i = 0; i < 4; ++i) {
            for(int j = 0; j < 8; j++){
                //QString tmp = button[i][j].first->parentWidget()->styleSheet();
                //QPixmap img = *(button[i][j].second->pixmap());
                std::pair<QPushButton*, QLabel*> cmp = button[i][j];
                //button[i][j].second->setPixmap(*(button[7-i][j].second->pixmap()));
                //button[7-i][j].second->setPixmap(img);
                //button[i][j].first->parentWidget()->setStyleSheet(button[7-i][j].first->parentWidget()->styleSheet());
                //button[7-i][j].first->parentWidget()->setStyleSheet(tmp);
                button[i][j]=button[7-i][j];
                button[7-i][j] = cmp;
            }}}
      else{
        ui->Display->setCurrentIndex(0);
        ui->Rows->setCurrentIndex(0);
        }

    //Promotion prompts for gameplay. Hidden at the start.
    ui->promPrompt->hide();
    ui->promPrompt_2->hide();

    //Rematch Button. Hidden at the start.
    ui->reMatch->hide();

    //Colouring the fields
    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; j++){
            button[i][j].first->setStyleSheet(invisButt);
            if((i+j)%2==0){
                button[i][j].first->parentWidget()->setStyleSheet(hellsetting);
            }else{
                button[i][j].first->parentWidget()->setStyleSheet(darksetting);
            }
        } }

    //Set the Pieces
    button[0][0].second->setPixmap(WRook); //Rooks
    button[0][7].second->setPixmap(WRook);
    button[7][0].second->setPixmap(BRook);
    button[7][7].second->setPixmap(BRook);
    button[0][1].second->setPixmap(WKnight);//Knights
    button[0][6].second->setPixmap(WKnight);
    button[7][1].second->setPixmap(BKnight);
    button[7][6].second->setPixmap(BKnight);
    button[0][2].second->setPixmap(WBishop); //Bishops
    button[0][5].second->setPixmap(WBishop);
    button[7][2].second->setPixmap(BBishop);
    button[7][5].second->setPixmap(BBishop);
    button[0][3].second->setPixmap(WQueen); //Queens
    button[7][3].second->setPixmap(BQueen);
    button[0][4].second->setPixmap(WKing); //Kings
    button[7][4].second->setPixmap(BKing);
    for (int j = 0; j < 8; j++) { //Pawns
        button[1][j].second->setPixmap(WPawn);
        button[6][j].second->setPixmap(BPawn);
    }

    //Connect the buttons
    for (int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; j++){
            connect(button[i][j].first,
                    &QPushButton::clicked,
                    this,
                    [=](){
                emit Buttonpos(i,j);
                qDebug()<<"Button ["<<i <<"]["<<j <<"] is working\n";});}
    }
    show();
}


/*Helper function that highlights a field by changing the stylesheet of the frame.
 *  Also removes highlight if Field is already highlighted. */
void Board::lightUp(int x, int y){
    QPushButton* tmp = button[x][y].first;
    if(!m_highlighted){
        if((x+y)%2 == 0){
            tmp->parentWidget()->setStyleSheet(highLit);
        }else{
            tmp->parentWidget()->setStyleSheet(darkLit);
        }}
    else{
        if((x+y)%2 == 0){
            tmp->parentWidget()->setStyleSheet(hellsetting);
        }else{
            tmp->parentWidget()->setStyleSheet(darksetting);
        }
    }

}


/*Highlight Slot that receives a selected position from Logic
 *              and a vector of pairs that are the positions of possible movements.
    Calls the lightUp function to highlight each position while saving each position in a new vector framers.*/
void Board::highLite(std::vector<std::pair<int,int>> moves, int fromX, int fromY){
    std::for_each(
                moves.begin(),
                moves.end(),
                [&](std::pair<int, int> a){
        lightUp(a.first, a.second);
        framers.push_back(a);
    } );

    lightUp(fromX, fromY);
    framers.push_back(std::pair<int,int>(fromX,fromY));
    m_highlighted = true;
}


/**Slot that moves pieces by changing the QLabels. Also removes highlighting and empties framers afterwards.
Also acts as a Capture method since what it does is:
                           1) change the Label of toX, toY position to the Label of the First.
                           2) Change the Label of the fromX, fromY position to an empty png.**/
void Board::moveLabel(int fromX, int fromY, int toX, int toY){
    button[toX][toY].second->setPixmap(*(button[fromX][fromY].second->pixmap()));
    button[fromX][fromY].second->setPixmap(Nul0);
//    if(_enpassant == 1){
//        if(toX-fromX == 1)
//            button[toX-1][toY].second->setPixmap(Nul0);
//        else
//            button[toX+1][toY].second->setPixmap(Nul0);
//    }
    if(m_highlighted){
        std::for_each(
                    framers.begin(),
                    framers.end(),
                    [&](std::pair<int, int> a){
            lightUp(a.first, a.second);
            framers.clear();}
        );
        m_highlighted = false;}
}

/*Slot that removes highlighting using lightUp in case there's no movement.
    And also empties the framers vector.*/
void Board::NoMove(){
    if(m_highlighted){
        std::for_each(
                    framers.begin(),
                    framers.end(),
                    [&](std::pair<int, int> a){
            lightUp(a.first, a.second);
            framers.clear();}
        );
        m_highlighted = false;}
}


/*Prompt to show pieces that can be promoted to.
Receives position x from Logic and showcases respective prompt (White or Black promotion).*/
void Board::promptShow(int x){
    if(x == 0){
        ui->ChessBoard->setEnabled(false);
        ui->promPrompt_2->show();
        ui->promPrompt_2->setEnabled(true);
        qDebug()<<"This is"<<x;
    }else {
        ui->ChessBoard->setEnabled(false);
        ui->promPrompt->show();
        ui->promPrompt->setEnabled(true);
        qDebug()<<"This is"<<x;
    }
}

//Promote Slot that gets called by Signal from Logic.
void Board::Promote(int x, int y, int type){
    qDebug()<<"Doing STUFF!!";
    qDebug()<<"The points are"<<x<<","<<y;
    ui->ChessBoard->setEnabled(true);
    if (x==0)
    {ui->promPrompt_2->hide();}else{ui->promPrompt->hide();}
    switch (type) {
    case 4:
        qDebug()<<"Case 4 is working!!!";
        if(x==0){
            button[x][y].second->setPixmap(*(ui->BBae->pixmap()));
        }else{
            button[x][y].second->setPixmap(*(ui->WBae->pixmap()));
        }
        break;
    case 3:
        qDebug()<<"Case 3 is working!!!";
        if(x==0){
            button[x][y].second->setPixmap(*(ui->BBurg->pixmap()));
        }else{
            button[x][y].second->setPixmap(*(ui->WBurg->pixmap()));
        }
        break;
    case 2:
        qDebug()<<"Case 2 is working!!!";
        if(x==0){
            button[x][y].second->setPixmap(*(ui->BKrieg->pixmap()));
        }else{
            button[x][y].second->setPixmap(*(ui->WKrieg->pixmap()));
        }
        break;
    case 1:
        qDebug()<<"Case 1 is working!!!";
        if (x==0){
            button[x][y].second->setPixmap(*(ui->BPope->pixmap()));
        }else{
            button[x][y].second->setPixmap(*(ui->WPope->pixmap()));
        }
        break;
    default:
        break;
    }
}

void Board::gamePrompts(int turn){
    if (turn == 1){
        if (checkedKing)
        {ui->Display->setCurrentIndex(4);
            checkedKing = false;}
        else
            ui->Display->setCurrentIndex(2);}
    else{
        if (checkedKing)
        {  ui->Display->setCurrentIndex(5);
            checkedKing = false;}
        else
            ui->Display->setCurrentIndex(3);}

}

void Board::checkedPrompt(){
    checkedKing = true;
}

//QPushbutton Slots for Promotion. Emits Signal to showcase the type of promotion.
void Board::on_fb_WBurg_clicked()
{
    emit mustPromote(3);
}

void Board::on_fb_WPope_clicked()
{
    emit mustPromote(1);
}

void Board::on_fb_WKrieg_clicked()
{
    emit mustPromote(2);
}

void Board::on_fb_WBae_clicked()
{
    emit mustPromote(4);
}

void Board::on_fb_BBae_clicked()
{
    emit mustPromote(4);
}

void Board::on_fb_BKrieg_clicked()
{
    emit mustPromote(2);
}

void Board::on_fb_BPope_clicked()
{
    emit mustPromote(1);
}

void Board::on_fb_BBurg_clicked()
{
    emit mustPromote(3);
}

void Board::matePrompt(int type, int turn){
    switch (type) {
    case 3:
        ui->Display->setCurrentIndex(9);
        break;
    case 2:
        ui->Display->setCurrentIndex(8);
        break;
    case 1:
        if(turn == 0)
            ui->Display->setCurrentIndex(6);
        else
            ui->Display->setCurrentIndex(7);
        break;
    default:
        break;
    }
    ui->reMatch->show();
}

