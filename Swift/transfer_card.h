#ifndef TRANSFER_CARD_H
#define TRANSFER_CARD_H

#include <QWidget>
#include <QtGui>
#include <QAbstractSpinBox>
#include "priorbank.h"
#include <QFileDialog>
#include <QFile>

namespace Ui {
class Transfer_card;
}

class Transfer_card : public QDialog
{
    Q_OBJECT

public:
    explicit Transfer_card(QDialog *parent = nullptr);
    ~Transfer_card();

    void set_priorbank(PriorBank* priorbank);
    QString get_card_numb(const QString card_numb);
    QString get_date(const QString date);

    void set_button_style();
    void set_credit_card_img();
    void create_step_1_window();
    void create_step_2_window();
    void create_step_3_window();

    bool sender_data_check();
    bool sender_card_numb_check();
    bool sender_month_year_check();
    bool sender_card_holder_check();
    bool sender_cvv_code_check();



//signals:
//    void back_to_mainwindow();
private slots:


    void on_step_1_button_clicked();

    void on_step_2_button_clicked();

    void on_step_3_button_clicked();


private:
    Ui::Transfer_card *ui;

    QString card_numb;
    QString month_year;
    QString card_holder;
    QString cvv_code;

    PriorBank* priorbank;

};

#endif // TRANSFER_CARD_H
