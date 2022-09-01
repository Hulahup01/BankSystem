#include "mainwindow.h"
#include "ui_mainwindow.h"


    MainWindow::MainWindow(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));

    setFixedSize(400,150);
    setWindowTitle("Swift");
    setWindowIcon(QIcon("../Swift/icon_logo.png"));


    account_information_window = new Account_information();
    connect(account_information_window,&Account_information::signal_CheckData_Account_Information,this,&MainWindow::slot_CheckData_Account_Information);
    connect(account_information_window,&Account_information::signal_SignOut_Account_Information,this,&MainWindow::slot_SignOut_Account_Information);
    connect(account_information_window,&Account_information::signal_RefreshMoney_Account_Information,this,&MainWindow::slot_RefreshMoney_Account_Information);
    connect(this,&MainWindow::signal_Fail_Incorrect_Data_Account_Information,account_information_window,&Account_information::slot_Fail_Incorrect_Data_Account_Information);
    connect(this,&MainWindow::signal_Sending_Information_Account_Information,account_information_window,&Account_information::slot_Sending_Information_Account_Information);
    connect(this,&MainWindow::signal_Send_Money_Status_Account_Information,account_information_window,&Account_information::slot_Send_Money_Status_Account_Information);


    trans_card_window = new Transfer_card();

    create_main_ui();
    create_banks();
}

MainWindow::~MainWindow(){
    delete ui;  
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

void MainWindow::create_banks()
{
    priorbank = new PriorBank(1.5, 2.5);
    priorbank->AddClient(Client_class("Tatarinov", "Slava", "Vladimirovich", "Minsk", "Hikalo", 9, 50000));
    priorbank->AddClient(Client_class("Tatarinov", "Ilya", "Vladimirovich", "Mogilev", "Kuleshova", 24, 40000));
    priorbank->AddClient(Client_class("Tatarinov", "Vladimir", "Sergeevich", "Mogilev", "Kuleshova", 24, 31500));

    alphabank = new AlphaBank(2, 3);
    alphabank->AddClient(Client_class("Bobko", "Ilya", "Vitalievich", "Minsk", "Hikalo", 9, 20000));
    alphabank->AddClient(Client_class("Bobko", "Artem", "Sergeevich", "Minsk", "Kuleshova", 24, 10000));
    alphabank->AddClient(Client_class("Bobko", "Anton", "Stepanovich", "Minsk", "Kuleshova", 24, 850));

    belarusbank = new BelarusBank(1, 2);
    belarusbank->AddClient(Client_class("Senchenko", "Nastya", "Mikhailovna", "Minsk", "Hikalo", 9, 920000));
    belarusbank->AddClient(Client_class("Senchenko", "Rita", "Aleksandrovna", "Minsk", "Kuleshova", 24, 80000));
    belarusbank->AddClient(Client_class("Senchenko", "Liza", "Pavlovna", "Minsk", "Kuleshova", 24, 3000));
}

void MainWindow::create_main_ui()
{
    ui->pushButton_2->setStyleSheet("color: black; background-color: #20880d; border-radius: 7px; max-width: 6em; max-height: 2em; font: 15px; padding: 0px");
    ui->pushButton_3->setStyleSheet("color: black; background-color: #818eff; border-radius: 7px; max-width: 6em; max-height: 2em; font: 15px; padding: 0px");
    ui->pushButton_Dialog_AccountInformation->setStyleSheet("color: black; background-color: #cf8a00; border-radius: 7px; max-width: 6em; max-height: 2em; font: 15px; padding: 0px");
    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    ui->pushButton_3->setCursor(Qt::PointingHandCursor);
    ui->pushButton_Dialog_AccountInformation->setCursor(Qt::PointingHandCursor);

    QLabel* logo = new QLabel("");
    logo->setScaledContents(true);

    QPixmap pix_1("../Swift/logo.png");
    logo->setPixmap(pix_1);
    logo->setFixedSize(100, 40);



    QGridLayout* lay = new QGridLayout();
    lay->addWidget(logo, 0, 0);
    lay->addWidget(ui->pushButton_2, 1, 0);
    lay->addWidget(ui->pushButton_3, 1, 1);
    lay->addWidget(ui->pushButton_Dialog_AccountInformation, 1, 2);

    QWidget* central = new QWidget;
    central->setLayout(lay);
    setCentralWidget(central);



}

void MainWindow::on_pushButton_2_clicked()
{
    trans_card_window->set_banks(priorbank, alphabank, belarusbank);
    trans_card_window->create_step_1_window();
    trans_card_window->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "priorbank";
    qDebug() << priorbank->get_money_status();
     for(auto i : priorbank->get_clients()){
         qDebug() << i.credit_card().get_card_numb();
         qDebug() << i.get_Money();
         qDebug() << i.credit_card().get_date();
         qDebug() << i.credit_card().get_cvv_code();
         qDebug() << i.credit_card().get_pin_code();
         qDebug() << "*******************";
     }

     qDebug() << "alphabank";
     qDebug() << alphabank->get_money_status();
      for(auto i : alphabank->get_clients()){
          qDebug() << i.credit_card().get_card_numb();
          qDebug() << i.get_Money();
          qDebug() << i.credit_card().get_date();
          qDebug() << i.credit_card().get_cvv_code();
          qDebug() << i.credit_card().get_pin_code();
          qDebug() << "*******************";
      }

      qDebug() << "belarusbank";
      qDebug() << belarusbank->get_money_status();
       for(auto i : belarusbank->get_clients()){
           qDebug() << i.credit_card().get_card_numb();
           qDebug() << i.get_Money();
           qDebug() << i.credit_card().get_date();
           qDebug() << i.credit_card().get_cvv_code();
           qDebug() << i.credit_card().get_pin_code();
           qDebug() << "*******************";
       }
}

void MainWindow::on_pushButton_Dialog_AccountInformation_clicked()
{
    account_information_window->exec();
}

void MainWindow::slot_CheckData_Account_Information(QString bankName, QString cardNumber, QString pinCode, short int month, short int year)
{
    bool dataIsCorrect = false;
    QString lastName;
    QString firstName;
    QString secondName;
    QString city;
    QString street;
    int house=0;
    int flat=0;
    double money=0;
    std::vector<Client_class> clients;

    cardNumber.replace( " ", "" );

    if(bankName == "Priorbank")
    {
        clients = priorbank->get_clients();
    }
    if(bankName == "Belarusbank")
    {
        clients = belarusbank->get_clients();
    }
    if(bankName == "Alfabank")
    {
        clients = alphabank->get_clients();
    }

    for(auto i : clients)
    {
        if(i.credit_card().get_card_numb() == cardNumber &&
           i.credit_card().get_pin_code() == pinCode &&
           i.credit_card().get_date() == (QString::number(month)+QString::number(year)))
        {
            dataIsCorrect = true;
            lastName = QString::fromStdString(i.Last_name);
            firstName = QString::fromStdString(i.First_name);
            secondName = QString::fromStdString(i.Second_name);
            city = QString::fromStdString(i.City);
            street = QString::fromStdString(i.Street);
            house = i.House;
            flat = i.Flat;
            money = i.Money;
            break;
        }

    }


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

void MainWindow::slot_RefreshMoney_Account_Information(QString bankName, QString cardNumber, QString pinCode, short int month, short int year)
{ 
    std::vector<Client_class> clients;
    double currentMoney=-1;

    cardNumber.replace( " ", "" );

    if(bankName == "Priorbank")
    {
        clients = priorbank->get_clients();
    }
    if(bankName == "Belarusbank")
    {
        clients = belarusbank->get_clients();
    }
    if(bankName == "Alfabank")
    {
        clients = alphabank->get_clients();
    }

    for(auto i : clients)
    {
        if(i.credit_card().get_card_numb() == cardNumber &&
           i.credit_card().get_pin_code() == pinCode &&
           i.credit_card().get_date() == (QString::number(month)+QString::number(year)))
        {
            currentMoney = i.Money;
            break;
        }
    }

    emit signal_Send_Money_Status_Account_Information(currentMoney);
}
