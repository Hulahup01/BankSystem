#ifndef TRANSFER_CARD_H
#define TRANSFER_CARD_H

#include <QWidget>
#include <QtGui>
#include <QAbstractSpinBox>

namespace Ui {
class Transfer_card;
}

class Transfer_card : public QWidget
{
    Q_OBJECT

public:
    explicit Transfer_card(QWidget *parent = nullptr);
    ~Transfer_card();

    QString get_line();

//signals:
//    void back_to_mainwindow();
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Transfer_card *ui;

    QString card_numb_from;
    QString month_year_from;
    QString card_owner;
    QString cvv_code;
    QString card_numb_to;
    QString month_year_to;
};

#endif // TRANSFER_CARD_H
