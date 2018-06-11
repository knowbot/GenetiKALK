#ifndef PROCONTROLLER_H
#define PROCONTROLLER_H
#include "view/proteinawidget.h"
#include "model/proteina.h"
#include "policontroller.h"

class ProController : public poliController {
    Q_OBJECT

private:
    Proteina* _activeObj;
    Proteina* _storedObj;
    ProQWidget* _view;

public:
    ProController(Proteina *s = nullptr, ProQWidget* = nullptr);
    ~ProController();

    Proteina *activeObj() const;
    void setActiveObj(Proteina *activeObj);

    Proteina *storedObj() const;
    void setStoredObj(Proteina *storedObj);

    ProQWidget *view() const;
    void setView(ProQWidget *view);

    void receiveObj(IPolimero*) override;

public slots:
    void addElement();
    void delElement();
    void saveMemory();
    void loadMemory();
    void emptyMemory();
    void baseOpLen();
    void baseOpMass();
    void baseOpConcat();
    void baseOpVol();
    void specOpPercentage();
    void specOpCompare();
    void resetCalc();

};

#endif // PROCONTROLLER_H
