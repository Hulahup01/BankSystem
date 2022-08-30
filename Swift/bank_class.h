#ifndef BANK_CLASS_H
#define BANK_CLASS_H

#include "client_class.h"
#include <QComboBox>
#include <QSpinBox>


class Bank_class{
protected:
    const double percent_in;
    const double percent_out;
    double bank_status;
    std::vector<Client_class> clients;

public:
    Bank_class(const double percent_in, const double percent_out);

    double get_money_status() const;
    virtual void transfer(QString destination, double value) = 0;
    virtual double get_percent_in() const;
    virtual void send_to_bank(double value);
    double get_percent_out() const;

    std::vector<Client_class>& get_clients();
};



class Transfer_bank_dialog : public QDialog {
    Q_OBJECT

private:
    QComboBox* bank;

public:
    Transfer_bank_dialog(QWidget* parent = nullptr);
    QString get_bank_name() const;
};

class Transfer_client_dialog : public QDialog {
    Q_OBJECT

private:
    QComboBox* client;

public:
    Transfer_client_dialog(QWidget* parent = nullptr);
    QString get_client_name() const;
};


#endif // BANK_CLASS_H
