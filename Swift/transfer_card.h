#ifndef TRANSFER_CARD_H
#define TRANSFER_CARD_H

#include <QWidget>
#include <QtGui>
#include <QAbstractSpinBox>
#include "priorbank.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include "receipt.h"

namespace Ui {
class Transfer_card;
}

class Transfer_card : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer_card(QDialog *parent = nullptr);
    ~Transfer_card();

    void set_banks(PriorBank* priorbank, AlphaBank* alphabank, BelarusBank* belarusbank);
    QString get_card_numb(const QString card_numb);
    QString get_date(const QString date);

    void set_button_style();
    void set_credit_card_img();
    void create_step_1_window();
    void create_step_2_window();
    void create_step_3_window();

    bool sender_data_check();
    QString sender_card_numb_check();
    bool sender_month_year_check(const QString numb);
    bool sender_card_holder_check();
    bool sender_cvv_code_check(const QString numb);

    bool recipient_data_check();
    QString recipient_card_numb_check();
    bool recipient_month_year_check(const QString numb);

    void invalid_or_empty_show();
    void invalid_or_empty_hide();

    void step_1_get_info();
    void step_2_get_info();
    bool run_transact();

    bool in_or_out_fee();

    QString split_card_numb(QString card_numb);


//signals:
//    void back_to_mainwindow();
private slots:


    void on_step_1_button_clicked();

    void on_step_2_button_clicked();

    void on_step_3_button_clicked();

    void on_card_numb_edit_textChanged(const QString &arg1);

    void on_gift_no_perc_textChanged(const QString &arg1);

private:
    Ui::Transfer_card *ui;

    QString card_numb_sender;
    QString month_year_sender;
    QString card_holder;
    QString cvv_code;

    QString card_numb_recipient;
    QString month_year_recipient;

    int sizeCard = 16;

    PriorBank* priorbank;
    AlphaBank* alphabank;
    BelarusBank* belarusbank;

    QString bank_sender;
    QString bank_recipient;


};

#endif // TRANSFER_CARD_H
