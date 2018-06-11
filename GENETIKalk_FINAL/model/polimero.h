#ifndef POLIMERO_H
#define POLIMERO_H
#include "ipolimero.h"
#include<QVector>
template <class T>
class Polimero : public IPolimero {
private:
    QVector<T *> _elems;
    int _length;
    double _mass;

protected:

public:
    //Costruttore
    Polimero(QVector<T*> = {}); //lunghezza e peso sono derivati automaticamente dall'array di inizializzazione
    //Distruttore profondo virtuale (tutte le classi derivate necessitano disruzione profonda di _elems)
    Polimero(const Polimero&);
    virtual ~Polimero();

    //Metodi di get
    QVector<T*> getElems() const;
    int getLength() const;
    double getMass() const;

    //Metodi di set
    void setElems(const QVector<T *> &);
    void setLength(const int &);
    void setMass(const double &);

/*Metodi virtuali*/
    //Metodi di manipolazione
    virtual void addElem(const T &);
    virtual void delElem();
    Polimero<T>* concat(IPolimero* const) const override;

    //metodi di calcolo
    virtual double calcMass() const;

    void updateInfo() override;
    QString toString() const override;
};

#endif // POLIMERO_H
