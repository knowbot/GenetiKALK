#include <type_traits>
#include <assert.h>
#include "exceptions/exceptionhandle.h"
#include "polimero.h"
#include "nucleotide.h"

template <class T>
Polimero<T>::Polimero(QVector<T*> e) : _elems(std::move(e)) {
    assert((std::is_base_of<Monomero, T>::value));
}

template <class T>
Polimero<T>::Polimero(const Polimero<T> &p) {
    for(auto i : p.getElems())
        addElem(*i);
    updateInfo();
}

template <class T>
Polimero<T>::~Polimero() {
     for(auto it = _elems.begin(); it != _elems.end(); ++it) {
        delete *it;
        it = _elems.erase(it);
        --it;
     }
}

//Metodi di get
template<class T>
QVector<T *> Polimero<T>::getElems() const {
    return _elems;
}

template<class T>
int Polimero<T>::getLength() const {
    return _length;
}

template<class T>
double Polimero<T>::getMass() const {
    return _mass;
}

//Metodi di set
template <class T>
void Polimero<T>::setElems(const QVector<T*>& newElems) {
    _elems = newElems;
}

template <class T>
void Polimero<T>::setLength(const int& newLength) {
    _length = newLength;
}

template <class T>
void Polimero<T>::setMass(const double& newMass) {
    _mass = newMass;
}


template <class T>
void Polimero<T>::addElem(const T& elAgg) {
   QVector<T*> newVec = _elems;
   newVec.push_back(elAgg.clone());
   _elems = newVec;
   updateInfo();
}

template <class T>
void Polimero<T>::delElem() {
   QVector<T*> newVec = _elems;
   auto lastEl = newVec.end()-1;
   delete *lastEl;
   newVec.pop_back();
   _elems = newVec;
}

template <class T>
Polimero<T> *Polimero<T>::concat(IPolimero* const p) const {
    Polimero<T>* poli = dynamic_cast<Polimero<T>*>(p);
    QVector<T*> new_elems;
    for(auto i : this->getElems())
        new_elems.push_back((*i).clone());
    for(auto i : poli->getElems())
        new_elems.push_back((*i).clone());
    return new Polimero<T>(new_elems);
}

//Metodi di calcolo
template <class T>
double Polimero<T>::calcMass() const {
    double mass = 0;
    for(auto i : _elems)
        mass += i->getMass();
    return mass;
}

template <class T>
void Polimero<T>::updateInfo() {
    setLength(_elems.size());
    setMass(calcMass());
}

template <class T>
QString Polimero<T>::toString() const {
    QString s;
    for(auto i : _elems)
        s.append(i->getAcr());
    return s;
}




