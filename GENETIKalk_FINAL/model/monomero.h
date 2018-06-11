//
// Created by andre on 05/01/2018.
//
#ifndef DNAKALK_PAO1718_MONOMERO_H
#define DNAKALK_PAO1718_MONOMERO_H

#include <QString>
class Monomero {

private:
    QString _name;
    QString _acr;
    double _mass;

protected:
    //Costruttore
    Monomero(QString = "\0", QString = "\0", double = 0);

public:
    //Distruttore
    virtual ~Monomero() = default;

    //Metodi di get
    QString getName() const;
    void setName(const QString &name);
    QString getAcr() const;

    //Metodi di set
    void setAcr(const QString &acr);
    double getMass() const;
    void setMass(double mass);

    //Metodi virtuali
    virtual Monomero* clone() const;

    bool operator ==(const Monomero &) const;
};
#endif //DNAKALK_PAO1718_MONOMERO_H
