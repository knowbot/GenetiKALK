#include "procontroller.h"

Proteina *ProController::activeObj() const {
    return _activeObj;
}

void ProController::setActiveObj(Proteina *activeObj) {
    _activeObj = activeObj;
}

Proteina *ProController::storedObj() const {
    return _storedObj;
}

void ProController::setStoredObj(Proteina *storedSeq) {
    _storedObj = storedSeq;
}

ProQWidget *ProController::view() const {
    return _view;
}

void ProController::setView(ProQWidget *view) {
    _view = view;
}

//METODI
void ProController::receiveObj(IPolimero *newObj) {
    try {
        Proteina* newActive = dynamic_cast<Proteina*>(newObj);
        if(!newActive)
            throw new typeIsIncompatible("Proteina ricevuta di tipo incompatibile.");
        if(_activeObj && _activeObj->getLength() > 0) {
                bool confirm = _view->confirmOp("Esiste una Proteina attiva. Sovrascriverla?", "Procedi", "Annulla");
                if(confirm) {
                    delete _activeObj;
                    setActiveObj(dynamic_cast<Proteina*>(newObj));
                 }
            }   else    {
                if(_activeObj)
                    delete _activeObj;
                setActiveObj(dynamic_cast<Proteina*>(newObj));
            }
            _view->operationLog("Proteina ricevuta con successo!");
            _view->refreshDisplay();
   } catch(typeExc* t) {_view->operationLog(t->excMessage());}

}

//SLOTS
void ProController::addElement() {
    try {
        if(!_activeObj)
            _activeObj = new Proteina;
        bool found = false;
        for(auto i = gencode::proCode.begin(); i != gencode::proCode.end() && !found; ++i)
            if (_view->getSelectAmm()->currentData().toString() == i->getAcr()) {
                _activeObj->addElem(*i);
                found = true;
            }
        if(!found)
            throw new objectNotFound("Amminoacido invalido.");
        _view->refreshDisplay();
    } catch(notFoundExc* f) { _view->operationLog(f->excMessage()); }
}

void ProController::delElement() {
    try{
        if(!_activeObj)
            throw new emptyObj("Proteina vuota.");
        _activeObj->delElem();
        _view->refreshDisplay();
    } catch(emptyExc* e) { _view->operationLog(e->excMessage()); }
}

void ProController::saveMemory() {
    if(_activeObj->getLength() > 0)
        if(_storedObj) {
            bool confirm = _view->confirmOp("Proteina presente in memoria. Sovrascriverla?", "Procedi", "Annulla");
            if(confirm) {
                delete _storedObj;
                _storedObj = new Proteina(*_activeObj);
                _view->operationLog("Sovrascrittura avvenuta con successo!");
            }
        }   else {
            _storedObj = new Proteina(*_activeObj);
            _view->operationLog("Salvataggio avvenuto con successo!");
        }
    else
       _view->operationLog("Nessuna Proteina da salvare!");    //ECCEZIONE

}

void ProController::loadMemory()   {
    if(_storedObj) {
        if(_activeObj->getLength() > 0) {
            bool confirm = _view->confirmOp(QString::fromUtf8("La Proteina attiva verrà automaticamente salvata in memoria. Continuare?"), "Procedi", "Annulla");
            if(confirm) {
                Proteina* temp = _activeObj;
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
    } else
        _view->operationLog("Nessuna Proteina salvata in memoria!");
    //ECCEZIONE EMPTYMEM!!!
    _view->refreshDisplay();
}

void ProController::emptyMemory() {
    if(_storedObj) {
            delete _storedObj;
            _storedObj = nullptr;
            _view->operationLog("Eliminazione avvenuta con successo!");
        //}
    }   else
        _view->operationLog("Nessuna Proteina salvata in memoria!");
}

void ProController::baseOpLen() {
    _activeObj->updateInfo();
    QString showLen = "Lunghezza: " + QString::number(_activeObj->getLength());
    _view->operationLog(showLen);
}

void ProController::baseOpMass() {
    _activeObj->updateInfo();
    QString showMass = "Massa: " + QString::number(_activeObj->getMass()) + gencode::massUnit;
    _view->operationLog(showMass);
}

void ProController::baseOpConcat() {
    if(!_storedObj)
        _view->operationLog("Nessuna Proteina salvata in memoria!"); //ECCEZIONE EMPTYMEM
    else {
        Proteina* _resultSeq = new Proteina(*(_activeObj->concat(_storedObj)));
        delete _activeObj;
        setActiveObj(_resultSeq);
        _view->refreshDisplay();
    }
}

void ProController::baseOpVol() {
    _activeObj->updateInfo();
    QString showVol = "Volume: " + QString::number(_activeObj->getVolume()) + QString::fromUtf8(" Å^3");
    _view->operationLog(showVol);
}

void ProController::resetCalc() {
    delete _activeObj;
    _activeObj = new Proteina;
    _view->refreshDisplay();
    if(_storedObj)
        if(_view->confirmOp("Eliminare anche la Proteina in memoria?", "Procedi", "Annulla"))
            emptyMemory();
    _view->operationLog("Reset avvenuto con successo!");
}

void ProController::specOpPercentage()   {
    try {
        if(!_activeObj || _activeObj->getLength()<1)
           throw new emptyObj("Proteina vuota.");
        double percent = 0;
        bool found = false;
        for(auto i = gencode::proCode.begin(); i != gencode::proCode.end() && !found; ++i)
            if (_view->getSelectAmm()->currentData().toString() == i->getAcr()) {
                found = true;
                percent = i->calcPercentage(_activeObj->getElems());
                _view->operationLog("L'amminoacido " + i->getName() + " costituisce il " + QString::number(percent) + "% della proteina.");
            }
        if(!found)
            throw new objectNotFound("L'amminoacido non è presente");
    }
    catch (emptyExc* e) {_view->operationLog(e->excMessage());}
    catch (notFoundExc* n) {_view->operationLog(n->excMessage());}
    //ECCEZIONE
}

void ProController::specOpCompare() {
    try {
        if(!_storedObj)
        throw new emptyObj("Nessuna proteina é salvata in memoria!");
        if(_activeObj->isSimilar(*_storedObj))
            _view->operationLog("Le proteine appartengono alla stessa famiglia.");
        else
            _view->operationLog("Le proteine appartengono a famiglie differenti.");
   } catch (emptyExc* e) {_view->operationLog(e->excMessage());}
}

ProController::ProController(Proteina*s, ProQWidget *v) : _activeObj(s), _storedObj(nullptr), _view(v) {
    if(!_view)
        throw new widgetNotFound("ProController non è stato assegnato ad un ProWidget.");
    for(auto i : gencode::proCode)
       _view->getSelectAmm()->addItem(i.getName(), i.getAcr());

    connect(_view->saveButton(), SIGNAL(clicked()), this, SLOT(saveMemory()));
    connect(_view->loadButton(), SIGNAL(clicked()), this, SLOT(loadMemory()));
    connect(_view->emptyButton(), SIGNAL(clicked()), this, SLOT(emptyMemory()));
    connect(_view->resetButton(), SIGNAL(clicked()), this, SLOT(resetCalc()));

    connect(_view->getCalcLen(), SIGNAL(clicked()), this, SLOT(baseOpLen()));
    connect(_view->getCalcMass(), SIGNAL(clicked()), this, SLOT(baseOpMass()));
    connect(_view->getCalcVol(), SIGNAL(clicked()), this, SLOT(baseOpVol()));
    connect(_view->getConcat(), SIGNAL(clicked()), this, SLOT(baseOpConcat()));

    connect(_view->getCalcPercentage(), SIGNAL(clicked()), this, SLOT(specOpPercentage()));
    connect(_view->getCompareToPro(), SIGNAL(clicked()), this, SLOT(specOpCompare()));

    connect(_view->getInsertAmm(), SIGNAL(clicked()), this, SLOT(addElement()));

    connect(_view->getDelEl(), SIGNAL(clicked()), this, SLOT(delElement()));
}

ProController::~ProController() {
    if(_activeObj)
        delete _activeObj;
    if(_storedObj)
        delete _storedObj;
}

