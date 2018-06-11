#ifndef PROQWIDGET_H
#define PROQWIDGET_H

#include <QGridLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include "poliwidget.h"
#include "model/proteina.h"


class ProQWidget : public PoliQWidget {
    Q_OBJECT
private:
    QComboBox* _selectAmm;
    QPushButton* _insertAmm;

    QGridLayout* _baseOpsLayout;
    QVBoxLayout* _specOpsLayout;
    QGridLayout* _inputOpsLayout;

    QPushButton* _calcLen;
    QPushButton* _calcMass;
    QPushButton* _calcVol;
    QPushButton* _concat;

    QPushButton* _calcPercentage;
    QPushButton* _compareToPro;

    QPushButton* _delEl;

public:
    explicit ProQWidget(PoliQTabWidget *parent = nullptr);
    ~ProQWidget() = default;

    Proteina *getActivePro() const;
    void setActivePro(Proteina *value);

    QGridLayout *getBaseOpsLayout() const;
    void setBaseOpsLayout(QGridLayout *baseOpsLayout);

    QVBoxLayout *getSpecOpsLayout() const;
    void setSpecOpsLayout(QVBoxLayout *specOpsLayout);

    QGridLayout *getInputOpsLayout() const;
    void setInputOpsLayout(QGridLayout *inputOpsLayout);

    Proteina *getStoredPro() const;
    void setStoredPro(Proteina *storedPro);

    QComboBox *getSelectAmm() const;
    void setSelectAmm(QComboBox *selectAmm);

    QPushButton *getCalcLen() const;
    void setCalcLen(QPushButton *calcLen);

    QPushButton *getCalcMass() const;
    void setCalcMass(QPushButton *calcMass);

    QPushButton *getCalcVol() const;
    void setCalcVol(QPushButton *calcVol);

    QPushButton *getConcat() const;
    void setConcat(QPushButton *concat);

    QPushButton *getCalcPercentage() const;
    void setCalcPercentage(QPushButton *calcPercentage);

    QPushButton *getCompareToPro() const;
    void setCompareToPro(QPushButton *compareToPro);

    QPushButton *getDelEl() const;
    void setDelEl(QPushButton *delEl);

    QPushButton *getInsertAmm() const;
    void setInsertAmm(QPushButton *insertAmm);

signals:

public slots:

};

#endif // PROQWIDGET_H
