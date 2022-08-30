#include "account_information.h"
#include "ui_account_information.h"

int LenghtCardNumberAccount=0;

Account_information::Account_information(QWidget *parent) :QDialog(parent),ui(new Ui::Account_information)
{
    ui->setupUi(this);

    setWindowTitle("Swift. Account information");
    setFixedSize(575, 330);
    setWindowIcon(QIcon("../Swift/Iconelogo.png"));

    ui->label_incorrectData->hide();
    hide_info_page();

    QPixmap pix_BankLogo("../Swift/bankLogo.png");
    ui->label_bankLogo_png->setPixmap(pix_BankLogo);

    QPixmap pix_Card("../Swift/credit_card(receiver).png");
    ui->label_card_png->setPixmap(pix_Card);
    ui->label_cardInfo_png->setPixmap(pix_Card);

    QPixmap pix_Logo("../Swift/logo.png");
    ui->label_logo_png->setPixmap(pix_Logo);

    QPixmap pix_PinCode("../Swift/pin-code.png");
    ui->label_pinCode_png->setPixmap(pix_PinCode);

    QPixmap pix_RefreshIcon("../Swift/refresh.png");
    ui->pushButton_Refresh->setIcon(pix_RefreshIcon);


    ui->pushButton_SignIn->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->pushButton_SignOut->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->pushButton_Close->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->pushButton_Refresh->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->dateEdit_cardDate->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->dateEdit_cardDate_info->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

Account_information::~Account_information()
{
    delete ui;
}

void Account_information::show_input_page()
{
    ui->label_bankLogo_png->show();
    ui->comboBox_chooseBank->show();
    ui->label_card_png->show();
    ui->label_pinCode_png->show();
    ui->lineEdit_pinCode->show();
    ui->lineEdit_cardNumber->show();
    ui->date_label_1->show();
    ui->date_label_3->show();
    ui->dateEdit_cardDate->show();
    ui->pushButton_SignIn->show();
}

void Account_information::hide_input_page()
{
    ui->label_bankLogo_png->hide();
    ui->comboBox_chooseBank->hide();
    ui->label_card_png->hide();
    ui->label_pinCode_png->hide();
    ui->lineEdit_pinCode->hide();
    ui->lineEdit_cardNumber->hide();
    ui->date_label_1->hide();
    ui->date_label_3->hide();
    ui->dateEdit_cardDate->hide();
    ui->pushButton_SignIn->hide();
    ui->label_incorrectData->hide();
}

void Account_information::show_info_page()
{
    ui->label_firstName->show();
    ui->label_secondName->show();
    ui->label_lastName->show();
    ui->lineEdit_firstName->show();
    ui->lineEdit_lastName->show();
    ui->lineEdit_secondName->show();

    ui->label_city->show();
    ui->label_street->show();
    ui->label_house->show();
    ui->label_flat->show();
    ui->lineEdit_city->show();
    ui->lineEdit_street->show();
    ui->lineEdit_house->show();
    ui->lineEdit_flat->show();

    ui->label_cardInfo_png->show();
    ui->label_bankName->show();
    ui->label_money->show();
    ui->lineEdit_cardNumber_info->show();
    ui->dateEdit_cardDate_info->show();
    ui->pushButton_SignOut->show();
    ui->pushButton_Close->show();
    ui->pushButton_Refresh->show();
}

void Account_information::hide_info_page()
{
    ui->label_firstName->hide();
    ui->label_secondName->hide();
    ui->label_lastName->hide();
    ui->lineEdit_firstName->hide();
    ui->lineEdit_lastName->hide();
    ui->lineEdit_secondName->hide();

    ui->label_city->hide();
    ui->label_street->hide();
    ui->label_house->hide();
    ui->label_flat->hide();
    ui->lineEdit_city->hide();
    ui->lineEdit_street->hide();
    ui->lineEdit_house->hide();
    ui->lineEdit_flat->hide();

    ui->label_cardInfo_png->hide();
    ui->label_bankName->hide();
    ui->label_money->hide();
    ui->lineEdit_cardNumber_info->hide();
    ui->dateEdit_cardDate_info->hide();
    ui->pushButton_SignOut->hide();
    ui->pushButton_Close->hide();
    ui->pushButton_Refresh->hide();
}


void Account_information::on_lineEdit_cardNumber_textChanged(const QString &arg1)
{
    if(LenghtCardNumberAccount>arg1.length()&&(arg1.length()==5||arg1.length()==10||arg1.length()==15)){QString temp  = arg1; temp.chop(1); ui->lineEdit_cardNumber->setText(temp);}

    if(arg1.length()==4){ ui->lineEdit_cardNumber->setText(arg1+" ");}
    else if(arg1.length()==9){ ui->lineEdit_cardNumber->setText(arg1+" ");}
    else if(arg1.length()==14){ ui->lineEdit_cardNumber->setText(arg1+" ");}

    LenghtCardNumberAccount = arg1.length();
}


void Account_information::on_pushButton_SignIn_clicked()
{
    QString cardNumber = ui->lineEdit_cardNumber->text();
    QString pinCode = ui->lineEdit_pinCode->text();
    short int month = ui->dateEdit_cardDate->date().month();
    short int year = ui->dateEdit_cardDate->date().year();
    QString bankName = ui->comboBox_chooseBank->currentText();

    emit signal_CheckData_Account_Information(bankName,cardNumber,pinCode,month,year);
}


void Account_information::on_pushButton_Close_clicked()
{
    this->close();
}

void Account_information::on_pushButton_SignOut_clicked()
{
    emit signal_SignOut_Account_Information();
}

void Account_information::on_pushButton_Refresh_clicked()
{
    emit signal_RefreshMoney_Account_Information();
}

void Account_information::slot_Fail_Incorrect_Data_Account_Information()
{
    ui->label_incorrectData->show();
    ui->lineEdit_cardNumber->setText("");
    ui->lineEdit_pinCode->setText("");
}

void Account_information::slot_Sending_Information_Account_Information(QString lastName, QString firstName, QString secondName, QString city, QString street, int house, int flat, double money)
{
    ui->lineEdit_lastName->setText(lastName);
    ui->lineEdit_firstName->setText(firstName);
    ui->lineEdit_secondName->setText(secondName);

    ui->lineEdit_city->setText(city);
    ui->lineEdit_street->setText(street);
    ui->lineEdit_house->setText(QString::number(house));
    if(flat) ui->lineEdit_flat->setText(QString::number(flat));

    ui->lineEdit_cardNumber_info->setText(ui->lineEdit_cardNumber->text());
    ui->dateEdit_cardDate_info->setDate(ui->dateEdit_cardDate->date());
    ui->label_bankName->setText(ui->comboBox_chooseBank->currentText());
    ui->label_money->setText(QString::number(money)+" BYN");

    hide_input_page();
    show_info_page();
}

void Account_information::slot_Send_Money_Status_Account_Information(double money)
{
    ui->label_money->setText(QString::number(money)+" BYN");
}

