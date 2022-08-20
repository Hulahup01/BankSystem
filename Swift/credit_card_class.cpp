#include "credit_card_class.h"

Credit_card_class::Credit_card_class(std::string last_name, std::string first_name){
    generate_card_numb();
    generate_month_year();
    generate_cvv_code();
    this->owner = last_name + ' ' + first_name;
}

void Credit_card_class::generate_card_numb(){
    for(int i = 0; i < 16; i++){
//        if(i != 0 && i % 4 == 0) // spaces after each 4-th digit
//            this->card_numb += " ";
        this->card_numb += rand() % 10 + '0';
    }
}

void Credit_card_class::generate_month_year()
{
    this->month = rand() % 12 + 1;
    this->year = rand() % 5 + 23;
    qDebug() <<  month << ", " << year;
}

void Credit_card_class::generate_cvv_code(){
    for(int i = 0; i < 3; i++){
        this->cvv_code += rand() % 10 + '0';
    }
}

QString Credit_card_class::get_card_numb() const{
    return QString::fromStdString(this->card_numb);
}

QString Credit_card_class::get_cvv_code() const{
    return QString::fromStdString(this->cvv_code);
}

void Credit_card_class::set_pin_code(QString pin_code)
{
    this->pin_code = pin_code;
}
