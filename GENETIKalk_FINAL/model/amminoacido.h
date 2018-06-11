#ifndef AMMINOACIDO_H
#define AMMINOACIDO_H

#include<QVector>
#include "polimero_include.h"
#include "monomero.h"
#include "nucleotide.h"

class Amminoacido : public Monomero {
    //Ridefinizione di operator<<
    friend std::ostream& operator<<(std::ostream&, const Amminoacido&);

private:
    QVector<QString> _codon; //codoni associati

public:
    //Costruttore e distruttore
    Amminoacido(QString = "", QString = "", double = 0, QVector<QString> = {});
    ~Amminoacido() = default;

    //Metodi di get
    QVector<QString> getCodon() const;

    //Metodi di set
    void setCodon(const QVector<QString>&);

    Amminoacido* clone() const;

    //Metodi di calcolo
    double calcPercentage(const QVector<Amminoacido *> &) const;
    int findInSequence(const QVector<Nucleotide*>&) const;

    //Operatori ridefiniti
    bool operator==(const  Amminoacido&) const;

};

#endif // AMMINOACIDO_H
