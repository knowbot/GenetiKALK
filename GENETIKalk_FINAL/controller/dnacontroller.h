#ifndef DNACONTROLLER_H
#define DNACONTROLLER_H
#include "model/sequenzaDNA.h"
#include "view/dnawidget.h"
#include "policontroller.h"

class DNAQWidget;

class DNAController : public poliController {

    Q_OBJECT

private:
    seqDNA* _activeObj;
    seqDNA* _storedObj;
    DNAQWidget* _view;

public:
    DNAController(seqDNA *s = nullptr, DNAQWidget * = nullptr);
    ~DNAController();

    seqDNA *activeObj() const;
    void setActiveObj(seqDNA *activeObj);

    seqDNA *storedObj() const;
    void setStoredObj(seqDNA *storedObj);

    DNAQWidget *view() const;
    void setView(DNAQWidget *view);

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
    void resetCalc();

    void specOpCalcComp();
    void specOpSwitchComp();
    void specOpDelComp();
    void specOpToRNA();
};

#endif // DNACONTROLLER_H
