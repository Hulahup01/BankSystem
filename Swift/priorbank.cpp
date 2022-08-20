#include "priorbank.h"

PriorBank::PriorBank(const double percent) : Bank_class(percent){

  }

void PriorBank::transfer(QString destination, double value)
{

}

void PriorBank::AddClient(const Client_class obj)
{
    this->clients.push_back(obj);
}
