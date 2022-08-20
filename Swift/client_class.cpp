#include "client_class.h"

Client_class::Client_class(std::string Last_name, std::string First_name, std::string Second_name,
                           std::string City, std::string Street, int House, double Money, int Flat) :
    Last_name(Last_name), First_name(First_name), Second_name(Second_name), City(City), Street(Street), House(House),
    Money(Money), Flat(Flat), credit(Last_name, First_name)
{


    Add_Client_Dialog* dialog = new Add_Client_Dialog;
    dialog->show();
    dialog->activateWindow();

    if (dialog->exec() == QDialog::Accepted) {
        credit.set_pin_code(dialog->get_Pin_code());
    }
}

double Client_class::get_Money() const
{
    return Money;
}



Add_Client_Dialog::Add_Client_Dialog(QWidget* parent)
    : QDialog(parent, Qt::Window | Qt::Tool) {

    setWindowTitle("New client");
    setModal(true);

    Last_name_line = new QLineEdit;
    First_name_line = new QLineEdit;
    Second_name_line = new QLineEdit;
    City_line = new QLineEdit;
    Street_line = new QLineEdit;
    House_line = new QLineEdit;
    Flat_line = new QLineEdit;
    Money_line = new QLineEdit;
    Pin_code_line = new QLineEdit;

    set_validation();

    QLabel* Last_name_label = new QLabel("Last_name: ");
    QLabel* First_name_label = new QLabel("First_name: ");
    QLabel* Second_name_label = new QLabel("Second_name: ");
    QLabel* City_label = new QLabel("City: ");
    QLabel* Street_label = new QLabel("Street: ");
    QLabel* House_label = new QLabel("House: ");
    QLabel* Flat_label = new QLabel("Flat: ");
    QLabel* Money_label = new QLabel("Money_state: ");
    QLabel* Pin_code_label = new QLabel("Create Pin code: ");

    QPushButton* Ok = new QPushButton("&Ок");



    QGridLayout* lay = new QGridLayout;
    lay->addWidget(Last_name_label, 0, 0);
    lay->addWidget(Last_name_line, 0, 1);
    lay->addWidget(First_name_label, 1, 0);
    lay->addWidget(First_name_line, 1, 1);
    lay->addWidget(Second_name_label, 2, 0);
    lay->addWidget(Second_name_line, 2, 1);
    lay->addWidget(City_label, 3, 0);
    lay->addWidget(City_line, 3, 1);
    lay->addWidget(Street_label, 4, 0);
    lay->addWidget(Street_line, 4, 1);
    lay->addWidget(House_label, 5, 0);
    lay->addWidget(House_line, 5, 1);
    lay->addWidget(Flat_label, 6, 0);
    lay->addWidget(Flat_line, 6, 1);
    lay->addWidget(Money_label, 7, 0);
    lay->addWidget(Money_line, 7, 1);
    lay->addWidget(Pin_code_label, 8, 0);
    lay->addWidget(Pin_code_line, 8, 1);


    QVBoxLayout* verticalLay = new QVBoxLayout;
    verticalLay->addLayout(lay);
    verticalLay->addWidget(Ok);

    setLayout(verticalLay);

    connect(Ok, SIGNAL(clicked()), this, SLOT(accept()));
}

void Add_Client_Dialog::set_validation(){
    QRegularExpression Last_name("^[A-Z][a-z]{2,20}");
    Last_name_check = new QRegularExpressionValidator(QRegularExpression(Last_name), Last_name_line);
    Last_name_line->setValidator(Last_name_check);

    QRegularExpression First_name("^[A-Z][a-z]{2,20}");
    First_name_check = new QRegularExpressionValidator(QRegularExpression(First_name), First_name_line);
    First_name_line->setValidator(First_name_check);

    QRegularExpression Second_name("^[A-Z][a-z]{2,20}");
    Second_name_check = new QRegularExpressionValidator(QRegularExpression(Second_name), Second_name_line);
    Second_name_line->setValidator(Second_name_check);

    QRegularExpression City_name("^[A-Z][a-z]{2,20}");
    City_check = new QRegularExpressionValidator(QRegularExpression(City_name), City_line);
    City_line->setValidator(City_check);

    QRegularExpression Street_name("^[A-Z][a-z ]{2,20}");
    Street_check = new QRegularExpressionValidator(QRegularExpression(Street_name), Street_line);
    Street_line->setValidator(Street_check);

    QRegularExpression House_name("([1-9])|([1-9][0-9])|(1[0-9][0-9])");
    House_check = new QRegularExpressionValidator(QRegularExpression(House_name), House_line);
    House_line->setValidator(House_check);

    QRegularExpression Flat_name("([1-9])|([1-9][0-9])|(1[0-9][0-9])");
    Flat_check = new QRegularExpressionValidator(QRegularExpression(Flat_name), Flat_line);
    Flat_line->setValidator(Flat_check);

    QRegularExpression Money_name("[1-9][0-9]{8}");
    Money_check = new QRegularExpressionValidator(QRegularExpression(Money_name), Money_line);
    Money_line->setValidator(Money_check);

    QRegularExpression Pin_code_name("[0-9]{4}");
    Pin_code_check = new QRegularExpressionValidator(QRegularExpression(Pin_code_name), Pin_code_line);
    Pin_code_line->setValidator(Pin_code_check);
}

QString Add_Client_Dialog::get_Last_name() const{
    return Last_name_line->text();
}

QString Add_Client_Dialog::get_First_name() const{
    return First_name_line->text();
}

QString Add_Client_Dialog::get_Second_name() const{
    return Second_name_line->text();
}

QString Add_Client_Dialog::get_City() const{
    return City_line->text();
}

QString Add_Client_Dialog::get_Street() const{
    return Street_line->text();
}

QString Add_Client_Dialog::get_House() const{
    return House_line->text();
}

QString Add_Client_Dialog::get_Flat() const{
    return Flat_line->text();
}

QString Add_Client_Dialog::get_Money() const{
    return Money_line->text();
}

QString Add_Client_Dialog::get_Pin_code() const{
    return Pin_code_line->text();
}
