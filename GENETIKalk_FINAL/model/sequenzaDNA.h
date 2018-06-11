//
// Created by andre on 10/01/2018.
//
#ifndef DNAKALK_PAO1718_SEQUENZADNA_H
#define DNAKALK_PAO1718_SEQUENZADNA_H

#include "gen_costants.h"
#include "polimero_include.h"
#include "nucleotide.h"
#include "sequenzaRNA.h"

class seqRNA; //risolve dipendenza circolare

//classe DNA
class seqDNA : public Polimero<Nucleotide> {
    //Ridefinizione di operator<<
    friend std::ostream& operator<<(std::ostream&, const seqDNA&);

private:
    bool _isSense;
    seqDNA* _seqComp = nullptr;

public:
    //Costruttore e distruttore
    seqDNA(QVector<Nucleotide *> = {}, bool = true, seqDNA* = nullptr);
    ~seqDNA();
    //Costruttore di copia
    seqDNA(const seqDNA&);

    //Metodi di get
    bool getIsSense() const;
    seqDNA* getSeqComp() const;

    //Metodi di set
    void setIsSense(const bool&);
    void setSeqComp(seqDNA*);

    //Metodi di calcolo
    //calcola massa
    double calcMass() const override;
    bool validate(const Nucleotide &) const;
    void calcSeqComp();
    seqRNA* toRNA() const;

    //Metodi di manipolazione
    //ridefinizione di addElem, aggiunge un elemento
    void addElem(const Nucleotide &) override;
    //ridefinizione di delElem
    void delElem() override;
    //concatenazione
    seqDNA* concat(IPolimero * const) const override;
    //scambia con filamento complementare
    seqDNA* toSeqComp();
    //distrugge filamento complementare
    void delSeqComp();

};

#endif //DNAKALK_PAO1718_SEQUENZADNA_H
