#ifndef RECEIPT_H
#define RECEIPT_H
#include <QFileDialog>
#include <QFile>
#include <QDate>

static void issue_a_receipt(QString txt_Directory, QString bank_name, QString adress, QString contact_details, QDateTime transaction_date,
                            QString senders_card, QString recipients_card, double transfer_amount, double commission, QString currency){

    QString text_receipt = "\n\n                         RECEIPT                         \n"
                           "*********************************************************\n";


    for(int i = 0;i<(57 - bank_name.length())/2;i++)
        text_receipt+=" ";
    text_receipt+=bank_name+"\n";


    text_receipt+= "                         'SWIFT'                         \n";


    for(int i = 0;i<(57 - adress.length())/2;i++)
        text_receipt+=" ";
    text_receipt+=adress+"\n";


    for(int i = 0;i<(57 - contact_details.length())/2;i++)
        text_receipt+=" ";
    text_receipt+=contact_details+"\n";


    text_receipt += "*********************************************************\n";

    text_receipt += "                 Date: " + transaction_date.toString("dd.MM.yyyy hh:mm") + "\n";

    text_receipt += "                 Card: " + senders_card.mid(0,6) + "******" + senders_card.mid(12,4) + "\n";

    text_receipt += "*********************************************************\n";

    text_receipt += " Recipient's card: " + recipients_card.mid(0,4) + " " + recipients_card.mid(5,2) + "** **** " + recipients_card.mid(12,4) + "\n";

    text_receipt += " Transfer amount: " + QString::number(transfer_amount) + " " +currency +"\n";

    text_receipt += " Commission: " + QString::number(commission) + " " +currency + "\n";

    text_receipt += " Amount to be paid: " + QString::number(transfer_amount+commission) + " " +currency + "\n";

    text_receipt += "*********************************************************\n";

    text_receipt += "                        THANK YOU!                         ";



    QFile receipt_file(txt_Directory);
    if (receipt_file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        receipt_file.write(text_receipt.toStdString().c_str());
        receipt_file.close();
    }

}

#endif // RECEIPT_H
