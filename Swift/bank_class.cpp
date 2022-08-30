#include "bank_class.h"

Bank_class::Bank_class(const double percent_in, const double percent_out)
    : percent_in(percent_in), percent_out(percent_out), bank_status(0)
{

}

double Bank_class::get_money_status() const{
    return this->bank_status;
}

double Bank_class::get_percent_in() const
{
    return this->percent_in;
}

void Bank_class::send_to_bank(double value)
{
    this->bank_status += value;
}

double Bank_class::get_percent_out() const
{
    return this->percent_out;
}

std::vector<Client_class>& Bank_class::get_clients()
{
    return this->clients;
}

void Bank_class::transfer(QString destination, double value) {

    Q_UNUSED(destination);
    Q_UNUSED(value);
}


Transfer_bank_dialog::Transfer_bank_dialog(QWidget *parent)
    : QDialog(parent, Qt::Window | Qt::Tool){

   setWindowTitle("Transfer");
   setModal(true);


    QStringList source_list;
    source_list.push_back("PriorBank");
    source_list.push_back("AlfaBank");
    source_list.push_back("BelarusBank");

    bank = new QComboBox;
    bank->addItems(source_list);

    QLabel* bank_label = new QLabel("Select sending bank: ");
    QPushButton* Ok = new QPushButton("Next");

    QGridLayout* lay = new QGridLayout;
    lay->addWidget(bank_label, 0, 0);
    lay->addWidget(bank, 0, 1);
    lay->addWidget(Ok, 1, 1);

    setLayout(lay);

    connect(Ok, SIGNAL(clicked()), this, SLOT(accept()));

}

QString Transfer_bank_dialog::get_bank_name() const{
    return bank->currentText();
}




Transfer_client_dialog::Transfer_client_dialog(QWidget *parent)
{
    setWindowTitle("Transfer");
    setModal(true);


     QStringList source_list;
     source_list.push_back("PriorBank");
     source_list.push_back("AlfaBank");
     source_list.push_back("BelarusBank");

     client = new QComboBox;
     client->addItems(source_list);

     QLabel* client_label = new QLabel("Select sending client: ");
     QPushButton* Ok = new QPushButton("Next");

     QGridLayout* lay = new QGridLayout;
     lay->addWidget(client_label, 0, 0);
     lay->addWidget(client, 0, 1);
     lay->addWidget(Ok, 1, 1);

     setLayout(lay);

     connect(Ok, SIGNAL(clicked()), this, SLOT(accept()));
}
