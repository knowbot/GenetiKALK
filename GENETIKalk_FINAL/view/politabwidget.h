#ifndef POLIQTABWIDGET_H
#define POLIQTABWIDGET_H
#include <QTabWidget>
#include "model/polimero_include.h"
#include "controller/dispatchcontroller.h"

class dispatchController;

class PoliQTabWidget : public QTabWidget {
    Q_OBJECT
private:
    dispatchController* _dispatcher;

public:
    PoliQTabWidget(QWidget* = nullptr, dispatchController* = nullptr);
    ~PoliQTabWidget() = default;

    dispatchController *dispatcher() const;
    void setDispatcher(dispatchController *dispatcher);

signals:

public slots:

};

#endif // POLIQTABWIDGET_H
