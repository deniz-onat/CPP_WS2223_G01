#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);

    //for connection in main function
    QPushButton* startBut;
    QPushButton* endBut;
    QPushButton* conBut;
    QPushButton* disCon;


    bool serving = false;
    //bool clienting = false;
    ~Interface();

public slots:
    void setServer();
    void setClient();
    void switchButt();

public: signals:
    void _Adrr(QString x);
    void _Port(QString x);

private slots:
    void on_connButt_clicked();

    void on_Start_clicked();

    void on_DiscButt_clicked();


    void on_Stop_clicked();

private:
    Ui::Interface *ui;
};

#endif // INTERFACE_H
