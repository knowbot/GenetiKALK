#ifndef RNACONTROLLER_H
#define RNACONTROLLER_H
#include "model/sequenzaRNA.h"
#include "view/rnawidget.h"
#include "policontroller.h"

class RNAQWidget;

class RNAController : public poliController {

    Q_OBJECT

private:
    seqRNA* _activeObj;
    seqRNA* _storedObj;
    RNAQWidget* _view;

public:
    RNAController(seqRNA * = nullptr, RNAQWidget * = nullptr);
    ~RNAController();

    seqRNA *activeObj() const;
    void setActiveObj(seqRNA *activeObj);

    seqRNA *storedObj() const;
    void setStoredObj(seqRNA *storedObj);

    RNAQWidget *view() const;
    void setView(RNAQWidget *view);

    void receiveObj(IPolimero*) override;

public slots:
    void addElement(const QString&);
    void delElement() ;
    void saveMemory();
    void loadMemory();
    void emptyMemory();

    void baseOpLen();
    void baseOpMass() ;
    void baseOpConcat() ;
    void baseOpSense();

    void specOpSplicing();
    void specOpFindAmm();
    void specOpsToDNA();
    void specOpsToPro();

    void resetCalc();
};

#endif // RNACONTROLLER_H
