#ifndef POLICONTROLLER_H
#define POLICONTROLLER_H
#include <QObject>
#include "model/polimero_include.h"
#include "exceptions/exceptionhandle.h"
class poliController : public QObject {
    Q_OBJECT
private:
public:
    explicit poliController() {}
    virtual ~poliController() = default;
    virtual void receiveObj(IPolimero*) = 0;
    virtual IPolimero* activeObj() const = 0;
};

#endif // POLICONTROLLER_H
