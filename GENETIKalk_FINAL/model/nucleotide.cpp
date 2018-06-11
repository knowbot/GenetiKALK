//
// Created by andre on 10/01/2018.
//
#include "nucleotide.h"

//Ridefinizione di operator<<
std::ostream& operator<<(std::ostream& os, const Nucleotide& n) {
    return os << n.getName().toUtf8().constData() << " - " << n.getAcr().toUtf8().constData();
}

//Costruttore
Nucleotide::Nucleotide(QString n, QString s, double p, bool h, QString co) : Monomero(std::move(n), s, p), _hasOxy(h), _comp(co){ }

//Metodi di get
QString Nucleotide::getComp() const {
    return _comp;
}

bool Nucleotide::getHasOxy() const {
    return _hasOxy;
}

//Metodi di set
void Nucleotide::setComp(const QString & c) {
    _comp = c;
}

void Nucleotide::setHasOxy(const bool & h) {
    _hasOxy = h;
}

Nucleotide* Nucleotide::clone() const {
    return new Nucleotide(*this);
}

//Operatori ridefiniti
bool Nucleotide::operator==(const Nucleotide& n) const {
    return getName() == n.getName() && getAcr() == n.getAcr() && getHasOxy() == n.getHasOxy();
}



