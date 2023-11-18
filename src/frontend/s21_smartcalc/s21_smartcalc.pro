QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../backend/s21_deposit_credit.c \
    ../../backend/s21_smartcalc.c \
    ../../backend/s21_stack_op.c \
    ../../backend/s21_support.c \
    credit_calc.cpp \
    deposit_calc.cpp \
    graps.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../backend/s21_smartcalc.h \
    credit_calc.h \
    deposit_calc.h \
    graps.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    credit_calc.ui \
    deposit_calc.ui \
    graps.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
