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

    set_credit_card_img();
    create_step_1_window();
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
    ui->step_2_label->hide();
    ui->step_3_label->hide();

    ui->step_2_button->hide();
    ui->step_3_button->hide();

    ui->step_2_img->hide();
    ui->date_label_4->hide();
    ui->date_label_5->hide();
    ui->date_edit_2->hide();
    ui->card_numb_edit_2->hide();
    ui->label->hide();

    ui->invalid_name_sender_label->hide();
    ui->invalid_date_sender_label->hide();
    ui->invalid_number_sender_label->hide();
    ui->invalid_cvv_sender_label->hide();

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
}

void Transfer_card::on_step_1_button_clicked()
{
//    for(auto i : priorbank->get_clients()){
//        qDebug() << i.credit_card().get_cvv_code();
//        qDebug() << i.credit_card().get_card_numb();    // Test completed!!!
//    }
    if(sender_data_check())
        create_step_2_window();
    else
        qDebug() << "No!";
}

bool Transfer_card::sender_data_check()
{
    if(sender_card_numb_check() && sender_month_year_check())
        return 1;
}

bool Transfer_card::sender_card_numb_check()
{
    bool isCorrect(false);

    for(auto i : priorbank->get_clients()){
        if(get_card_numb(ui->card_numb_edit->text()) == i.credit_card().get_card_numb())
            isCorrect = true;
    }

    if(isCorrect)
        return 1;
    else{
        ui->card_numb_edit->clear();
        ui->invalid_number_sender_label->show();
        return 0;
    }
}

bool Transfer_card::sender_month_year_check()
{
    bool isCorrect(false);

    for(auto i : priorbank->get_clients()){
        if(get_date(ui->date_edit->text()) == i.credit_card().get_date())
            isCorrect = true;
    }

    if(isCorrect)
        return 1;
    else{
        ui->date_edit->setDate(QDate::currentDate());
        ui->invalid_date_sender_label->show();
        return 0;
    }
}

void Transfer_card::create_step_2_window()
{
//    this->card_numb = get_card_numb(ui->card_numb_edit->text());
//    this->month_year_from = ui->date_edit->text();
//    this->card_owner = ui->holder_name_edit->text();
//    this->cvv_code = ui->cvv_edit->text();

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
    ui->invalid_cvv_sender_label->hide();
    ui->invalid_date_sender_label->hide();
    ui->invalid_name_sender_label->hide();
    ui->invalid_number_sender_label->hide();

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
    create_step_3_window();
}

void Transfer_card::create_step_3_window()
{
//    this->card_numb = ui->card_numb_edit->text();
//    this->month_year = ui->date_edit->text();

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

    ui->label->show();
    ui->step_3_label->show();
    ui->step_3_button->show();
}

void Transfer_card::on_step_3_button_clicked()
{
    create_step_1_window();

   // QString fname =  QFileDialog::getExistingDirectory(this, tr("Open Directory"),
   // "/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks)+"/receipt.txt";

    hide();
}
Transfer_card::~Transfer_card()
{
    delete ui;
}

void Transfer_card::set_priorbank(PriorBank* priorbank)
{
    this->priorbank = priorbank;
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

    qDebug() << result;

    return result;
}

