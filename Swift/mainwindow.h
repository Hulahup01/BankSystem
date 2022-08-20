#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "credit_card_class.h"
#include "client_class.h"
#include "bank_class.h"
#include "priorbank.h"
#include "transfer_card.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool select_bank();
    bool select_client();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;

    Transfer_card* trans_card_window;
};
#endif // MAINWINDOW_H
