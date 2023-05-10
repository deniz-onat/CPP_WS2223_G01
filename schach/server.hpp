/*#ifndef SERVER_HPP
#define SERVER_HPP
#include<QObject>
#include<QDialog>
#include<QTcpServer>
#include<QWidget>


class Server : public QDialog
{
  Q_OBJECT
public:
    explicit Server(QWidget *parent = nullptr);

private slots:
    void sendZug();
    void sendGameStart();
    void sendResponse;

private:

    QTcpServer *tcpServer = nullptr;
};

#endif // SERVER_HPP*/
