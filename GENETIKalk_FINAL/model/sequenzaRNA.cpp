//
// Created by andre on 10/01/2018.
//
#include <iostream>
#include <algorithm>
#include "sequenzaRNA.h"

/************seqRNA************/
//Ridefinizione di operator<<
std::ostream& operator<<(std::ostream& os, const seqRNA& r) {
    for(auto i : r.getElems())
        os << i->getAcr().toUtf8().constData();
    return os;
}

//Costruttore
seqRNA::seqRNA(QVector<Nucleotide *> e, bool i) : Polimero(std::move(e)), _isSense(i) {
        updateInfo();
}

//Distruttore profondo
seqRNA::~seqRNA() {
}

//Costruttore di copia profonda
seqRNA::seqRNA(const seqRNA &r) : Polimero() { //mi limito a creare il sottooggetto vuoto, i cui campi andrò a riempire in seguito
    for(auto i : r.getElems())
       addElem(*i);
    updateInfo();
}


//Metodi di get
bool seqRNA::getIsSense() const {
    return _isSense;
}

//Metodi di set
void seqRNA::setIsSense(const bool& newSense) {
    _isSense = newSense;
}

//Metodi di calcolo
bool seqRNA::validate(const Nucleotide & n) const {
    return std::find(gencode::rnaCode.begin(), gencode::rnaCode.end(), n) != gencode::rnaCode.end();
}

seqDNA* seqRNA::toDNA() const {
    if(getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Nucleotide *> _toDNAelems;
    _toDNAelems.reserve(getElems().size());
    for(auto i : getElems())
        for(auto j : gencode::dnaCode)
            if( j.getAcr() == i->getComp() )
                _toDNAelems.push_back(j.clone());
    return new seqDNA(_toDNAelems, !_isSense);
}

Proteina* seqRNA::toProtein() const {
    if(getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Amminoacido*> _toProElems;
    int elemsLeft = getElems().size();
    bool stop = false;
    unsigned int currPos = 0;
    auto it1 = getElems().begin();
    for(; elemsLeft>2; it1+=3, currPos+=3,  elemsLeft-=3) {
        bool found = false;
        stop = false;
        for(auto it2 = gencode::proCode.begin(); it2 != gencode::proCode.end() && !(found || stop); ++it2) {
            QVector<Nucleotide*> currSeq = getElems().mid(currPos,3);
            if(it2->findInSequence(currSeq)) {
                if(!found) {
                     found = true;
                     if(it2->getAcr()!="STOP")
                         _toProElems.push_back(it2->clone());
                     else
                        stop = true;
                }
            }
        }
    }
    return new Proteina(_toProElems);
}

//Metodi di manipolazione
void seqRNA::addElem(const Nucleotide &elAgg) {
    QVector<Nucleotide*> newVec = getElems();
    if(!validate(elAgg))
        throw new objectNotFound("Nucleotide non valido.");
    newVec.push_back(elAgg.clone());
    setElems(newVec);
    updateInfo();
}

void seqRNA::delElem() {
    if (getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Nucleotide *> newVec = getElems();
    auto lastEl = newVec.end()-1;
    delete *lastEl;
    newVec.pop_back();
    setElems(newVec);
    updateInfo();
}

seqRNA *seqRNA::concat(IPolimero * const s) const {
    seqRNA* seq = dynamic_cast<seqRNA*>(s);
    if(!seq)
        throw new typeIsIncompatible("Tentativo di concatenare una sequenza RNA e un polimero incompatibile.");
    QVector<Nucleotide*> new_elems;
    for(auto i : this->getElems())
        new_elems.push_back((*i).clone());
    for(auto i : seq->getElems())
        new_elems.push_back((*i).clone());
    return new seqRNA(new_elems);
}

void seqRNA::splicing (unsigned int ind1, unsigned int ind2)  {
    if(getLength()<1)
        throw new emptyObj("Sequenza vuota.");
    QVector<Nucleotide *> result = getElems();
    if(ind1 > ind2 || ind1 > static_cast<unsigned int>(result.size()) || ind2 > static_cast<unsigned int>(result.size()))
        throw new outOfBounds("Indici di splicing non validi");
    result.erase(result.begin()+ind1-1, result.begin()+ind2);
    setElems(result);
    updateInfo();
}
