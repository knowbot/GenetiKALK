#ifndef IPOLIMERO
#define IPOLIMERO
#include <QString>
//classe interfaccia per riferimenti polimorfi a istanze di polimero e derivate di istanze di polimero
class IPolimero {
private:
public:
//    static QString _massUnit;
    virtual ~IPolimero() = default;
    virtual void updateInfo() = 0;
    virtual QString toString() const = 0;
    virtual IPolimero* concat(IPolimero* const) const = 0;
};

//QString IPolimero::_massUnit = "u";

#endif // IPOLIMERO

