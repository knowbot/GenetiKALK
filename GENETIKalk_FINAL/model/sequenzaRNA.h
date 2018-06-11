#ifndef SEQUENZARNA_H
#define SEQUENZARNA_H

#include "gen_costants.h"
#include "polimero_include.h"
#include "nucleotide.h"
#include "sequenzaDNA.h"
#include "proteina.h"

class seqDNA; //risolve dipendenza circolare

//classe RNA
class seqRNA : public Polimero<Nucleotide> {
    friend std::ostream& operator<<(std::ostream&, const seqRNA&);
private:
    //direzione della sequenza
    bool _isSense;

public:
/*costruttore, copia profonda, distruttore*/
    seqRNA(QVector<Nucleotide *> = {}, bool = true);
    ~seqRNA();
    seqRNA(const seqRNA&);

/*Metodi getter*/
    bool getIsSense() const;

/*Metodi setter*/
    void setIsSense(const bool&);


/*Metodi di calcolo*/
    bool validate(const Nucleotide&) const;

/*Metodi di manipolazione*/
    void addElem(const Nucleotide&) override;
    void delElem() override;
    seqRNA* concat(IPolimero* const) const override;

    seqDNA* toDNA() const;
    Proteina* toProtein() const;
    void splicing(unsigned int, unsigned int);
};

#endif // SEQUENZARNA_H
