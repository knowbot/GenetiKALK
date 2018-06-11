#include "poliwidget.h"

//metodi di get/set

QLineEdit *PoliQWidget::display() const {
    return _display;
}

void PoliQWidget::setDisplay(QLineEdit *display) {
    _display = display;
}

QTextBrowser *PoliQWidget::consoleLog() const {
    return _consoleLog;
}

void PoliQWidget::setConsoleLog(QTextBrowser *consoleLog) {
    _consoleLog = consoleLog;
}

QGroupBox *PoliQWidget::baseOps() const {
    return _baseOps;
}

void PoliQWidget::setBaseOps(QGroupBox *baseOps) {
    _baseOps = baseOps;
}

QGroupBox *PoliQWidget::specOps() const {
    return _specOps;
}

void PoliQWidget::setSpecOps(QGroupBox *specOps) {
    _specOps = specOps;
}


QGroupBox *PoliQWidget::inputOps() const {
    return _inputOps;
}

void PoliQWidget::setInputOps(QGroupBox *inputOps) {
    _inputOps = inputOps;
}

QGroupBox *PoliQWidget::memOps() const {
    return _memOps;
}

void PoliQWidget::setmemOps(QGroupBox *memOps) {
    _memOps = memOps;
}

QHBoxLayout *PoliQWidget::memOpsLayout() const {
    return _memOpsLayout;
}

void PoliQWidget::setmemOpsLayout(QHBoxLayout *memOpsLayout) {
    _memOpsLayout = memOpsLayout;
}

QPushButton *PoliQWidget::resetButton() const {
    return _resetButton;
}

void PoliQWidget::setResetButton(QPushButton *resetButton) {
    _resetButton = resetButton;
}

QPushButton *PoliQWidget::clearButton() const {
    return _clearButton;
}

void PoliQWidget::setClearButton(QPushButton *clearButton) {
    _clearButton = clearButton;
}

QPushButton *PoliQWidget::saveButton() const {
    return _saveButton;
}

void PoliQWidget::setSaveButton(QPushButton *saveButton) {
    _saveButton = saveButton;
}

QPushButton *PoliQWidget::loadButton() const {
    return _loadButton;
}

void PoliQWidget::setLoadButton(QPushButton *loadButton) {
    _loadButton = loadButton;
}

QPushButton *PoliQWidget::emptyButton() const {
    return _emptyButton;
}

void PoliQWidget::setEmptyButton(QPushButton *emptyButton) {
    _emptyButton = emptyButton;
}

//slots
void PoliQWidget::clearLog() {
    _consoleLog->clear();
}

//metodi
void PoliQWidget::operationLog(const QString &newLog) {
    _consoleLog->append(newLog);
}

bool PoliQWidget::confirmOp(const QString &operationText, const QString &acceptText, const QString &rejectText) const {
    QMessageBox* _confirm = new QMessageBox(QMessageBox::Question, "Conferma operazione", operationText);
    _confirm->setAttribute(Qt::WA_DeleteOnClose);
    QPushButton* _accept = new QPushButton(acceptText);
    _confirm->addButton(_accept, QMessageBox::AcceptRole);
    QPushButton* _reject = new QPushButton(rejectText);
    _confirm->addButton(_reject, QMessageBox::RejectRole);
    return _confirm->exec() == QDialog::Accepted;
}

PoliQTabWidget *PoliQWidget::getParentTab() const
{
    return _parentTab;
}

void PoliQWidget::setParentTab(PoliQTabWidget *value)
{
    _parentTab = value;
}

poliController *PoliQWidget::getController() const
{
    return _controller;
}

void PoliQWidget::setController(poliController *controller)
{
    _controller = controller;
}

void PoliQWidget::refreshDisplay() {
    display()->setText(getController()->activeObj()->toString());
}

PoliQWidget::PoliQWidget(PoliQTabWidget* parent) : QWidget(parent) {
    //try {
    if(parent) {
        _display = new QLineEdit(this);
        _display->setObjectName("Display");
        _display->setReadOnly(true);
        _display->move(20, 20);
        _display->setFixedSize(550, 60);
        _display->setFont(QFont("Ubuntu", 26));
        _display->setStyleSheet("background-color:black; color:white;");
        _display->setTextMargins(5,0,5,0);

        _consoleLog = new QTextBrowser(this);
        _consoleLog->setObjectName("ConsoleLog");
        _consoleLog->move(20, 210);
        _consoleLog->setFixedSize(390, 145);
        _consoleLog->append(QString("Benvenuto in GenetiKALK!"));

        _baseOps = new QGroupBox(this);
        _baseOps->setObjectName("BaseOperations");
        _baseOps->setTitle("Operazioni base");
        _baseOps->move(20, 90);
        _baseOps->setFixedSize(390, 110);
        _baseOps->setContentsMargins(-10, 15, 0, 0);
        _baseOps->setFlat(true);

        _specOps = new QGroupBox(this);
        _specOps->setObjectName("SpecialOperations");
        _specOps->setTitle("Operazioni speciali");
        _specOps->move(430, 205);
        _specOps->setFixedSize(220, 250);
        _specOps->setContentsMargins(-10, 15, -10, 0);
        _specOps->setFlat(true);

        _inputOps = new QGroupBox(this);
        _inputOps->setTitle("Input");
        _inputOps->setObjectName("InputOperations");
        _inputOps->move(430, 90);
        _inputOps->setFixedSize(220, 110);
        _inputOps->setContentsMargins(-10, 15, -10, 0);
        _inputOps->setFlat(true);

        _memOps = new QGroupBox(this);
        _memOps->setObjectName("MemoryOperations");
        _memOps->move(100, 364);
        _memOps->setFixedSize(310, 35);
        _memOps->setContentsMargins(0, 0, 0, 0);
        _memOps->setFlat(true);

        _memOpsLayout = new QHBoxLayout(_memOps);
        _memOpsLayout->setObjectName("MemOpsLayout");
        _memOpsLayout->setAlignment(Qt::AlignTop);
        _memOpsLayout->setSpacing(13);
        _memOpsLayout->setContentsMargins(0, 0, 0, 0);

        _saveButton = new QPushButton("Salva", _memOps);
        _saveButton->setObjectName("saveMemButton");
        _saveButton->setFixedSize(95, 35);
        _memOpsLayout->addWidget(_saveButton);
        _loadButton = new QPushButton("Carica", _memOps);
        _loadButton->setObjectName("loadMemButton");
        _loadButton->setFixedSize(95, 35);
        _memOpsLayout->addWidget(_loadButton);
        _emptyButton = new QPushButton("Svuota", _memOps);
        _emptyButton->setObjectName("emptyMemButton");
        _emptyButton->setFixedSize(95, 35);
        _memOpsLayout->addWidget(_emptyButton);

        _resetButton = new QPushButton("RST", this);
        _resetButton->setFixedSize(60, 60);
        _resetButton->move(590, 20);

        _clearButton = new QPushButton("Clear", this);
        _clearButton->setFixedSize(67, 35);
        _clearButton->move(20, 364);

        connect(_clearButton, SIGNAL(clicked()), this, SLOT(clearLog()));
    }   else
        throw new widgetNotFound("PoliQWidget non assegnato ad un PoliQTabWidget.");
    //}
}

PoliQWidget::~PoliQWidget() {
    if(_controller)
        delete _controller;
}

