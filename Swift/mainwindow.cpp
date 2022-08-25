#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));

    trans_card_window = new Transfer_card();
    //connect(trans_card_window, &Transfer_card::back_to_mainwindow, this, &MainWindow::show);
    priorbank = new PriorBank(2.5);
    priorbank->AddClient(Client_class("Tatarinov", "Slava", "Vladimirovich", "Minsk", "Hikalo", 9, 50000));
    priorbank->AddClient(Client_class("Tatarinov", "Ilya", "Vladimirovich", "Mogilev", "Kuleshova", 24, 9));
    priorbank->AddClient(Client_class("Tatarinov", "Vladimir", "Sergeevich", "Mogilev", "Kuleshova", 24, 31500));
}

MainWindow::~MainWindow(){
    delete ui;  
}

void MainWindow::on_pushButton_clicked()
{
    if(!(select_bank() && select_client() && select_bank() && select_client()))
        qDebug() << "Error!";
    else {
        qDebug() << "Error!";
    }

}

bool MainWindow::select_bank()
{
    Transfer_bank_dialog* dialog = new Transfer_bank_dialog;
    dialog->show();
    dialog->activateWindow();

    if (dialog->exec() == QDialog::Accepted)
        return true;
    else
        return false;
}

bool MainWindow::select_client()
{
    Transfer_client_dialog* dialog = new Transfer_client_dialog;
    dialog->show();
    dialog->activateWindow();

    if (dialog->exec() == QDialog::Accepted)
        return true;
    else
        return false;
}

void MainWindow::on_pushButton_2_clicked()
{
    trans_card_window->set_priorbank(priorbank);
    trans_card_window->show();
}


void MainWindow::on_pushButton_3_clicked()
{
     for(auto i : priorbank->get_clients()){
         qDebug() << i.credit_card().get_card_numb();
     }

     for(auto i : priorbank->get_clients()){
         qDebug() << i.credit_card().get_date();
     }
}


void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_pushButton_5_clicked()
{

}

