#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include "credit_card_class.h"
#include "client_class.h"
#include "bank_class.h"
#include "priorbank.h"
#include "transfer_card.h"
#include "account_information.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool select_bank();
    bool select_client();

    void create_banks();

    void create_main_ui();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_Dialog_AccountInformation_clicked();

public slots:
    void slot_CheckData_Account_Information(QString, QString, QString, short int, short int);

    void slot_SignOut_Account_Information();

    void slot_RefreshMoney_Account_Information(QString, QString, QString, short int, short int);

signals:

    void signal_Sending_Information_Account_Information(QString,QString,QString,QString,QString,int,int,double);

    void signal_Fail_Incorrect_Data_Account_Information();

    void signal_Send_Money_Status_Account_Information(double);

private:
    Ui::MainWindow *ui;

    Transfer_card* trans_card_window;

    Account_information* account_information_window;

    PriorBank* priorbank;
    AlphaBank* alphabank;
    BelarusBank* belarusbank;
};
#endif // MAINWINDOW_H
