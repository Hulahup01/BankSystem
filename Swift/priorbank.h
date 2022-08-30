#ifndef PRIORBANK_H
#define PRIORBANK_H

#include "bank_class.h"

class PriorBank : public Bank_class {

public:
    PriorBank(const double percent_in, const double percent_out);
    void transfer(QString destination, double value);
    void AddClient(const Client_class obj);

private:
    double percent_in;
    double percent_out;
};

class AlphaBank : public Bank_class {

public:
    AlphaBank(const double percent_in, const double percent_out);
    void transfer(QString destination, double value);
    void AddClient(const Client_class obj);

private:
    double percent_in;
    double percent_out;
};

class BelarusBank : public Bank_class {

public:
    BelarusBank(const double percent_in, const double percent_out);
    void transfer(QString destination, double value);
    void AddClient(const Client_class obj);

private:
    double percent_in;
    double percent_out;
};
#endif // PRIORBANK_H
