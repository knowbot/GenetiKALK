//
// Created by andre on 10/01/2018.
//
#include <iostream>
#include <algorithm>
#include "sequenzaDNA.h"

/************SEQDNA************/
//Ridefinizione di operator<<
std::ostream& operator<<(std::ostream& os, const seqDNA& d) {
    for(auto i : d.getElems())
        os << i->getAcr().toUtf8().constData();
    return os;
}

//Costruttore
seqDNA::seqDNA(QVector<Nucleotide *> e, bool i, seqDNA * c) : Polimero(std::move(e)), _isSense(i), _seqComp(c) {
    updateInfo();
}

//Distruttore profondo
seqDNA::~seqDNA() {
    try {
        delSeqComp();
    } catch(emptyMember* e) {} //necessario per gestire il delete
                               //su una sequenza senza complementare
}

    //Funzione ausiliaria
void seqDNA::delSeqComp() {
    if(!_seqComp)
        throw new emptyMember("Nessun filamento complementare presente.");
    _seqComp->setSeqComp(nullptr); //altrimenti viene tentata la distruzione dell'oggetto corrente, dato che _seqComp._seqComp punta a this
    delete _seqComp;
    _seqComp = nullptr;
}

//Costruttore di copia profonda
seqDNA::seqDNA(const seqDNA &d) : Polimero() { //mi limito a creare il sottooggetto vuoto, i cui campi andrò a riempire in seguito
    for(auto i : d.getElems())
       addElem(*i);
    updateInfo();
    if(d.getSeqComp())  {
    setSeqComp(new seqDNA());
    for(auto j : d.getSeqComp()->getElems())
            getSeqComp()->addElem(*j);
    }
}

//Metodi di get
bool seqDNA::getIsSense() const {
    return _isSense;
}
seqDNA* seqDNA::getSeqComp() const {
    return _seqComp;
}

//Metodi di set
void seqDNA::setIsSense(const bool &newSense) {
    _isSense = newSense;
}
void seqDNA::setSeqComp(seqDNA* newSeqComp) {
    _seqComp = newSeqComp;
}

//Metodi di calcolo
bool seqDNA::validate(const Nucleotide &n) const {
    return std::find(gencode::dnaCode.begin(), gencode::dnaCode.end(), n) != gencode::dnaCode.end();
}

double seqDNA::calcMass() const {
    double mass = 0;
    for(auto i : getElems())
        mass += i->getMass();
    if (getSeqComp() && getSeqComp()->getElems().size() > 0) //se la grandezza è diversa da 0 (contiene elementi) aggiunge la massa del filamento complementare
        for(auto j : getSeqComp()->getElems())
            mass += j->getMass();
    return mass;
}

void seqDNA::calcSeqComp()  {
    if(getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    if(_seqComp)
        delSeqComp();
    QVector<Nucleotide *> _elemsComp;
    _elemsComp.reserve(getElems().size());
    for(auto i : getElems())
        for(auto j : gencode::dnaCode)
            if(i->getComp() == j.getAcr())
                _elemsComp.push_back(j.clone());
    setSeqComp(new seqDNA(_elemsComp, !getIsSense(), this));
}

//traduce in RNA
seqRNA* seqDNA::toRNA() const {
    if(getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Nucleotide*> _toRNAelems;
    _toRNAelems.reserve(getElems().size());
    for(auto i : getElems())
        for(auto j : gencode::rnaCode)
            if(j.getComp() == i->getAcr())
                _toRNAelems.push_back(j.clone());
    return new seqRNA(_toRNAelems, !_isSense);
}

//uso un vector intermedio per evitare errori di sorta: in inserimento consuma più memoria, ma in caso
//di errori imprevisti/interruzioni evita modifiche permanenti all'oggetto

//Metodi di manipolazione
void seqDNA::addElem(const Nucleotide &elAgg) {
    QVector<Nucleotide*> newVec = getElems();
    if(!validate(elAgg))
        throw new objectNotFound("Nucleotide non valido.");
    newVec.push_back(elAgg.clone());
    setElems(newVec);
    if(_seqComp)
        calcSeqComp();
    updateInfo();
}

void seqDNA::delElem() {
    if (getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Nucleotide *> newVec = getElems();
    auto lastEl = newVec.end()-1;
    delete *lastEl;
    newVec.pop_back();
    setElems(newVec);
    if(_seqComp)
       calcSeqComp();
    updateInfo();
}

seqDNA* seqDNA::concat(IPolimero* const s) const {
    seqDNA* seq = dynamic_cast<seqDNA*>(s);
    if(!seq)
        throw new typeIsIncompatible("Tentativo di concatenare una sequenza DNA e un polimero incompatibile.");
    QVector<Nucleotide*> new_elems;
    for(auto i : this->getElems())
        new_elems.push_back((*i).clone());
    for(auto i : seq->getElems())
        new_elems.push_back((*i).clone());
    return new seqDNA(new_elems);
}

seqDNA* seqDNA::toSeqComp() {
    if(!_seqComp)
        throw new emptyMember("Nessun filamento complementare presente.");
    return getSeqComp();
}




