#ifndef RNAQWIDGET_H
#define RNAQWIDGET_H
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QComboBox>
#include <QInputDialog>
#include "poliwidget.h"
#include "model/sequenzaRNA.h"
#include "controller/policontroller.h"

class RNAQWidget : public PoliQWidget {

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

    QPushButton* _splicing;
    QPushButton* _findAmm;
    QPushButton* _trToDNA;
    QPushButton* _trToPro;

    QPushButton* _addA;
    QPushButton* _addU;
    QPushButton* _addC;
    QPushButton* _addG;
    QPushButton* _delEl;

public:
    explicit RNAQWidget(PoliQTabWidget* parent = nullptr);
    ~RNAQWidget();

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

    QPushButton *getSplicing() const;
    void setSplicing(QPushButton *splicing);

    QPushButton *getFindAmm() const;
    void setFindAmm(QPushButton *findAmm);

    QPushButton *getTrToDNA() const;
    void setTrToDNA(QPushButton *trToDNA);

    QPushButton *getTrToPro() const;
    void setTrToPro(QPushButton *trToPro);

    QPushButton *getAddA() const;
    void setAddA(QPushButton *addA);

    QPushButton *getAddU() const;
    void setAddU(QPushButton *addU);

    QPushButton *getAddC() const;
    void setAddC(QPushButton *addC);

    QPushButton *getAddG() const;
    void setAddG(QPushButton *addG);

    QPushButton *getDelEl() const;
    void setDelEl(QPushButton *delEl);

    QString chooseAmmDialog() const;

signals:

public slots:

};

#endif // RNAQWIDGET_H
