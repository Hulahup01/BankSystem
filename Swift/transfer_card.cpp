#include "transfer_card.h"
#include "ui_transfer_card.h"

Transfer_card::Transfer_card(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Transfer_card)
{
    ui->setupUi(this);
    setWindowTitle("Swift. Transfer from card to card");
    setFixedSize(575, 330);
    setModal(true);
    setWindowIcon(QIcon("../Swift/icon_logo.png"));


    set_credit_card_img();
    set_button_style();
}

void Transfer_card::set_credit_card_img()
{
    QPixmap pix_1("../Swift/Сredit__card.png");
    ui->step_1_img->setPixmap(pix_1);

    QPixmap pix_2("../Swift/credit_card(receiver).png");
    ui->step_2_img->setPixmap(pix_2);
}

void Transfer_card::create_step_1_window()
{
    ui->step_3_label_2->hide();
    ui->step_3_label_3->hide();
    ui->step_3_label_4->hide();
    ui->step_3_label_5->hide();
    ui->step_3_label_6->hide();
    ui->step_3_label_7->hide();
    ui->step_3_label_8->hide();
    ui->step_3_label_9->hide();
    ui->step_3_label_10->hide();
    ui->step_3_label_11->hide();
    ui->step_3_label_12->hide();
    ui->step_3_fee_label->hide();
    ui->invalid_or_empty_label->hide();
    ui->required_number_sender_label->hide();
    ui->required_date_sender_label->hide();
    ui->required_name_sender_label->hide();
    ui->required_cvv_sender_label->hide();
    ui->required_number_sender_label_2->hide();
    ui->required_date_sender_label_2->hide();
    ui->gift_no_perc->hide();
    ui->gift_perc->hide();
    ui->step_2_label->hide();
    ui->step_3_label->hide();

    ui->step_2_button->hide();
    ui->step_3_button->hide();
    ui->checkBox->hide();

    ui->step_2_img->hide();
    ui->date_label_4->hide();
    ui->date_label_5->hide();
    ui->date_edit_2->hide();
    ui->card_numb_edit_2->hide();
    ui->label->hide();

    ui->required_name_sender_label->hide();
    ui->required_date_sender_label->hide();
    ui->required_number_sender_label->hide();
    ui->required_cvv_sender_label->hide();
    ui->invalid_or_empty_label->hide();

    ui->cvv_edit->clear();
    ui->card_holder_edit->clear();
    ui->card_numb_edit->clear();
    ui->date_edit->setDate(QDate::currentDate());

    ui->card_holder_edit->show();
    ui->card_holder_label->show();
    ui->card_numb_edit->show();
    ui->date_edit->show();
    ui->cvv_edit->show();
    ui->date_label_2->show();
    ui->date_label_3->show();
    ui->step_1_img->show();
    ui->step_1_button->show();
    ui->step_1_label->show();
    ui->cvv_label->show();
    ui->header_label->show();


    ui->header_label->setText("Sender's card details");
}

void Transfer_card::set_button_style()
{
    ui->step_1_button->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->step_2_button->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");
    ui->step_3_button->setStyleSheet("color: white; background-color: #195375; border-radius: 7px");

    ui->date_edit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->date_edit_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->gift_no_perc->setButtonSymbols(QAbstractSpinBox::NoButtons);
}

void Transfer_card::on_step_1_button_clicked()
{

    if(sender_data_check()){
        step_1_get_info();
        create_step_2_window();
    }
}

bool Transfer_card::sender_data_check()
{
    QString numb = sender_card_numb_check();
    bool date = sender_month_year_check(numb);
    bool holder = sender_card_holder_check();
    bool cvv = sender_cvv_code_check(numb);

    if(numb.length() && date && holder && cvv)
        return 1;
    else{
        ui->invalid_or_empty_label->show();
        return 0;
    }
}

QString Transfer_card::sender_card_numb_check()
{
    ui->required_number_sender_label->hide();
    if(ui->card_numb_edit->text().length() == 0){
        ui->required_number_sender_label->show();
        return "";
    }

    QString numb = "";

    for(auto i : priorbank->get_clients()){
        if(get_card_numb(ui->card_numb_edit->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_sender = "priorbank";
        }
    }

    for(auto i : alphabank->get_clients()){
        if(get_card_numb(ui->card_numb_edit->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_sender = "alphabank";
        }
    }

    for(auto i : belarusbank->get_clients()){
        if(get_card_numb(ui->card_numb_edit->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_sender = "belarusbank";
        }
    }

    if(numb.length())
        return numb;
    else{
        ui->required_number_sender_label->show();
        return "";
    }
}

bool Transfer_card::sender_month_year_check(const QString numb)
{
    ui->required_date_sender_label->hide();
    if(ui->date_edit->text().length() == 0){
        ui->required_date_sender_label->show();
        return 0;
    }

    bool isCorrect(false);

    for(auto i : priorbank->get_clients()){
        if((get_date(ui->date_edit->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : alphabank->get_clients()){
        if((get_date(ui->date_edit->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : belarusbank->get_clients()){
        if((get_date(ui->date_edit->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    if(isCorrect)
        return 1;
    else{
        ui->date_edit->setDate(QDate::currentDate());
        ui->required_date_sender_label->show();
        return 0;
    }
}

bool Transfer_card::sender_card_holder_check()
{
    ui->required_name_sender_label->hide();

    if(ui->card_holder_edit->text().length() == 0){
        ui->required_name_sender_label->show();
        return 0;
    }
    else
        return 1;
}

bool Transfer_card::sender_cvv_code_check(const QString numb)
{
    ui->required_cvv_sender_label->hide();
    if(ui->cvv_edit->text().length() == 0){
        ui->required_cvv_sender_label->show();
        return 0;
    }

    bool isCorrect(false);

    for(auto i : priorbank->get_clients()){
        if((ui->cvv_edit->text() == i.credit_card().get_cvv_code()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : alphabank->get_clients()){
        if((ui->cvv_edit->text() == i.credit_card().get_cvv_code()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : belarusbank->get_clients()){
        if((ui->cvv_edit->text() == i.credit_card().get_cvv_code()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    if(isCorrect)
        return 1;
    else{
        ui->cvv_edit->clear();
        ui->required_cvv_sender_label->show();
        return 0;
    }
}

void Transfer_card::invalid_or_empty_show()
{
    ui->invalid_or_empty_label->show();
}

void Transfer_card::invalid_or_empty_hide()
{
    ui->invalid_or_empty_label->hide();
}

void Transfer_card::step_1_get_info()
{
    this->card_numb_sender = get_card_numb(ui->card_numb_edit->text());
    this->month_year_sender = get_date(ui->date_edit->text());
    this->card_holder = ui->card_holder_edit->text();
    this->cvv_code = ui->cvv_edit->text();
}

void Transfer_card::step_2_get_info()
{
    this->card_numb_recipient = get_card_numb(ui->card_numb_edit_2->text());
    this->month_year_recipient = get_date(ui->date_edit_2->text());
}

bool Transfer_card::run_transact()
{   if(this->bank_sender == "priorbank"){
        for(std::vector<Client_class>::iterator it = priorbank->get_clients().begin(); it != priorbank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_sender){

                if(it->get_Money() >= ui->gift_perc->text().toDouble()){
                    it->set_Money(ui->gift_perc->text().toDouble() * (-1));
                    priorbank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
                }
                else{
                  QMessageBox::critical(this,"Error", "Insufficient funds!");
                 return 0;
                }
            }
        }
    }
    else if(this->bank_sender == "alphabank") {
        for(std::vector<Client_class>::iterator it = alphabank->get_clients().begin(); it != alphabank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_sender){

                if(it->get_Money() >= ui->gift_perc->text().toDouble()) {
                    it->set_Money(ui->gift_perc->text().toDouble() * (-1));
                    alphabank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
                }
                else{
                  QMessageBox::critical(this,"Error", "Insufficient funds!");
                 return 0;
                }
            }
        }
    }
    else if(this->bank_sender == "belarusbank"){
        for(std::vector<Client_class>::iterator it = belarusbank->get_clients().begin(); it != belarusbank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_sender){

                if(it->get_Money() >= ui->gift_perc->text().toDouble()){
                    it->set_Money(ui->gift_perc->text().toDouble() * (-1));
                    belarusbank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
                }
                else{
                  QMessageBox::critical(this,"Error", "Insufficient funds!");
                 return 0;
                }
            }
        }
    }

    if(this->bank_recipient == "priorbank"){
        for(std::vector<Client_class>::iterator it = priorbank->get_clients().begin(); it != priorbank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_recipient){
                it->set_Money(ui->gift_no_perc->text().toDouble());
                priorbank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
            }
        }
    }
    else if(this->bank_recipient == "alphabank"){
        for(std::vector<Client_class>::iterator it = alphabank->get_clients().begin(); it != alphabank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_recipient){
                it->set_Money(ui->gift_no_perc->text().toDouble());
                alphabank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
            }
        }
    }
    else if(this->bank_recipient == "belarusbank"){
        for(std::vector<Client_class>::iterator it = belarusbank->get_clients().begin(); it != belarusbank->get_clients().end(); it++){
            if(it->credit_card().get_card_numb() == this->card_numb_recipient){
                it->set_Money(ui->gift_no_perc->text().toDouble());
                belarusbank->send_to_bank((ui->gift_perc->text().toDouble() - ui->gift_no_perc->text().toDouble()) / 2);
            }
        }
    }


    return 1;
}


QString Transfer_card::split_card_numb(QString card_numb)
{
    QString result;
    for(int i = 0; i < 16; i++){
        result += card_numb[i];
        if(i == 3 || i == 7 || i == 11)
            result += ' ';
    }

    return result;
}

void Transfer_card::create_step_2_window()
{
    ui->invalid_or_empty_label->hide();
    ui->step_1_label->hide();
    ui->step_1_button->hide();
    ui->card_holder_edit->hide();
    ui->cvv_edit->hide();
    ui->card_holder_label->hide();
    ui->date_label_2->hide();
    ui->date_label_3->hide();
    ui->cvv_label->hide();
    ui->step_1_img->hide();
    ui->card_numb_edit->hide();
    ui->date_edit->hide();
    ui->label->hide();
    ui->required_cvv_sender_label->hide();
    ui->required_date_sender_label->hide();
    ui->required_name_sender_label->hide();
    ui->required_number_sender_label->hide();

    ui->card_numb_edit_2->clear();
    ui->date_edit_2->setDate(QDate::currentDate());


    ui->step_2_label->show();
    ui->step_2_button->show();
    ui->step_2_img->show();
    ui->date_label_4->show();
    ui->date_label_5->show();
    ui->date_edit_2->show();
    ui->card_numb_edit_2->show();

    ui->header_label->setText("Recipient's card details");
}

void Transfer_card::on_step_2_button_clicked()
{


    if(recipient_data_check()){
        step_2_get_info();

        if(this->card_numb_sender != this->card_numb_recipient)
            create_step_3_window();
        else{
            ui->card_numb_edit_2->clear();
            ui->required_number_sender_label_2->show();
            invalid_or_empty_show();
        }
    }
}

bool Transfer_card::recipient_data_check()
{
    QString numb = recipient_card_numb_check();
    bool date = recipient_month_year_check(numb);

    if(numb.length() && date)
        return 1;
    else{
        ui->invalid_or_empty_label->show();
        return 0;
    }
}

QString Transfer_card::recipient_card_numb_check()
{
    ui->required_number_sender_label_2->hide();
    if(ui->card_numb_edit_2->text().length() == 0){
        ui->required_number_sender_label_2->show();
        return "";
    }

    QString numb = "";

    for(auto i : priorbank->get_clients()){
        if(get_card_numb(ui->card_numb_edit_2->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_recipient = "priorbank";
        }
    }

    for(auto i : alphabank->get_clients()){
        if(get_card_numb(ui->card_numb_edit_2->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_recipient = "alphabank";
        }
    }

    for(auto i : belarusbank->get_clients()){
        if(get_card_numb(ui->card_numb_edit_2->text()) == i.credit_card().get_card_numb()){
            numb = i.credit_card().get_card_numb();
            this->bank_recipient = "belarusbank";
        }
    }

    if(numb.length())
        return numb;
    else{
        ui->required_number_sender_label_2->show();
        return "";
    }
}

bool Transfer_card::recipient_month_year_check(const QString numb)
{
    ui->required_date_sender_label_2->hide();
    if(ui->date_edit->text().length() == 0){
        ui->required_date_sender_label_2->show();
        return 0;
    }

    bool isCorrect(false);

    for(auto i : priorbank->get_clients()){
        if((get_date(ui->date_edit_2->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : alphabank->get_clients()){
        if((get_date(ui->date_edit_2->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    for(auto i : belarusbank->get_clients()){
        if((get_date(ui->date_edit_2->text()) == i.credit_card().get_date()) && (numb == i.credit_card().get_card_numb()))
            isCorrect = true;
    }

    if(isCorrect)
        return 1;
    else{
        ui->date_edit_2->setDate(QDate::currentDate());
        ui->required_date_sender_label_2->show();
        return 0;
    }
}

void Transfer_card::create_step_3_window()
{
    ui->checkBox->show();
    ui->gift_perc->show();
    ui->gift_no_perc->show();
    ui->step_2_label->hide();
    ui->step_2_button->hide();
    ui->date_edit->hide();
    ui->card_numb_edit->hide();
    ui->step_1_img->hide();
    ui->step_2_img->hide();
    ui->date_label_4->hide();
    ui->date_label_5->hide();
    ui->date_edit_2->hide();
    ui->card_numb_edit_2->hide();
    ui->header_label->hide();
    ui->required_number_sender_label_2->hide();
    invalid_or_empty_hide();

    ui->label->show();
    ui->step_3_label->show();
    ui->step_3_button->show();

    ui->step_3_label_2->show();
    ui->step_3_label_3->show();
    ui->step_3_label_4->show();
    ui->step_3_label_5->show();
    ui->step_3_label_6->show();
    ui->step_3_label_7->show();
    ui->step_3_label_8->show();

    ui->step_3_label_9->setText(split_card_numb(this->card_numb_recipient));
    ui->step_3_label_9->show();

    ui->step_3_label_10->setText(ui->date_edit_2->text());
    ui->step_3_label_10->show();

    ui->step_3_label_11->setText(split_card_numb(this->card_numb_sender));
    ui->step_3_label_11->show();

    ui->step_3_label_12->setText(ui->date_edit->text());
    ui->step_3_label_12->show();

    ui->step_3_fee_label->show();
}

void Transfer_card::on_step_3_button_clicked()
{
    if(run_transact()){
        if(ui->checkBox->isChecked()){
                QString fname =  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                "/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks)+"/receipt.txt";
                issue_a_receipt(fname, this->bank_sender, "Hikalo 9", "+375-29-293-86-65",
                    QDateTime::currentDateTime(), this->card_numb_sender, this->card_numb_recipient, ui->gift_no_perc->text().toDouble(),
                    ui->step_3_fee_label->text().toDouble(), "BYN");
        }

        create_step_1_window();
        hide();
    }



}
Transfer_card::~Transfer_card()
{
    delete ui;
}

void Transfer_card::set_banks(PriorBank* priorbank, AlphaBank* alphabank, BelarusBank* belarusbank)
{
    this->priorbank = priorbank;
    this->alphabank = alphabank;
    this->belarusbank = belarusbank;
}

QString Transfer_card::get_card_numb(const QString card_numb)
{
    QString result;
    for(auto i : card_numb){
        if(i != ' ')
            result += i;
    }

    return result;
}

QString Transfer_card::get_date(const QString date)
{
    QString result;
    for(auto i : date){
        if(i != '/')
            result += i;
    }

    QString::iterator it = result.begin();
    QString::iterator it2 = it + 1;

    if(*it == '0')
        result.erase(it, it2);

    return result;
}


void Transfer_card::on_card_numb_edit_textChanged(const QString &arg1)
{
    if(sizeCard > arg1.length() && (arg1.length() == 7 || arg1.length() == 14 || arg1.length() == 21)){
        QString temp = arg1;
        temp.chop(4);
        ui->card_numb_edit->setText(temp);
    }

    if(arg1.length() == 4)
        ui->card_numb_edit->setText(arg1 + "   ");
    else if(arg1.length() == 11)
        ui->card_numb_edit->setText(arg1 + "   ");
    else if(arg1.length() == 18)
        ui->card_numb_edit->setText(arg1 + "   ");

    sizeCard = arg1.length();
}

void Transfer_card::on_gift_no_perc_textChanged(const QString &arg1)
{
    QString temp = arg1;
    double fee;
    if(this->bank_recipient == "priorbank"){
        if(in_or_out_fee())
            fee = temp.toDouble() * priorbank->get_percent_in() * 0.01;
        else
            fee = temp.toDouble() * priorbank->get_percent_out() * 0.01;
    }
    else if(this->bank_recipient == "alphabank"){
        if(in_or_out_fee())
            fee = temp.toDouble() * alphabank->get_percent_in() * 0.01;
        else
            fee = temp.toDouble() * alphabank->get_percent_out() * 0.01;
    }
    else if(this->bank_recipient == "belarusbank"){
        if(in_or_out_fee())
            fee = temp.toDouble() * belarusbank->get_percent_in() * 0.01;
        else
            fee = temp.toDouble() * belarusbank->get_percent_out() * 0.01;
    }
    double total = temp.toDouble() + fee;
    ui->gift_perc->setText(QString::number(total));


    ui->step_3_fee_label->setText(QString::number(fee));
}

bool Transfer_card::in_or_out_fee()
{
    if(!this->bank_sender.compare(this->bank_recipient))
        return 1;
    else
        return 0;
}

