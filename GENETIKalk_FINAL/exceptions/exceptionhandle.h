#ifndef EXCEPTIONHANDLE
#define EXCEPTIONHANDLE
#include <QString>
class exceptionHandler {
private:
    QString _excMessage;
public:
    exceptionHandler(QString text = "Unknown exception occurred.") : _excMessage(text) {}
    virtual ~exceptionHandler() = default;
    QString excMessage() const { return _excMessage; }
};

class typeExc : public exceptionHandler {
public:
     typeExc(QString text) : exceptionHandler(text) {}
};

class typeIsInvalid : public typeExc {
public:
     typeIsInvalid(QString text) : typeExc(text) {}
};

class typeIsIncompatible : public typeExc {
public:
     typeIsIncompatible(QString text) : typeExc(text) {}
};

class emptyExc : public exceptionHandler {
public:
    emptyExc(QString text) : exceptionHandler(text) {}
};

class emptyObj : public emptyExc {
public:
    emptyObj(QString text) : emptyExc(text) {}
};

class emptyMember : public emptyExc {
public:
    emptyMember(QString text) : emptyExc(text) {}
};

class memExc : public exceptionHandler {
public:
    memExc(QString text) : exceptionHandler(text) {}
};

class memIsEmpty : public memExc {
public:
    memIsEmpty(QString text) : memExc(text) {}
};

class notFoundExc : public exceptionHandler {
public:
    notFoundExc(QString text) : exceptionHandler(text) {}
};

class objectNotFound : public notFoundExc {
public:
    objectNotFound(QString text) : notFoundExc(text) {}
};

class widgetNotFound : public notFoundExc {
public:
    widgetNotFound(QString text) : notFoundExc(text) {}
};

class outOfBounds : public exceptionHandler {
public:
    outOfBounds(QString text) : exceptionHandler(text) {}
};

class abortOp : public exceptionHandler {
public:
    abortOp(QString text) : exceptionHandler(text) {}
};
#endif // EXCEPTIONHANDLE

