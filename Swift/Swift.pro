QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account_information.cpp \
    bank_class.cpp \
    client_class.cpp \
    credit_card_class.cpp \
    main.cpp \
    mainwindow.cpp \
    priorbank.cpp \
    transfer_card.cpp

HEADERS += \
    account_information.h \
    bank_class.h \
    client_class.h \
    credit_card_class.h \
    mainwindow.h \
    priorbank.h \
    receipt.h \
    transfer_card.h

FORMS += \
    account_information.ui \
    mainwindow.ui \
    transfer_card.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
