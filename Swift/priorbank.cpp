#include "priorbank.h"

PriorBank::PriorBank(const double percent_in, const double percent_out)
    : Bank_class(percent_in, percent_out){

}

void PriorBank::transfer(QString destination, double value)
{

}

void PriorBank::AddClient(const Client_class obj)
{
    this->clients.push_back(obj);
}

AlphaBank::AlphaBank(const double percent_in, const double percent_out)
    : Bank_class(percent_in, percent_out){

}

void AlphaBank::transfer(QString destination, double value)
{

}

void AlphaBank::AddClient(const Client_class obj)
{
    this->clients.push_back(obj);
}

BelarusBank::BelarusBank(const double percent_in, const double percent_out)
    : Bank_class(percent_in, percent_out){

}

void BelarusBank::transfer(QString destination, double value)
{

}

void BelarusBank::AddClient(const Client_class obj)
{
    this->clients.push_back(obj);
}
