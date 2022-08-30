#ifndef CLIENT_CLASS_H
#define CLIENT_CLASS_H

#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "string.h"
#include "credit_card_class.h"

class Client_class{
private:
    std::string Last_name;
    std::string First_name;
    std::string Second_name;
    std::string City;
    std::string Street;
    int House;
    double Money;
    int Flat; // optional, not necessarily
    Credit_card_class credit;



public:
    Client_class(std::string Last_name, std::string First_name, std::string Second_name,
                 std::string City, std::string Street, int House, double Money, int Flat = 0);

    double get_Money() const;
    void set_Money(const double money);
    Credit_card_class credit_card();

};

class Add_Client_Dialog : public QDialog {
    Q_OBJECT

private:
    QLineEdit* Last_name_line;
    QLineEdit* First_name_line;
    QLineEdit* Second_name_line;
    QLineEdit* City_line;
    QLineEdit* Street_line;
    QLineEdit* House_line;
    QLineEdit* Flat_line;
    QLineEdit* Money_line;
    QLineEdit* Pin_code_line;

    QRegularExpressionValidator* Last_name_check;
    QRegularExpressionValidator* First_name_check;
    QRegularExpressionValidator* Second_name_check;
    QRegularExpressionValidator* City_check;
    QRegularExpressionValidator* Street_check;
    QRegularExpressionValidator* House_check;
    QRegularExpressionValidator* Flat_check;
    QRegularExpressionValidator* Money_check;
    QRegularExpressionValidator* Pin_code_check;

public:
    Add_Client_Dialog(QWidget* parent = nullptr);

    void set_validation();


    QString get_Last_name() const;
    QString get_First_name() const;
    QString get_Second_name() const;
    QString get_City() const;
    QString get_Street() const;
    QString get_House() const;
    QString get_Flat() const;
    QString get_Money() const;
    QString get_Pin_code() const;

};


#endif // CLIENT_CLASS_H
