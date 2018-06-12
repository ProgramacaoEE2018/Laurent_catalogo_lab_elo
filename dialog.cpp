#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QDir myPath("C:/Users/Laurent/");
    myPath.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    mylist = myPath.entryList();
    ui->listWidget->addItems(mylist);
    ui->labeltotal->setText(QString("%1").arg(ui->listWidget->count()));
    ui->listWidget->addItem("Capacitor          mica                Gaveteiro 1 Gaveta 1");
    ui->listWidget->addItem("Capacitor          ceramica            Gaveteiro 1 Gaveta 2");
    ui->listWidget->addItem("Capacitor          poliester           Gaveteiro 1 Gaveta 1");
    ui->listWidget->addItem("Capacitor          eletrolitico        Gaveteiro 1 Gaveta 4");
    ui->listWidget->addItem("Indutor            microchoque         Gaveteiro 1 Gaveta 5");
    ui->listWidget->addItem("Resistor           fixo                Gaveteiro 2 Gaveta 1");
    ui->listWidget->addItem("Resistor           fixo                Gaveteiro 2 Gaveta 2");
    ui->listWidget->addItem("Resistor           trimpot             Gaveteiro 2 Gaveta 3");
    ui->listWidget->addItem("Transistor         TBJ PNP             Gaveteiro 2 Gaveta 4");
    ui->listWidget->addItem("Transistor         TBJ NPN             Gaveteiro 2 Gaveta 4");
    ui->listWidget->addItem("Diodo              comum               Gaveteiro 2 Gaveta 5");
    ui->listWidget->addItem("Diodo              zener               Gaveteiro 2 Gaveta 5");
    ui->listWidget->addItem("Diodo              LED                 Gaveteiro 2 Gaveta 5");
    ui->listWidget->addItem("Diodo              germanio            Gaveteiro 2 Gaveta 5");
    ui->listWidget->addItem("Diodo              ultrafast           Gaveteiro 2 Gaveta 5");
    ui->listWidget->addItem("CI                 reg tensão          Gaveteiro 1 Gaveta 1");


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    QRegExp regExp(arg1, Qt::CaseInsensitive, QRegExp::Wildcard);
    ui->listWidget->clear();
    ui->listWidget->addItems(mylist.filter(regExp));
    ui->labeltotal->setText(QString("%1").arg(ui->listWidget->count()));
}
