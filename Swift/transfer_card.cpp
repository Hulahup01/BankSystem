#include "transfer_card.h"
#include "ui_transfer_card.h"

Transfer_card::Transfer_card(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transfer_card)
{
    ui->setupUi(this);
    QPixmap pix("C:/Computer/Fucking Motherfucker QT/Swift/credit_card.png");
    ui->label_2->setPixmap(pix);
    ui->dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

}

Transfer_card::~Transfer_card()
{
    delete ui;
}

QString Transfer_card::get_line()
{
    return "";
}


void Transfer_card::on_pushButton_clicked()
{
    this->card_numb_from = ui->lineEdit_1_1->text();
    this->month_year_from = ui->dateEdit->text();
    this->card_owner = ui->lineEdit_1_2->text();
    this->cvv_code = ui->lineEdit_1_3->text();
    ui->pushButton->hide();
    ui->lineEdit_1_1->clear();
    ui->lineEdit_1_2->hide();
    ui->lineEdit_1_3->hide();
}


void Transfer_card::on_pushButton_2_clicked()
{
    this->card_numb_to = ui->lineEdit_1_1->text();
    this->month_year_to = ui->dateEdit->text();
    ui->pushButton_2->hide();
    ui->dateEdit->hide();
    ui->lineEdit_1_1->hide();
    ui->label->setText(this->card_numb_from);
    ui->label_2->setText(this->month_year_from);
    //ui->label_3->setText(this->card_owner);
    //ui->label_4->setText(this->cvv_code);
    ui->label_5->setText(this->card_numb_to);
    ui->label_6->setText(this->month_year_to);

}


void Transfer_card::on_pushButton_3_clicked()
{
    ui->lineEdit_1_1->clear();
    ui->lineEdit_1_1->show();

    ui->lineEdit_1_2->clear();
    ui->lineEdit_1_2->show();

    ui->lineEdit_1_3->clear();
    ui->lineEdit_1_3->show();

    ui->dateEdit->clear();
    ui->dateEdit->show();

    ui->pushButton->show();
    ui->pushButton_2->show();
    hide();
}

