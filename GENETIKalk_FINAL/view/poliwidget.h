#ifndef POLIWIDGET_H
#define POLIWIDGET_H
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextBrowser>
#include <QMessageBox>
#include <QLine>
#include "model/polimero_include.h"
#include "politabwidget.h"

class PoliQTabWidget;
class poliController;

class PoliQWidget : public QWidget {
    Q_OBJECT
private:
    poliController* _controller;

    PoliQTabWidget* _parentTab;

    QLineEdit* _display;
    QTextBrowser* _consoleLog;

    QGroupBox* _baseOps;
    QGroupBox* _specOps;
    QGroupBox* _inputOps;
    QGroupBox* _memOps;

    QHBoxLayout* _memOpsLayout;

    QPushButton* _resetButton;
    QPushButton* _clearButton;

    QPushButton* _saveButton;
    QPushButton* _loadButton;
    QPushButton* _emptyButton;

protected:
    QPushButton* createButton(const QString&, QWidget*, const char*);

public:
    explicit PoliQWidget(PoliQTabWidget* parent = nullptr);
    virtual ~PoliQWidget();

    QLineEdit *display() const;
    void setDisplay(QLineEdit *display);

    QTextBrowser *consoleLog() const;
    void setConsoleLog(QTextBrowser *consoleLog);

    QGroupBox *baseOps() const;
    void setBaseOps(QGroupBox *baseOps);

    QGroupBox *specOps() const;
    void setSpecOps(QGroupBox *specialOps);

    QGroupBox *inputOps() const;
    void setInputOps(QGroupBox *inputOps);

    QGroupBox *memOps() const;
    void setmemOps(QGroupBox *memOps);

    QHBoxLayout *memOpsLayout() const;
    void setmemOpsLayout(QHBoxLayout *memOpsLayout);

    QPushButton *resetButton() const;
    void setResetButton(QPushButton *resetButton);

    QPushButton *clearButton() const;
    void setClearButton(QPushButton *clearButton);

    QPushButton *saveButton() const;
    void setSaveButton(QPushButton *saveButton);

    QPushButton *loadButton() const;
    void setLoadButton(QPushButton *loadButton);

    QPushButton *emptyButton() const;
    void setEmptyButton(QPushButton *emptyButton);

    PoliQTabWidget *getParentTab() const;
    void setParentTab(PoliQTabWidget *value);

    poliController *getController() const;
    void setController(poliController *controller);

    void refreshDisplay();
    void operationLog(const QString&);
    bool confirmOp(const QString&,const QString&, const QString&) const;

signals:

public slots:
    void clearLog();
};

#endif // POLIWIDGET_H
