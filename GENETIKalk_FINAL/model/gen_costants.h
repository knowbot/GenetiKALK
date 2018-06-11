#ifndef GEN_COSTANTS_H
#define GEN_COSTANTS_H
#include <QVector>
#include "nucleotide.h"
#include "amminoacido.h"
namespace gencode {
    extern const QString massUnit;
    extern const QVector<Nucleotide> dnaCode;
    extern const QVector<Nucleotide> rnaCode;
    extern const QVector<Amminoacido> proCode;
}

#endif // GEN_COSTANTS_H
