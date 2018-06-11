#ifndef PROTEINA_H
#define PROTEINA_H

#include "gen_costants.h"
#include "polimero_include.h"
#include "amminoacido.h"

class Proteina : public Polimero<Amminoacido> {
    //Ridefinizione di operator<<
    friend std::ostream& operator<<(std::ostream&, const Proteina&);

private:
    double _volume;

public:
    //Costruttore e distruttore
    Proteina(QVector<Amminoacido*> = {}, double = 0);
    ~Proteina();
    Proteina(const Proteina&);

    //Metodi di get
    double getVolume() const;

    //Metodi di set
    void setVolume(double);

    //Metodi di manipolazione
    void addElem(const Amminoacido&) override;
    void delElem() override;
    Proteina* concat(IPolimero * const) const override;

    //Metodi di calcolo
    void updateInfo() override;
    double calcVolume() const;
    bool validate(const Amminoacido&) const;
    bool isSimilar(const Proteina&); //calcola la somiglianza tra due diverse proteine

};

#endif // PROTEINA_H
