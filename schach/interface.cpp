#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

Interface::Interface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    //for
    startBut = ui->Start;
    endBut = ui->Stop;
    conBut = ui->connButt;
    disCon = ui->DiscButt;
    ui->connButt->hide();
    ui->Start->hide();
    ui->Stop->hide();
    //ui->Stop->setEnabled(false);
    ui->DiscButt->hide();
    ui->Addr_Port->hide();

    connect(ui->servButt, &QRadioButton::clicked, this, &Interface::setServer);
    connect(ui->clintButt, &QRadioButton::clicked, this, &Interface::setClient);
}
Interface::~Interface()
{
    delete ui;
}
void Interface::setServer(){
    serving = true;
    //clienting = false;
    ui->connButt->hide();
    ui->Start->show();
    ui->Start->setEnabled(true);
    ui->Addr_Port->hide();
    ui->connButt->hide();
    qDebug()<<"Device is set to Host.";
}
void Interface::setClient(){
    serving = false;
    //clienting = false;
    ui->Start->hide();
    ui->Addr_Port->show();
    ui->connButt->show();
    ui->connButt->setEnabled(true);
    qDebug()<<"Device is set as Client.";
}

void Interface::on_connButt_clicked()
{
    qDebug()<<"Button works";
    emit _Adrr(ui->linAdr->text());
    emit _Port(ui->linPort->text());
    ui->servButt->hide();
    ui->connButt->hide();
    ui->DiscButt->show();
    //ui->DiscButt->setEnabled(true);
}


void Interface::on_Start_clicked()
{
    qDebug()<<"Button works";
    //    emit _Adrr(ui->linAdr->text());
    //    emit _Port(ui->linPort->text());
    ui->clintButt->hide();
    ui->Start->hide();
    ui->Stop->show();
    //ui->Stop->setEnabled(true);
}


void Interface::on_DiscButt_clicked()
{
    qDebug()<<"Button works";
    ui->connButt->show();
    ui->DiscButt->hide();
    ui->servButt->show();
}




void Interface::on_Stop_clicked()
{
    ui->clintButt->show();
    ui->Start->show();
    ui->Stop->hide();
}

void Interface::switchButt(){
    if(serving){
        ui->clintButt->show();
        ui->Stop->hide();
        ui->Start->show();
    }
    else{
        ui->connButt->show();
        ui->DiscButt->hide();
        ui->servButt->show();
    }
}
