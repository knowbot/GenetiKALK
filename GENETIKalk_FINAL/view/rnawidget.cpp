#include "rnawidget.h"

//metodi di get/set
QSignalMapper *RNAQWidget::getInputCode() const {
    return _inputCode;
}

void RNAQWidget::setInputCode(QSignalMapper *inputCode) {
    _inputCode = inputCode;
}

QGridLayout *RNAQWidget::getBaseOpsLayout() const {
    return _baseOpsLayout;
}

void RNAQWidget::setBaseOpsLayout(QGridLayout *baseOpsLayout) {
    _baseOpsLayout = baseOpsLayout;
}

QGridLayout *RNAQWidget::getInputOpsLayout() const {
    return _inputOpsLayout;
}

void RNAQWidget::setInputOpsLayout(QGridLayout *inputOpsLayout) {
    _inputOpsLayout = inputOpsLayout;
}

QPushButton *RNAQWidget::getPrintSense() const
{
    return _printSense;
}

void RNAQWidget::setPrintSense(QPushButton *printSense)
{
    _printSense = printSense;
}

QPushButton *RNAQWidget::getCalcLen() const
{
    return _calcLen;
}

void RNAQWidget::setCalcLen(QPushButton *calcLen)
{
    _calcLen = calcLen;
}

QPushButton *RNAQWidget::getCalcMass() const
{
    return _calcMass;
}

void RNAQWidget::setCalcMass(QPushButton *calcMass)
{
    _calcMass = calcMass;
}

QPushButton *RNAQWidget::getConcat() const
{
    return _concat;
}

void RNAQWidget::setConcat(QPushButton *concat)
{
    _concat = concat;
}

QPushButton *RNAQWidget::getSplicing() const
{
    return _splicing;
}

void RNAQWidget::setSplicing(QPushButton *splicing)
{
    _splicing = splicing;
}

QPushButton *RNAQWidget::getFindAmm() const
{
    return _findAmm;
}

void RNAQWidget::setFindAmm(QPushButton *findAmm)
{
    _findAmm = findAmm;
}

QPushButton *RNAQWidget::getTrToDNA() const
{
    return _trToDNA;
}

void RNAQWidget::setTrToDNA(QPushButton *trToDNA)
{
    _trToDNA = trToDNA;
}

QPushButton *RNAQWidget::getTrToPro() const
{
    return _trToPro;
}

void RNAQWidget::setTrToPro(QPushButton *trToPro)
{
    _trToPro = trToPro;
}

QPushButton *RNAQWidget::getAddA() const
{
    return _addA;
}

void RNAQWidget::setAddA(QPushButton *addA)
{
    _addA = addA;
}

QPushButton *RNAQWidget::getAddU() const
{
    return _addU;
}

void RNAQWidget::setAddU(QPushButton *addU)
{
    _addU = addU;
}

QPushButton *RNAQWidget::getAddC() const
{
    return _addC;
}

void RNAQWidget::setAddC(QPushButton *addC)
{
    _addC = addC;
}

QPushButton *RNAQWidget::getAddG() const
{
    return _addG;
}

void RNAQWidget::setAddG(QPushButton *addG)
{
    _addG = addG;
}

QPushButton *RNAQWidget::getDelEl() const
{
    return _delEl;
}

void RNAQWidget::setDelEl(QPushButton *delEl)
{
    _delEl = delEl;
}

QString RNAQWidget::chooseAmmDialog() const {
    QString _amm;
    QInputDialog* _chooseAmm = new QInputDialog();
    _chooseAmm->setAttribute(Qt::WA_DeleteOnClose);
    QStringList _aminoacids;
    for(auto i : gencode::proCode)
        _aminoacids << i.getAcr();
    _chooseAmm->setComboBoxItems(_aminoacids);
    _chooseAmm->setWindowTitle("Scegli amminoacido");
    _chooseAmm->setLabelText("Scegli l'amminoacido da trovare:");
    connect(_chooseAmm, &QInputDialog::textValueSelected, [&_amm](QString text) { _amm = text; });
    if(_chooseAmm->exec()!=QDialog::Accepted)
        throw new abortOp("");
    return _amm;
}

RNAQWidget::RNAQWidget(PoliQTabWidget *parent) : PoliQWidget(parent) {
    //try {

    if(parent) {

            setParentTab(parent);

            setObjectName("RNA");

            _inputCode = new QSignalMapper;

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

            _splicing = new QPushButton("Splicing", specOps());
            _splicing->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_splicing);
            _findAmm = new QPushButton("Trova amminoacido", specOps());
            _findAmm->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_findAmm);
            _trToDNA = new QPushButton("Traduci in DNA", specOps());
            _trToDNA->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_trToDNA);
            _trToPro = new QPushButton("Traduci in proteina", specOps());
            _trToPro->setFixedSize(220, 35);
            _specOpsLayout->addWidget(_trToPro);

            _inputOpsLayout = new QGridLayout(inputOps());
            _inputOpsLayout->setAlignment(Qt::AlignTop);
            _inputOpsLayout->setHorizontalSpacing(10);
            _inputOpsLayout->setVerticalSpacing(10);

            _addA = new QPushButton("A", inputOps());
            _addA->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addA, 1, 0);
            _addU = new QPushButton("U", inputOps());
            _addU->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addU, 1, 1);
            _addC = new QPushButton("C", inputOps());
            _addC->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addC, 2, 0);
            _addG = new QPushButton("G", inputOps());
            _addG->setFixedSize(80, 35);
            _inputOpsLayout->addWidget(_addG, 2, 1);

            connect(_addA, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addU, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addC, SIGNAL(clicked()), _inputCode, SLOT(map()));
            connect(_addG, SIGNAL(clicked()), _inputCode, SLOT(map()));

            _delEl = new QPushButton(QString::fromUtf8("←\nDel"), inputOps());
            _delEl->setFixedSize(40, 80);
            _inputOpsLayout->addWidget(_delEl, 1, 3);
    }
}

RNAQWidget::~RNAQWidget() {

}
