#ifndef TRANSMITCONTROLLER_H
#define TRANSMITCONTROLLER_H
#include "model/polimero_include.h"
#include "view/politabwidget.h"
#include "view/poliwidget.h"
#include "policontroller.h"

class PoliQTabWidget;

class dispatchController : public QObject {
    Q_OBJECT
private:
    PoliQTabWidget *_view;
public:
    dispatchController(PoliQTabWidget* = nullptr);
    ~dispatchController() = default;

    PoliQTabWidget *view() const;

    void setView(PoliQTabWidget *view);
    void dispatchObj(IPolimero*, const QString&);
};

#endif // TRANSMITCONTROLLER_H
