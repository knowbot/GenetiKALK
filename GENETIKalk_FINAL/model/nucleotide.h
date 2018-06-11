//
// Created by andre on 10/01/2018.
//
#ifndef DNAKALK_PAO1718_NUCLEOTIDE_H
#define DNAKALK_PAO1718_NUCLEOTIDE_H

#include <iostream>
#include "monomero.h"

class Nucleotide : public Monomero {
    //Ridefinizione di operator<<
    friend std::ostream& operator<<(std::ostream&, const Nucleotide&);

private:
    bool _hasOxy; //false indica desossiribonucleotide (nel DNA), true indica ribonucleotide (RNA)
    QString _comp;

public:
    //Costruttore e distruttore
    Nucleotide(QString = "\0", QString = "\0", double = 0, bool = false, QString = "\0");
    ~Nucleotide() = default;

    //Metodi di get
    QString getComp() const;
    bool getHasOxy() const;

    //Metodi di set
    void setComp(const QString &);
    void setHasOxy(const bool &);

    Nucleotide* clone() const;

    //Operatori ridefiniti
    bool operator==(const Nucleotide&) const;

};

#endif //DNAKALK_PAO1718_NUCLEOTIDE_H
