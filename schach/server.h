#ifndef SERVER_H
#define SERVER_H
#include<QTcpServer>
#include<iostream>
#include<QNetworkInterface>
#include<QtGlobal>
#include<QtNetwork/QTcpSocket>
#include<QDataStream>
#include<QObject>
/**
 * @brief The Server class
 *
 */
class Server : public QObject
{
    Q_OBJECT
public:

    /**
    * @brief Server
    * creates a Server object
    *
    * @param parent
    */
    Server(QObject *parent = nullptr);
    /**
     * @brief _InOutStream
     * QDataStream object to read the incoming streams and
     * write in the outgoing ones
     */
    QDataStream _InOutStream;
    /**
     * @brief tcpServer
     * QTcpServer pointer to host the game
     */
    QTcpServer *tcpServer;
    /**
     * @brief socket
     * QTcpSocket ppointer to handle the communication with the client
     */
    QTcpSocket *socket;
    /**
     * @brief firstoGo
     * random generated variable to determine the starting side,0=Server 1=Client
     */
    quint8 firstoGo;
    /**
     * @brief promotionType
     * Pawn promotion type according to the network protocol
     */
    quint8 promotionType;


public slots:
    /**
     * @brief initServer
     * Creates a new QTcpServer object if one doesn't exist and calls setSocket() when there is a nnew connection
     */
    void initServer();
    /**
     * @brief setSocket
     * Sets up _InOutStream and socket. Closes the tcpserver
     */
    void setSocket();

    /**
     * @brief closeConnection
     * Disconnects _InOutStream and deletes the created QTcpSocket and QTcpServer. Tells GUI to disable the board.
     */
    void closeConnection();
    /**
     * @brief socketError
     * Disconnects _InOutStream and deletes the created QTcpSocket and QTcpServer. Tells GUI to disable the board.
     */
    void socketError();


    /**
     * @brief sendStartSignal
     * Sends the starting signal  to client
     */
    void sendStartSignal();
    /**
     * @brief recieveSignal
     * Reads from _InOutStream and interprets the signal
     */
    void recieveSignal();
    /**
     * @brief sendSignal
     * Sends the signal from logic to client
     * @param cmd type of command being sent
     * @param startRow starting row
     * @param startColumn starting coulumn
     * @param targetRow target Row
     * @param targetColumn target coulumn
     * @param promotionType if there is a promotion and its type
     * @param concequense results of the move sent to client
     * @param status if the recieved move was legal
     */
    void sendSignal(quint8 cmd,quint8 startRow =  0,
                    quint8 startColumn = 0,quint8 targetRow = 0,quint8 targetColumn = 0,quint8 promotionType = 0,quint8 concequense = 0,quint8 status = 0);


signals:
    /**
     * @brief initLogic
     * starts/restarts logic
     */
    void initLogic();
    /**
     * @brief colorSelection
     * sends the color of Server to GUI
     * @param color Color
     */
    void colorSelection(int color);
    /**
     * @brief triggerMove
     * sends the recieved move to logic
     * @param fromX starting coulumn
     * @param fromY starting row
     * @param toX target coulumn
     * @param toY target Row
     * @param type if there is a promotion and its type
     * @param concequence results of the move sent to client
     */
    void triggerMove(int fromX,int fromY, int toX, int toY, int type, int concequence);
    /**
     * @brief turnFinished
     * sends to logic when the server recieves the ok signal from client
     */
    void turnFinished();
    /**
     * @brief startGui
     * sends to GUI to make the booard visible
     * @param type sets the players POV
     */
    void startGui(int type);
    /**
     * @brief startingSide tells GUI and logic who starts first
     * @param firstToGo starting side
     */
    void startingSide(int firstToGo);
    /**
     * @brief triggerPromotion
     * tells the logic to promote the pawn
     */
    void triggerPromotion();
    /**
     * @brief guiCloseNotification
     * tells GUI to turn off the board
     */
    void guiCloseNotification();

private:




};

#endif // SERVER_H
