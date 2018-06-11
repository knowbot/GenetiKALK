#include "dnawidget.h"

//metodi di get/set

QSignalMapper *DNAQWidget::getInputCode() const {
    return _inputCode;
}

void DNAQWidget::setInputCode(QSignalMapper *inputCode) {
    _inputCode = inputCode;
}


QGridLayout *DNAQWidget::getBaseOpsLayout() const {
    return _baseOpsLayout;
}

void DNAQWidget::setBaseOpsLayout(QGridLayout *baseOpsLayout) {
    _baseOpsLayout = baseOpsLayout;
}

QGridLayout *DNAQWidget::getInputOpsLayout() const {
    return _inputOpsLayout;
}

void DNAQWidget::setInputOpsLayout(QGridLayout *inputOpsLayout) {
    _inputOpsLayout = inputOpsLayout;
}

QPushButton *DNAQWidget::getPrintSense() const
{
    return _printSense;
}

void DNAQWidget::setPrintSense(QPushButton *printSense)
{
    _printSense = printSense;
}

QPushButton *DNAQWidget::getCalcLen() const
{
    return _calcLen;
}

void DNAQWidget::setCalcLen(QPushButton *calcLen)
{
    _calcLen = calcLen;
}

QPushButton *DNAQWidget::getCalcMass() const
{
    return _calcMass;
}

void DNAQWidget::setCalcMass(QPushButton *calcMass)
{
    _calcMass = calcMass;
}

QPushButton *DNAQWidget::getConcat() const
{
    return _concat;
}

void DNAQWidget::setConcat(QPushButton *concat)
{
    _concat = concat;
}

QPushButton *DNAQWidget::getCalcComp() const
{
    return _calcComp;
}

void DNAQWidget::setCalcComp(QPushButton *calcComp)
{
    _calcComp = calcComp;
}

QPushButton *DNAQWidget::getSwitchComp() const
{
    return _switchComp;
}

void DNAQWidget::setSwitchComp(QPushButton *switchComp)
{
    _switchComp = switchComp;
}

QPushButton *DNAQWidget::getDelComp() const
{
    return _delComp;
}

void DNAQWidget::setDelComp(QPushButton *delComp)
{
    _delComp = delComp;
}

QPushButton *DNAQWidget::getTrToRNA() const
{
    return _trToRNA;
}

void DNAQWidget::setTrToRNA(QPushButton *trToRNA)
{
    _trToRNA = trToRNA;
}

QPushButton *DNAQWidget::getAddA() const
{
    return _addA;
}

void DNAQWidget::setAddA(QPushButton *addA)
{
    _addA = addA;
}

QPushButton *DNAQWidget::getAddT() const
{
    return _addT;
}

void DNAQWidget::setAddT(QPushButton *addT)
{
    _addT = addT;
}

QPushButton *DNAQWidget::getAddC() const
{
    return _addC;
}

void DNAQWidget::setAddC(QPushButton *addC)
{
    _addC = addC;
}

QPushButton *DNAQWidget::getAddG() const
{
    return _addG;
}

void DNAQWidget::setAddG(QPushButton *addG)
{
    _addG = addG;
}

QPushButton *DNAQWidget::getDelEl() const
{
    return _delEl;
}

void DNAQWidget::setDelEl(QPushButton *delEl)
{
    _delEl = delEl;
}


DNAQWidget::DNAQWidget(PoliQTabWidget* parent) : PoliQWidget(parent) {
    //try {

    if(parent) {

            setParentTab(parent);

             setObjectName("DNA");

            _baseOpsLayout = new QGridLayout(baseOps());
            _baseOpsLayout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
            _baseOpsLayout->setHorizontalSpacing(25);
            _baseOpsLayout->setVerticalSpacing(10);

            _printSense = new QPushButton("Stampa direzione", baseOps());
            _printSense->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_printSense, 1, 0);
             _calcLen = new QPushButton("Calcola lunghezza", baseOps());
            _calcLen->setFixedSize(185, 35);           
            _baseOpsLayout->addWidget(_calcLen, 1, 1);
             _calcMass = new QPushButton("Calcola massa", baseOps());
            _calcMass->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_calcMass, 2, 0);
             _concat = new QPushButton("Concatena", baseOps());
            _concat->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_concat, 2, 1);

            _specOpsLayout = new QVBoxLayout(specOps());
            _specOpsLayout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
            _specOpsLayout->setSpacing(10);

             _calcComp = new QPushButton("Calcola complementare", specOps());
            _calcComp->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_calcComp);
             _switchComp = new QPushButton("Scambia con complementare", specOps());
            _switchComp->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_switchComp);
             _delComp = new QPushButton("Elimina complementare", specOps());
            _delComp->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_delComp);
             _trToRNA = new QPushButton("Traduci in RNA", specOps());
            _trToRNA->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_trToRNA);

            _inputOpsLayout = new QGridLayout(inputOps());
            _inputOpsLayout->setAlignment(Qt::AlignTop);
            _inputOpsLayout->setHorizontalSpacing(10);
            _inputOpsLayout->setVerticalSpacing(10);

            _inputCode = new QSignalMapper;

             _addA = new QPushButton("A", inputOps());
            _addA->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addA, 1, 0);
             _addT = new QPushButton("T", inputOps());
            _addT->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addT, 1, 1);
             _addC = new QPushButton("C", inputOps());
            _addC->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addC, 2, 0);
             _addG = new QPushButton("G", inputOps());
            _addG->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addG, 2, 1);

            connect(_addA, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addT, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addC, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addG, SIGNAL(clicked()), _inputCode, SLOT(map()));

             _delEl = new QPushButton(QString::fromUtf8("←\nDel"), inputOps());
            _delEl->setFixedSize(40, 80);
            _inputOpsLayout->addWidget(_delEl, 1, 3);
    }
}

DNAQWidget::~DNAQWidget() {
}
