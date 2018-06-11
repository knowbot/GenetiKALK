#ifndef DNAQWIDGET_H
#define DNAQWIDGET_H
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSignalMapper>
#include "poliwidget.h"
#include "model/sequenzaDNA.h"
#include "controller/policontroller.h"

class DNAQWidget : public PoliQWidget {

    Q_OBJECT

private:
    QSignalMapper* _inputCode;

    QGridLayout* _baseOpsLayout;
    QVBoxLayout* _specOpsLayout;
    QGridLayout* _inputOpsLayout;

    QPushButton* _printSense;
    QPushButton* _calcLen;
    QPushButton* _calcMass;
    QPushButton* _concat;

    QPushButton* _calcComp;
    QPushButton* _switchComp;
    QPushButton* _delComp;
    QPushButton* _trToRNA;

    QPushButton* _addA;
    QPushButton* _addT;
    QPushButton* _addC;
    QPushButton* _addG;
    QPushButton* _delEl;


public:
    explicit DNAQWidget(PoliQTabWidget * = nullptr);
    ~DNAQWidget();

    QGridLayout *getBaseOpsLayout() const;
    void setBaseOpsLayout(QGridLayout *baseOpsLayout);

    QGridLayout *getInputOpsLayout() const;
    void setInputOpsLayout(QGridLayout *inputOpsLayout);

    QSignalMapper *getInputCode() const;
    void setInputCode(QSignalMapper *inputCode);

    QPushButton *getPrintSense() const;
    void setPrintSense(QPushButton *printSense);

    QPushButton *getCalcLen() const;
    void setCalcLen(QPushButton *calcLen);

    QPushButton *getCalcMass() const;
    void setCalcMass(QPushButton *calcMass);

    QPushButton *getConcat() const;
    void setConcat(QPushButton *concat);

    QPushButton *getCalcComp() const;
    void setCalcComp(QPushButton *calcComp);

    QPushButton *getSwitchComp() const;
    void setSwitchComp(QPushButton *switchComp);

    QPushButton *getDelComp() const;
    void setDelComp(QPushButton *delComp);

    QPushButton *getTrToRNA() const;
    void setTrToRNA(QPushButton *trToRNA);

    QPushButton *getAddA() const;
    void setAddA(QPushButton *addA);

    QPushButton *getAddT() const;
    void setAddT(QPushButton *addT);

    QPushButton *getAddC() const;
    void setAddC(QPushButton *addC);

    QPushButton *getAddG() const;
    void setAddG(QPushButton *addG);

    QPushButton *getDelEl() const;
    void setDelEl(QPushButton *delEl);

signals:

public slots:

};

#endif // DNAQWIDGET_H
