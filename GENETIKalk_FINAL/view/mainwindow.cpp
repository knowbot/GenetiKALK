#include <QVBoxLayout>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "politabwidget.h"
#include "controller/dispatchcontroller.h"
#include "controller/dnacontroller.h"
#include "controller/rnacontroller.h"
#include "controller/procontroller.h"
#include "dnawidget.h"
#include "rnawidget.h"
#include "proteinawidget.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)/*, ui(new Ui::MainWindow) */{
    //ui->setupUi(this);
    try {
        setWindowTitle("GenetiKALK");
        PoliQTabWidget* tabCollection = new PoliQTabWidget(this);
        tabCollection->setDispatcher(new dispatchController(tabCollection));

        PoliQWidget* tabDNA = new DNAQWidget(tabCollection);
        DNAQWidget* proxyTabDNA = dynamic_cast<DNAQWidget*>(tabDNA); //effettuo un cast per assicurarmi di
        if(proxyTabDNA)                                              //assegnare il controller al giusto tipo di tab
            proxyTabDNA->setController(new DNAController(new seqDNA, proxyTabDNA));
        else
            throw new typeIsIncompatible("Assegnazione di controller specifico fallita.");

        PoliQWidget* tabRNA = new RNAQWidget(tabCollection);
        RNAQWidget* proxyTabRNA = dynamic_cast<RNAQWidget*>(tabRNA);
        if(proxyTabRNA)
            proxyTabRNA->setController(new RNAController(new seqRNA, proxyTabRNA));
        else
            throw new typeIsIncompatible("Assegnazione di controller specifico fallita.");

        PoliQWidget* tabPro = new ProQWidget(tabCollection);
        ProQWidget* proxyTabPro = dynamic_cast<ProQWidget*>(tabPro);
        if(proxyTabPro)
            proxyTabPro->setController(new ProController(new Proteina, proxyTabPro));
        else
            throw new typeIsIncompatible("Assegnazione di controller specifico fallita.");

        tabCollection->addTab(tabDNA, "DNA");
        tabCollection->addTab(tabRNA, "RNA");
        tabCollection->addTab(tabPro, "Proteina");
        setCentralWidget(tabCollection);
        setFixedSize(670, 450);
    }  catch(widgetNotFound* w) { hide();
                                  std::cout << w->excMessage().toUtf8().constData();}
       catch(typeIsIncompatible* t) { hide();
                                      std::cout << t->excMessage().toUtf8().constData();}
       catch(exceptionHandler* e) { hide();
                                    std::cout << e->excMessage().toUtf8().constData();}
}

MainWindow::~MainWindow()
{
    //delete ui;
}
