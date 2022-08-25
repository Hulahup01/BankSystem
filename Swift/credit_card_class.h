#ifndef CREDIT_CARD_CLASS_H
#define CREDIT_CARD_CLASS_H
#include <iostream>
#include "string.h"
#include <ctime>
#include <QDebug>

class Credit_card_class{
private:
    std::string card_numb;
    short month;
    short year;
    std::string cvv_code;
    std::string owner;
    QString pin_code;

    void generate_card_numb();
    void generate_month_year();
    void generate_cvv_code();
public:
    Credit_card_class(std::string last_name, std::string first_name);

    QString get_card_numb() const;
    QString get_cvv_code() const;
    QString get_date();
    void set_pin_code(QString pin_code);
};

#endif // CREDIT_CARD_CLASS_H
