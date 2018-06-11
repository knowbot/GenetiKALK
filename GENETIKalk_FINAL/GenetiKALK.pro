#-------------------------------------------------
#
# Project created by QtCreator 2018-02-07T11:20:45
#
#-------------------------------------------------

QT += core gui
QT += widgets

QT_SELECT=qt5
greaterThan(QT_MAJOR_VERSION, 5):  QT += gui
lessThan(QT_MAJOR_VERSION, 5): error("requires QT 5")

TARGET = GenetiKALK
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
    model/amminoacido.cpp \
    model/monomero.cpp \
    model/nucleotide.cpp \
    model/polimero.cpp \
    model/proteina.cpp \
    model/sequenzaDNA.cpp \
    model/sequenzaRNA.cpp \
    view/mainwindow.cpp \
    view/poliwidget.cpp \
    view/dnawidget.cpp \
    view/proteinawidget.cpp \
    view/politabwidget.cpp \
    controller/dispatchcontroller.cpp \
    controller/dnacontroller.cpp \
    controller/rnacontroller.cpp \
    view/rnawidget.cpp \
    controller/procontroller.cpp \
    model/gen_costants.cpp

HEADERS  += \
    model/amminoacido.h \
    model/monomero.h \
    model/nucleotide.h \
    model/polimero.h \
    model/polimero_include.h \
    model/proteina.h \
    model/sequenzaDNA.h \
    model/sequenzaRNA.h \
    view/mainwindow.h \
    view/poliwidget.h \
    view/dnawidget.h \
    view/proteinawidget.h \
    view/politabwidget.h \
    view/gkqwidgets.h \
    controller/dispatchcontroller.h \
    controller/dnacontroller.h \
    controller/rnacontroller.h \
    view/rnawidget.h \
    controller/policontroller.h \
    model/ipolimero.h \
    controller/procontroller.h \
    exceptions/exceptionhandle.h \
    model/gen_costants.h

ICON += img/img.ico

FORMS  += mainwindow.ui

DISTFILES +=

RESOURCES +=
