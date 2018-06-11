#include "proteinawidget.h"

QGridLayout *ProQWidget::getBaseOpsLayout() const {
    return _baseOpsLayout;
}

void ProQWidget::setBaseOpsLayout(QGridLayout *baseOpsLayout) {
    _baseOpsLayout = baseOpsLayout;
}

QVBoxLayout *ProQWidget::getSpecOpsLayout() const {
    return _specOpsLayout;
}

void ProQWidget::setSpecOpsLayout(QVBoxLayout *specOpsLayout) {
    _specOpsLayout = specOpsLayout;
}

QGridLayout *ProQWidget::getInputOpsLayout() const {
    return _inputOpsLayout;
}

void ProQWidget::setInputOpsLayout(QGridLayout *inputOpsLayout) {
    _inputOpsLayout = inputOpsLayout;
}

QComboBox *ProQWidget::getSelectAmm() const {
    return _selectAmm;
}

void ProQWidget::setSelectAmm(QComboBox *selectAmm) {
    _selectAmm = selectAmm;
}

QPushButton *ProQWidget::getCalcLen() const
{
    return _calcLen;
}

void ProQWidget::setCalcLen(QPushButton *calcLen)
{
    _calcLen = calcLen;
}

QPushButton *ProQWidget::getCalcMass() const
{
    return _calcMass;
}

void ProQWidget::setCalcMass(QPushButton *calcMass)
{
    _calcMass = calcMass;
}

QPushButton *ProQWidget::getCalcVol() const
{
    return _calcVol;
}

void ProQWidget::setCalcVol(QPushButton *calcVol)
{
    _calcVol = calcVol;
}

QPushButton *ProQWidget::getConcat() const
{
    return _concat;
}

void ProQWidget::setConcat(QPushButton *concat)
{
    _concat = concat;
}

QPushButton *ProQWidget::getCalcPercentage() const
{
    return _calcPercentage;
}

void ProQWidget::setCalcPercentage(QPushButton *calcPercentage)
{
    _calcPercentage = calcPercentage;
}

QPushButton *ProQWidget::getCompareToPro() const
{
    return _compareToPro;
}

void ProQWidget::setCompareToPro(QPushButton *compareToPro)
{
    _compareToPro = compareToPro;
}

QPushButton *ProQWidget::getDelEl() const
{
    return _delEl;
}

void ProQWidget::setDelEl(QPushButton *delEl)
{
    _delEl = delEl;
}

QPushButton *ProQWidget::getInsertAmm() const
{
    return _insertAmm;
}

void ProQWidget::setInsertAmm(QPushButton *insertAmm)
{
    _insertAmm = insertAmm;
}

ProQWidget::ProQWidget(PoliQTabWidget *parent) : PoliQWidget(parent) {
    //try {

    if(parent) {

            setParentTab(parent);
            setObjectName("Protein");

            _baseOpsLayout = new QGridLayout(baseOps());
            _baseOpsLayout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
            _baseOpsLayout->setHorizontalSpacing(25);
            _baseOpsLayout->setVerticalSpacing(10);

            _calcLen = new QPushButton("Calcola lunghezza", baseOps());
            _calcLen->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_calcLen, 1, 0);
            _calcMass = new QPushButton("Calcola massa", baseOps());
            _calcMass->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_calcMass, 1, 1);
            _calcVol = new QPushButton("Calcola volume", baseOps());
            _calcVol->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_calcVol, 2, 0);
            _concat = new QPushButton("Concatena", baseOps());
            _concat->setFixedSize(185, 35);
            _baseOpsLayout->addWidget(_concat, 2, 1);

            _specOpsLayout = new QVBoxLayout(specOps());
            _specOpsLayout->setAlignment(Qt::AlignTop|Qt::AlignLeft);
            _specOpsLayout->setSpacing(10);

            _calcPercentage = new QPushButton("Percentuale amminoacido", specOps());
            _calcPercentage->setFixedSize(220, 80);
            _specOpsLayout->addWidget(_calcPercentage);

            _compareToPro = new QPushButton("Compara proteine", specOps());
            _compareToPro->setFixedSize(220, 80);
            _specOpsLayout->addWidget(_compareToPro);

            _inputOpsLayout = new QGridLayout(inputOps());
            _inputOpsLayout->setAlignment(Qt::AlignTop);
            _inputOpsLayout->setHorizontalSpacing(10);
            _inputOpsLayout->setVerticalSpacing(10);

            _selectAmm = new QComboBox(inputOps());
            _selectAmm->setEditable(true);
            _selectAmm->lineEdit()->setReadOnly(true);
            _selectAmm->lineEdit()->setAlignment(Qt::AlignCenter);
            _selectAmm->setFixedSize(170, 35);

            _insertAmm = new QPushButton("Inserisci", inputOps());
            _insertAmm->setFixedSize(170, 35);
            _delEl = new QPushButton(QString::fromUtf8("←\nDel"), inputOps());
            _delEl->setFixedSize(40, 80);

            _inputOpsLayout->addWidget(_selectAmm, 1, 0);
            _inputOpsLayout->addWidget(_insertAmm, 2, 0);
            _inputOpsLayout->addWidget(_delEl, 1, 1);
    }
}
