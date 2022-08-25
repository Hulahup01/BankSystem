#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));


    account_information_window = new Account_information();
    connect(account_information_window,&Account_information::signal_CheckData_Account_Information,this,&MainWindow::slot_CheckData_Account_Information);
    connect(account_information_window,&Account_information::signal_SignOut_Account_Information,this,&MainWindow::slot_SignOut_Account_Information);
    connect(account_information_window,&Account_information::signal_RefreshMoney_Account_Information,this,&MainWindow::slot_RefreshMoney_Account_Information);
    connect(this,&MainWindow::signal_Fail_Incorrect_Data_Account_Information,account_information_window,&Account_information::slot_Fail_Incorrect_Data_Account_Information);
    connect(this,&MainWindow::signal_Sending_Information_Account_Information,account_information_window,&Account_information::slot_Sending_Information_Account_Information);
    connect(this,&MainWindow::signal_Send_Money_Status_Account_Information,account_information_window,&Account_information::slot_Send_Money_Status_Account_Information);


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


void MainWindow::on_pushButton_Dialog_AccountInformation_clicked()
{
    account_information_window->exec();
}

void MainWindow::slot_CheckData_Account_Information(QString bankName, QString cardNumber, QString pinCode, short int month, short int year)
{
    bool dataIsCorrect = true;
    //проверка данных
    // ...
    // ...


    // ======================= тест значения
    QString lastName="FAMILIA";
    QString firstName="IMYA";
    QString secondName="OTCHESTVO";
    QString city="GOROD";
    QString street="YLICA";
    int house = 1;
    int flat=0;
    double money=98.23;
    // =======================


    if(dataIsCorrect){
        emit signal_Sending_Information_Account_Information(lastName, firstName, secondName, city,  street,house, flat, money);
    }else{
        emit signal_Fail_Incorrect_Data_Account_Information();
    }


    qDebug()<<bankName;
    qDebug()<<cardNumber;
    qDebug()<<pinCode;
    qDebug()<<month;
    qDebug()<<year;
}

void MainWindow::slot_SignOut_Account_Information()
{
    account_information_window->close();
    delete account_information_window;
    account_information_window = new Account_information();
    connect(account_information_window,&Account_information::signal_CheckData_Account_Information,this,&MainWindow::slot_CheckData_Account_Information);
    connect(account_information_window,&Account_information::signal_SignOut_Account_Information,this,&MainWindow::slot_SignOut_Account_Information);
    connect(account_information_window,&Account_information::signal_RefreshMoney_Account_Information,this,&MainWindow::slot_RefreshMoney_Account_Information);
    connect(this,&MainWindow::signal_Fail_Incorrect_Data_Account_Information,account_information_window,&Account_information::slot_Fail_Incorrect_Data_Account_Information);
    connect(this,&MainWindow::signal_Sending_Information_Account_Information,account_information_window,&Account_information::slot_Sending_Information_Account_Information);
    connect(this,&MainWindow::signal_Send_Money_Status_Account_Information,account_information_window,&Account_information::slot_Send_Money_Status_Account_Information);
}

void MainWindow::slot_RefreshMoney_Account_Information()
{
    // получение текущего состояние денег
    double currentMoney = 100.15;
    // =====


    emit signal_Send_Money_Status_Account_Information(currentMoney);
}
