#ifndef PRIORBANK_H
#define PRIORBANK_H

#include "bank_class.h"

class PriorBank : public Bank_class {

public:
    PriorBank(const double percent);
    void transfer(QString destination, double value);
    void AddClient(const Client_class obj);
};
#endif // PRIORBANK_H
