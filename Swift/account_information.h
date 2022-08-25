#ifndef ACCOUNT_INFORMATION_H
#define ACCOUNT_INFORMATION_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class Account_information;
}

class Account_information : public QDialog
{
    Q_OBJECT

public:
    explicit Account_information(QWidget *parent = nullptr);
    ~Account_information();

    void show_input_page();
    void hide_input_page();
    void show_info_page();
    void hide_info_page();

private slots:

    void on_lineEdit_cardNumber_textChanged(const QString &arg1);

    void on_pushButton_SignIn_clicked();

    void on_pushButton_Close_clicked();

    void on_pushButton_SignOut_clicked();

    void on_pushButton_Refresh_clicked();

signals:

    void signal_CheckData_Account_Information(QString, QString, QString, short int, short int);

    void signal_SignOut_Account_Information();

    void signal_RefreshMoney_Account_Information();

public slots:

    void slot_Fail_Incorrect_Data_Account_Information();

    void slot_Sending_Information_Account_Information(QString,QString,QString,QString,QString,int,int,double);

    void slot_Send_Money_Status_Account_Information(double);


private:
    Ui::Account_information *ui;
};

#endif // ACCOUNT_INFORMATION_H
