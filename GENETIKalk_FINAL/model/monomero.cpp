#include "monomero.h"

//Costruttore
Monomero::Monomero(QString n, QString s, double p) : _name(std::move(n)), _acr(s), _mass(p) {}

//Metodi di get
QString Monomero::getName() const {
    return _name;
}

QString Monomero::getAcr() const {
    return _acr;
}

double Monomero::getMass() const {
    return _mass;
}

//Metodi di set
void Monomero::setName(const QString &name) {
    _name = name;
}

void Monomero::setAcr(const QString &acr) {
    _acr = acr;
}

void Monomero::setMass(double mass) {
    _mass = mass;
}

Monomero *Monomero::clone() const {
    return new Monomero(*this);
}

bool Monomero::operator==(const Monomero &m) const {
    return this->getAcr() == m.getAcr() && this->getName() == m.getName();
}
