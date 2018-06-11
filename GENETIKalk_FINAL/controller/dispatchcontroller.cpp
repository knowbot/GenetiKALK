#include "dispatchcontroller.h"

PoliQTabWidget *dispatchController::view() const {
    return _view;
}

void dispatchController::setView(PoliQTabWidget *view) {
    _view = view;
}


void dispatchController::dispatchObj(IPolimero *object, const QString &type) {
    PoliQWidget* receiver = _view->findChild<PoliQWidget*>(type);
    if(!receiver)
             throw new widgetNotFound("Non esiste una tab in grado di gesire questo tipo di dato!");
    receiver->getController()->receiveObj(object);
    _view->setCurrentWidget(receiver);
}

dispatchController::dispatchController(PoliQTabWidget * tab) : _view(tab) {
}
