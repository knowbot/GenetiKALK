#include "amminoacido.h"
#include "sequenzaDNA.h"
#include "sequenzaRNA.h"

//Ridefinizione di operator<<
std::ostream& operator<<(std::ostream& os, const Amminoacido& a) {
    return os << a.getName().toUtf8().constData() << " - " << a.getAcr().toUtf8().constData();
}

//Costruttore
Amminoacido::Amminoacido(QString name, QString acr, double mass, QVector<QString> cod)
    : Monomero(name, acr, mass), _codon(cod) {}

//Metodi di get
QVector<QString> Amminoacido::getCodon() const {
    return _codon;
}

//Metodi di set
void Amminoacido::setCodon(const QVector<QString>& c) {
    _codon = c;
}

Amminoacido *Amminoacido::clone() const {
    return new Amminoacido(*this);
}

//Metodi di calcolo
//cerca l'amminoacido in una data sequenza di RNA, e restituisce la posizione del primo nucleotide del codone nella sequenza
int Amminoacido::findInSequence(const QVector<Nucleotide *> &s) const {
    if(!s.size())
        throw new emptyObj("Sequenza vuota");
    for(auto it = s.begin(); it != s.end() && (s.size() - (it - s.begin()))>=3; it++) {
        QString temp = "";
        temp.append((*it)->getAcr());
        if((it + 1) != s.end())
            temp.append((*(it+1))->getAcr());
        if(((it + 2) - s.begin()) < s.size())
            temp.append((*(it+2))->getAcr());
        for (auto j : getCodon())
            if(temp == j)
                return (it - s.begin() + 1);
    }
    return 0;
}

double Amminoacido::calcPercentage(const QVector<Amminoacido *> &p) const {
    int count = 0;
    if(!p.size())
        throw new emptyObj("Sequenza vuota.");
    for(auto i : p) {
        if(*i == *this)
            count++;
    }
    return ((count*100)/p.size());
}

//Operatori ridefiniti
bool Amminoacido::operator==(const Amminoacido & a) const {
    return a.getAcr()==getAcr() && a.getName()==getName();
}
