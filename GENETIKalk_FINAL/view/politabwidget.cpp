#include "politabwidget.h"
#include "gkqwidgets.h"
#include<iostream>

dispatchController *PoliQTabWidget::dispatcher() const
{
    return _dispatcher;
}

void PoliQTabWidget::setDispatcher(dispatchController *dispatcher)
{
    _dispatcher = dispatcher;
}

PoliQTabWidget::PoliQTabWidget(QWidget *parent, dispatchController *d) : QTabWidget(parent), _dispatcher(d) {

}


