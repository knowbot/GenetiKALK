#include <cmath>
#include "proteina.h"

//Ridefinizione di operator<<
std::ostream& operator<<(std::ostream& os, const Proteina& p) {
    for(auto i : p.getElems())
        os << i->getAcr().toUtf8().constData();
    return os;
}



//Costruttore
Proteina::Proteina(QVector<Amminoacido*> e, double v) : Polimero(std::move(e)), _volume(v) {
    updateInfo();
}

Proteina::~Proteina() {
}

Proteina::Proteina(const Proteina &p) : Polimero() { //mi limito a creare il sottooggetto vuoto, i cui campi andrò a riempire in seguito
    for(auto i : p.getElems())
       addElem(*i);
    updateInfo();
}

//Metodi di get
double Proteina::getVolume() const {
    return _volume;
}

//Metodi di set
void Proteina::setVolume(double newVolume) {
    _volume = newVolume;
}

//Metodi di calcolo
bool Proteina::validate(const Amminoacido &a) const {
    return std::find(gencode::proCode.begin(), gencode::proCode.end(), a) != gencode::proCode.end();
}

double Proteina::calcVolume() const { //in angstrom
    return (0.73*pow(10,24)*calcMass())/(6.02*pow(10,23));
}

void Proteina::updateInfo() {
    Polimero::updateInfo();
    setVolume(calcVolume());
}

bool Proteina::isSimilar(const Proteina & p) {
    unsigned int sameAA = 0; //conta amminoacidi in comune
    if(p.getLength()<1)
        throw new emptyObj("Proteina di confronto vuota.");
    if(getLength()<1)
        throw new emptyObj("Proteina corrente vuota.");
    for(auto i : this->getElems())
        for(auto j : p.getElems())
            if(*i == *j)
                sameAA++;
    unsigned int l1 = getLength(), l2 = p.getLength(), maxL = 1;
    auto max = [&]()  { (l1 > l2) ? maxL = l1 : maxL = l2; }; //lambda espressione per calcolare la lunghezza max
    max();
    return (((sameAA*100)/maxL >= 30.))? true : false;
}

//Metodi di manipolazione
void Proteina::addElem(const Amminoacido &elAgg){
    QVector<Amminoacido *> newVec = getElems();
    if(!validate(elAgg))
        throw new objectNotFound("Amminoacido non valido.");
    newVec.push_back(elAgg.clone());
    setElems(newVec);
    updateInfo();
}

void Proteina::delElem(){
    if (getLength()<1)
        throw new emptyObj("Proteina vuota.");
    QVector<Amminoacido*> newVec = getElems();
    auto lastEl = newVec.end()-1;
    delete *lastEl;
    newVec.pop_back();
    setElems(newVec);
    updateInfo();
}

Proteina* Proteina::concat(IPolimero * const p) const {
    Proteina* pro = dynamic_cast<Proteina*>(p);
    if(!pro)
        throw new typeIsIncompatible("Tentativo di concatenare una proteina e un polimero incompatibile.");
    QVector<Amminoacido*> new_elems;
    for(auto i : this->getElems())
        new_elems.push_back((*i).clone());
    for(auto i : pro->getElems())
        new_elems.push_back((*i).clone());
    return new Proteina(new_elems);
}
