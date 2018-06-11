#include "rnacontroller.h"

seqRNA *RNAController::activeObj() const {
    return _activeObj;
}

void RNAController::setActiveObj(seqRNA *activeSeq) {
    _activeObj = activeSeq;
}

seqRNA *RNAController::storedObj() const {
    return _storedObj;
}

void RNAController::setStoredObj(seqRNA *storedSeq) {
    _storedObj = storedSeq;
}

RNAQWidget *RNAController::view() const {
    return _view;
}

void RNAController::setView(RNAQWidget *view) {
    _view = view;
}


//METODI
void RNAController::receiveObj(IPolimero *newObj) {
    try {
    seqRNA* newActive = dynamic_cast<seqRNA*>(newObj);
        if(!newActive)
            throw new typeIsIncompatible("Sequenza ricevuta di tipo incompatibile.");
        if(_activeObj && _activeObj->getLength() > 0) {
            bool confirm = _view->confirmOp("Esiste una sequenza attiva. Sovrascriverla?", "Procedi", "Annulla");
            if(confirm) {
                delete _activeObj;
                setActiveObj(dynamic_cast<seqRNA*>(newObj));
             }
        }   else    {
            if(_activeObj)
                delete _activeObj;
            setActiveObj(dynamic_cast<seqRNA*>(newObj));
        }
        _view->operationLog("Sequenza ricevuta con successo!");
        _view->refreshDisplay();
    } catch(typeExc* t) {_view->operationLog(t->excMessage());}
}

//SLOTS
void RNAController::addElement(const QString& newEl) {
    try {
        bool found = false;
        for(auto i = gencode::rnaCode.begin(); i != gencode::rnaCode.end() && !found; ++i)
            if (i->getAcr() == newEl) {
                _activeObj->addElem(*i);
                found = true;
            }
        if(!found) //LANCIA_ECCEZIONE
            _view->operationLog("Input invalido");
        _view->refreshDisplay();
    } catch(notFoundExc* f) { _view->operationLog(f->excMessage()); }
}

void RNAController::delElement() {
    try {
        if(!_activeObj)
            throw new emptyObj("Sequenza vuota.");
        _activeObj->delElem();
        _view->refreshDisplay();
    } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }
}

void RNAController::saveMemory() {
    try {
        if(!_activeObj || _activeObj->getLength() < 1)
            throw new emptyObj("Nessuna sequenza da salvare!");
        if(_storedObj) {
            bool confirm = _view->confirmOp("Sequenza presente in memoria. Sovrascriverla?", "Procedi", "Annulla");
            if(confirm) {
                delete _storedObj;
                _storedObj = new seqRNA(*_activeObj);
                _view->operationLog("Sovrascrittura avvenuta con successo!");
            }
        }   else {
            _storedObj = new seqRNA(*_activeObj);
            _view->operationLog("Salvataggio avvenuto con successo!");
        }
       } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }    //ECCEZIONE

}

void RNAController::loadMemory()   {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        if(_activeObj->getLength() > 0) {
            bool confirm = _view->confirmOp(QString::fromUtf8("La sequenza attiva verrà automaticamente salvata in memoria. Continuare?"), "Procedi", "Annulla");
            if(confirm) {
                seqRNA* temp = _activeObj;
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

void RNAController::emptyMemory() {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        delete _storedObj;
        _storedObj = nullptr;
        _view->operationLog("Eliminazione avvenuta con successo!");

    } catch(memExc* m) {_view->operationLog(m->excMessage());}
}

void RNAController::baseOpLen() {
    if(!_activeObj)
        throw new emptyObj("Sequenza vuota.");
    _activeObj->updateInfo();
    QString showLen = "Lunghezza: " + QString::number(_activeObj->getLength());
    _view->operationLog(showLen);
}

void RNAController::baseOpMass() {
    if(!_activeObj)
        throw new emptyObj("Sequenza vuota.");
    _activeObj->updateInfo();
    QString showMass = "Massa: " + QString::number(_activeObj->getMass()) + " " + gencode::massUnit;
    _view->operationLog(showMass);
}

void RNAController::baseOpConcat() {
    try {
        if(!_storedObj)
            throw new memIsEmpty("Nessuna sequenza salvata in memoria!");
        else {
            if(!_activeObj)
                _activeObj = new seqRNA;
            seqRNA* _resultSeq = new seqRNA(*(_activeObj->concat(_storedObj)));
            delete _activeObj;
            setActiveObj(_resultSeq);
            _view->refreshDisplay();
        }
    } catch(memExc* m) {_view->operationLog(m->excMessage());}
      catch(typeExc* t) {_view->operationLog(t->excMessage());}
}

void RNAController::baseOpSense()  {
    try {
        if(!_activeObj || _activeObj->getLength()<1)
            throw new emptyObj("Sequenza vuota.");
        if(_activeObj->getIsSense())
            _view->operationLog("Direzione: 5'->3'");
        else
            _view->operationLog("Direzione: 3'->5'");
    } catch(emptyExc*e) {_view->operationLog(e->excMessage());}
}

void RNAController::resetCalc() {
    if(_activeObj)
        delete _activeObj;
    _activeObj = new seqRNA;
    _view->refreshDisplay();
    if(_storedObj)
        if(_view->confirmOp("Eliminare anche la sequenza in memoria?", "Procedi", "Annulla"))
            emptyMemory();
    _view->operationLog("Reset avvenuto con successo!");
}

void RNAController::specOpSplicing() {
   try{
           //eccezione
       unsigned int index1, index2;
       bool ok;
       index1= QInputDialog::getInt(_view, "Inizio taglio", "Inserisci la posizione in cui iniziare il taglio", 1, 0, _activeObj->getLength()-1, 1, &ok);
       if(ok) {
           index2 = QInputDialog::getInt(_view, "Fine taglio", "Inserisci la posizione in cui finire il taglio", 1, 0, _activeObj->getLength(), 1, &ok);
           _activeObj->splicing(index1, index2);
           _view->refreshDisplay();
       }
    }  catch(emptyExc*e) {_view->operationLog(e->excMessage());}
       catch(outOfBounds*o) {_view->operationLog(o->excMessage());}
}

void RNAController::specOpFindAmm() {
    try {
        int _ammPos;
        QString _amm = _view->chooseAmmDialog(), _ammName;
        bool valid = false;
        for(auto i = gencode::proCode.begin(); i!= gencode::proCode.end() && !valid; ++i)
            if(i->getAcr() == _amm) {
                _ammPos = i->findInSequence(_activeObj->getElems());
                _ammName = i->getName();
                valid = true;
        }
        if(!valid)
            throw new objectNotFound("Amminoacido non valido");
        if(!_ammPos)
            _view->operationLog("Amminoacido non presente");
        else {
        _view->display()->setSelection(_ammPos-1, 3);
        _view->operationLog("Amminoacido " + _ammName + " trovato in posizione: " + QString::number(_ammPos));
        }
    } catch(emptyExc *e) {_view->operationLog(e->excMessage());}
      catch(notFoundExc *e) {_view->operationLog(e->excMessage());}
      catch(abortOp *a) {}
}

void RNAController::specOpsToDNA() {
    try {
        if(!_activeObj)
            throw new emptyObj("Sequenza vuota.");
        seqDNA* translatedDNA = _activeObj->toDNA();
        _view->getParentTab()->dispatcher()->dispatchObj(translatedDNA, "DNA");
    } catch(emptyExc* e) {_view->operationLog(e->excMessage());}
      catch(widgetNotFound* w) {_view->operationLog(w->excMessage());}
}

void RNAController::specOpsToPro() {
    try {
        if(!_activeObj)
            throw new emptyObj("Sequenza vuota.");
        Proteina* translatedPro = _activeObj->toProtein();
        _view->getParentTab()->dispatcher()->dispatchObj(translatedPro, "Protein");
    } catch(emptyExc* e) {_view->operationLog(e->excMessage());}
      catch(widgetNotFound* w) {_view->operationLog(w->excMessage());}
}

RNAController::RNAController(seqRNA*s, RNAQWidget *v) : _activeObj(s), _storedObj(nullptr), _view(v) {
    if(!_view)
        throw new widgetNotFound("RNAController non è stato assegnato ad un RNAWidget.");

    connect(_view->saveButton(), SIGNAL(clicked()), this, SLOT(saveMemory()));
    connect(_view->loadButton(), SIGNAL(clicked()), this, SLOT(loadMemory()));
    connect(_view->emptyButton(), SIGNAL(clicked()), this, SLOT(emptyMemory()));
    connect(_view->resetButton(), SIGNAL(clicked()), this, SLOT(resetCalc()));

    connect(_view->getPrintSense(), SIGNAL(clicked()), this, SLOT(baseOpSense()));
    connect(_view->getCalcLen(), SIGNAL(clicked()), this, SLOT(baseOpLen()));
    connect(_view->getCalcMass(), SIGNAL(clicked()), this, SLOT(baseOpMass()));
    connect(_view->getConcat(), SIGNAL(clicked()), this, SLOT(baseOpConcat()));

    connect(_view->getSplicing(), SIGNAL(clicked()), this, SLOT(specOpSplicing()));
    connect(_view->getFindAmm(), SIGNAL(clicked()), this, SLOT(specOpFindAmm()));

    connect(_view->getTrToDNA(), SIGNAL(clicked()), this, SLOT(specOpsToDNA()));
    connect(_view->getTrToPro(), SIGNAL(clicked()), this, SLOT(specOpsToPro()));

    _view->getInputCode()->setMapping(_view->getAddA(), "A");
    _view->getInputCode()->setMapping(_view->getAddU(), "U");
    _view->getInputCode()->setMapping(_view->getAddC(), "C");
    _view->getInputCode()->setMapping(_view->getAddG(), "G");

    connect(_view->getInputCode(), SIGNAL(mapped(QString)), this, SLOT(addElement(QString)));

    connect(_view->getDelEl(), SIGNAL(clicked()), this, SLOT(delElement()));
}

RNAController::~RNAController() {
    if(_activeObj)
        delete _activeObj;
    if(_storedObj)
        delete _storedObj;
}
