#include "dnacontroller.h"

seqDNA *DNAController::activeObj() const {
    return _activeObj;
}

void DNAController::setActiveObj(seqDNA *activeSeq) {
    _activeObj = activeSeq;
}

seqDNA *DNAController::storedObj() const {
    return _storedObj;
}

void DNAController::setStoredObj(seqDNA *storedSeq) {
    _storedObj = storedSeq;
}

DNAQWidget *DNAController::view() const {
    return _view;
}

void DNAController::setView(DNAQWidget *view) {
    _view = view;
}

//METODI
void DNAController::receiveObj(IPolimero *newObj) {
    try {
        seqDNA* newActive = dynamic_cast<seqDNA*>(newObj);
        if(!newActive)
            throw new typeIsIncompatible("Sequenza ricevuta di tipo incompatibile.");
        if(_activeObj && _activeObj->getLength() > 0) {
            bool confirm = _view->confirmOp("Esiste una sequenza attiva. Sovrascriverla?", "Procedi", "Annulla");
            if(confirm) {
                delete _activeObj;
                setActiveObj(dynamic_cast<seqDNA*>(newObj));
             }
        }   else    {
            if(_activeObj)
                delete _activeObj;
            setActiveObj(dynamic_cast<seqDNA*>(newObj));
        }
        _view->operationLog("Sequenza ricevuta con successo!");
        _view->refreshDisplay();
    } catch(typeExc* t) {_view->operationLog(t->excMessage());}
}

//SLOTS
void DNAController::addElement(const QString& newEl) {
    try {
        bool found = false;
        for(auto i = gencode::dnaCode.begin(); i != gencode::dnaCode.end() && !found; ++i)
            if (i->getAcr() == newEl) {
                _activeObj->addElem(*i);
                found = true;
            }
        if(!found)
            throw new objectNotFound("Nucleotide non valido.");
        _view->refreshDisplay();
    } catch(notFoundExc* f) { _view->operationLog(f->excMessage()); }
}

void DNAController::delElement() {
    try {
        if(!_activeObj)
            throw new emptyObj("Sequenza vuota.");
        _activeObj->delElem();
        _view->refreshDisplay();
    } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }
}

void DNAController::saveMemory() {
    try {
        if(!_activeObj || _activeObj->getLength() < 1)
            throw new emptyObj("Nessuna sequenza da salvare!");
        if(_storedObj) {
            bool confirm = _view->confirmOp("Sequenza presente in memoria. Sovrascriverla?", "Procedi", "Annulla");
            if(confirm) {
                delete _storedObj;
                _storedObj = new seqDNA(*_activeObj);
                _view->operationLog("Sovrascrittura avvenuta con successo!");
            }
        }   else {
            _storedObj = new seqDNA(*_activeObj);
            _view->operationLog("Salvataggio avvenuto con successo!");
        }
       } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }    //ECCEZIONE

}

void DNAController::loadMemory()   {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        if(_activeObj->getLength() > 0) {
            bool confirm = _view->confirmOp(QString::fromUtf8("La sequenza attiva verrà automaticamente salvata in memoria. Continuare?"), "Procedi", "Annulla");
            if(confirm) {
                seqDNA* temp = _activeObj;
                setActiveObj(_storedObj);
                setStoredObj(temp);
                _view->operationLog("Salvataggio e caricamento avvenuti con successo!");
             }
        }   else    {
            if(_activeObj)
                delete _activeObj;
            setActiveObj(_storedObj);
            _view->operationLog("Caricamento avvenuto con successo!");
        }
        _view->refreshDisplay();

    } catch(memExc* m) {   _view->operationLog(m->excMessage()); }
}

void DNAController::emptyMemory() {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        delete _storedObj;
        _storedObj = nullptr;
        _view->operationLog("Eliminazione avvenuta con successo!");

    } catch(memExc* m) {_view->operationLog(m->excMessage());}
}

void DNAController::baseOpLen() {
    if(!_activeObj)
        throw new emptyObj("Sequenza vuota.");
    _activeObj->updateInfo();
    QString showLen = "Lunghezza: " + QString::number(_activeObj->getLength());
    _view->operationLog(showLen);
}

void DNAController::baseOpMass() {
    if(!_activeObj)
        throw new emptyObj("Sequenza vuota.");
    _activeObj->updateInfo();
    QString showMass = "Massa: " + QString::number(_activeObj->getMass()) + " " + gencode::massUnit;
    _view->operationLog(showMass);
}

void DNAController::baseOpConcat() {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        else {
            if(!_activeObj)
                _activeObj = new seqDNA;
            seqDNA* _resultSeq = new seqDNA(*(_activeObj->concat(_storedObj)));
            delete _activeObj;
            setActiveObj(_resultSeq);
            _view->refreshDisplay();
        }
    } catch(memExc* m) {_view->operationLog(m->excMessage());}
      catch(typeExc* t) {_view->operationLog(t->excMessage());}
}

void DNAController::baseOpSense()  {
    try {
        if(!_activeObj || _activeObj->getLength()<1)
            throw new emptyObj("Sequenza vuota.");
        if(_activeObj->getIsSense())
            _view->operationLog("Direzione: 5'->3'");
        else
            _view->operationLog("Direzione: 3'->5'");
    } catch(emptyExc*e) {_view->operationLog(e->excMessage());}
}

void DNAController::resetCalc() {
    if(_activeObj)
        delete _activeObj;
    _activeObj = new seqDNA;
    _view->refreshDisplay();
    if(_storedObj)
        if(_view->confirmOp("Eliminare anche la sequenza in memoria?", "Procedi", "Annulla"))
            emptyMemory();
    _view->operationLog("Reset avvenuto con successo!");
}

void DNAController::specOpCalcComp()   {
    try{
        _activeObj->calcSeqComp();
        _view->operationLog("Filamento complementare: " + (_activeObj->getSeqComp())->toString());
    } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }
}

void DNAController::specOpSwitchComp() {
    try {
        _activeObj->toSeqComp();
        _view->operationLog("Scambio avvenuto con successo!");
        _view->refreshDisplay();
    } catch (emptyObj* eo) {_view->operationLog(eo->excMessage());}
      catch (emptyMember *em) {_view->operationLog(em->excMessage());}
      catch (emptyExc *e) {_view->operationLog(e->excMessage());}
}

void DNAController::specOpDelComp() {
    try {
        if(!_activeObj || _activeObj->getLength()<1)
            throw new emptyObj("Sequenza vuota.");
        _activeObj->delSeqComp();
        _view->operationLog("Filameno complementare eliminato con successo!");
    } catch (emptyObj* eo) {_view->operationLog(eo->excMessage());}
      catch (emptyMember *em) {_view->operationLog(em->excMessage());}
      catch (emptyExc *e) {_view->operationLog(e->excMessage());}
}

void DNAController::specOpToRNA() {
    try {
        if(!_activeObj)
            throw new emptyObj("Sequenza vuota.");
        seqRNA* translatedRNA = _activeObj->toRNA();
        _view->getParentTab()->dispatcher()->dispatchObj(translatedRNA, "RNA");
    } catch(emptyExc* e) {_view->operationLog(e->excMessage());}
      catch(widgetNotFound* w) {_view->operationLog(w->excMessage());}
}

DNAController::DNAController(seqDNA*s, DNAQWidget *v) : _activeObj(s), _storedObj(nullptr), _view(v) {
    if(!_view)
        throw new widgetNotFound("DNAController non è stato assegnato ad un DNAWidget.");

    connect(_view->saveButton(), SIGNAL(clicked()), this, SLOT(saveMemory()));
    connect(_view->loadButton(), SIGNAL(clicked()), this, SLOT(loadMemory()));
    connect(_view->emptyButton(), SIGNAL(clicked()), this, SLOT(emptyMemory()));
    connect(_view->resetButton(), SIGNAL(clicked()), this, SLOT(resetCalc()));

    connect(_view->getPrintSense(), SIGNAL(clicked()), this, SLOT(baseOpSense()));
    connect(_view->getCalcLen(), SIGNAL(clicked()), this, SLOT(baseOpLen()));
    connect(_view->getCalcMass(), SIGNAL(clicked()), this, SLOT(baseOpMass()));
    connect(_view->getConcat(), SIGNAL(clicked()), this, SLOT(baseOpConcat()));

    connect(_view->getCalcComp(), SIGNAL(clicked()), this, SLOT(specOpCalcComp()));
    connect(_view->getSwitchComp(), SIGNAL(clicked()), this, SLOT(specOpSwitchComp()));
    connect(_view->getDelComp(), SIGNAL(clicked()), this, SLOT(specOpDelComp()));
    connect(_view->getTrToRNA(), SIGNAL(clicked()), this, SLOT(specOpToRNA()));

    _view->getInputCode()->setMapping(_view->getAddA(), "A");
    _view->getInputCode()->setMapping(_view->getAddT(), "T");
    _view->getInputCode()->setMapping(_view->getAddC(), "C");
    _view->getInputCode()->setMapping(_view->getAddG(), "G");

    connect(_view->getInputCode(), SIGNAL(mapped(QString)), this, SLOT(addElement(QString)));

    connect(_view->getDelEl(), SIGNAL(clicked()), this, SLOT(delElement()));
}

DNAController::~DNAController() {
    if(_activeObj)
        delete _activeObj;
    if(_storedObj)
        delete _storedObj;
}

