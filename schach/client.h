#ifndef CLIENT_H
#define CLIENT_H
#include<QtGlobal>
#include<QtNetwork/QTcpSocket>
#include<QDataStream>
#include<QObject>

/**
 * @brief The Client class
 */
class Client : public QObject{
    Q_OBJECT
public:
    /**
     * @brief Client
     * Creates a Client object
     * @param parent
     */
    Client(QObject *parent = nullptr);
    /**
     * @brief _InOutStream
     * QDataStream object to read the incoming streams and
     * write in the outgoing ones
     */
    QDataStream _InOutStream;

public slots:
    /**
     * @brief connectToServer
     * creates a socket and establishes a connection to the given server and port
     */
    void connectToServer();
    /**
     * @brief enableConnection
     * sets up _InOutStream
     */
    void enableConnection();

    /**
     * @brief disconnectFromServer
     * terminates the connection and and calls closeConnection
     */
    void disconnectFromServer();
    /**
     * @brief disconnected
     * deletes _InOutStream and emits guiCloseNotification
     */
    void disconnected();
    /**
     * @brief closeConnection
     * sets _InOutStream to nullptr
     */
    void closeConnection();
    /**
     * @brief socketError
     * if a socket error occurs deletes _InOutStream and closes GUI
     */
    void socketError();



    /**
     * @brief setHostAddres
     * sets the _hostAddres
     * @param addres hosttt addres
     */
    void setHostAddres(QString addres);
    /**
     * @brief setPort
     * sets the _port
     * @param port port number
     */
    void setPort(QString port);


    /**
     * @brief recieveSignal
     * Reads from _InOutStream and iinterprets the signal
     */
    void recieveSignal();
    /**
     * @brief sendSignal
     * Sends the signal from logic to server
     * @param cmd type of command being sent
     * @param startRow starting row
     * @param startColumn starting coulumn
     * @param targetRow target Row
     * @param targetColumn target coulumn
     * @param promotionType if there is a promotion and its type
     * @param concequense results of the move sent to server
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
     * @brief triggerMove
     * sends the recieved move to logic
     * @param fromX starting coulumn
     * @param fromY starting row
     * @param toX target coulumn
     * @param toY target Row
     * @param type if there is a promotion and its type
     * @param concequence results of the move sent to server
     */
    void triggerMove(int fromX,int fromY, int toX, int toY, int type, int consequence);
    /**
     * @brief turnFinished
     * sends to logic when the server recieves the ok signal from server
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
    void launchGui();
    void colorSelection(int color);
    void getPromotion(int x,int y, int type);
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

    /**
     * @brief _port port number
     */
    quint16 _port;
    /**
     * @brief _hostAddres host ip addres
     */
    QString _hostAddres;
};

#endif // CLIENT_H
