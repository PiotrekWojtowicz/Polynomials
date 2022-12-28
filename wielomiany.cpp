#include "wielomiany.h"
#include "ui_wielomiany.h"

Wielomiany::Wielomiany(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Wielomiany)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlaceholderText("Wielomian 1");
    ui->plainTextEdit_2->setPlaceholderText("Wielomian 2");
    ui->plainTextEdit_3->setPlaceholderText("Wynik operacji...");

    // Resize is not possible
    this->statusBar()->setSizeGripEnabled(false);
}

Wielomiany::~Wielomiany()
{
    delete ui;
}

std::string Wielomiany::getTextPol1() const
{
    return ui->plainTextEdit->toPlainText().toStdString();
}

std::string Wielomiany::getTextPol2() const
{
    return ui->plainTextEdit_2->toPlainText().toStdString();
}

double Wielomiany::getTextValue() const
{
    return ui->lineEdit->text().toDouble();
}


//Przycisk dodawania wielomianow
void Wielomiany::on_pushButton_clicked()
{
    //Utwórz wielomiany
    Polynomial wielomian1(WielomianParser::parseWielomian(getTextPol1()));
    Polynomial wielomian2(WielomianParser::parseWielomian(getTextPol2()));

    //Rezultat dodawania
    wielomian1 = wielomian1 + wielomian2;
    std::string a = wielomian1.wielomianToString();
    std::cout << a << std::endl;
    QString temp(QString::fromStdString(a));
    ui->plainTextEdit_3->setPlainText(temp);
}

void Wielomiany::on_pushButton_2_clicked()
{
    //Utwórz wielomiany
    Polynomial wielomian1(WielomianParser::parseWielomian(getTextPol1()));
    Polynomial wielomian2(WielomianParser::parseWielomian(getTextPol2()));

    //Rezultat dodawania
    wielomian1 = wielomian1 - wielomian2;
    std::string a = wielomian1.wielomianToString();
    QString temp(QString::fromStdString(a));
    ui->plainTextEdit_3->setPlainText(temp);
}


void Wielomiany::on_pushButton_3_clicked()
{
    //Utwórz wielomiany
    Polynomial wielomian1(WielomianParser::parseWielomian(getTextPol1()));
    Polynomial wielomian2(WielomianParser::parseWielomian(getTextPol2()));

    //Rezultat dodawania
    wielomian1 = wielomian1 * wielomian2;
    std::string a = wielomian1.wielomianToString();
    QString temp(QString::fromStdString(a));
    ui->plainTextEdit_3->setPlainText(temp);
}


void Wielomiany::on_pushButton_4_clicked()
{
    double value = 0.0;
    if(ui->radioButton->isChecked()){
        Polynomial wielomian1(WielomianParser::parseWielomian(getTextPol1()));
        value = wielomian1.wyliczDlaWartości(getTextValue());
    }
    else if(ui->radioButton_2->isChecked()){
        Polynomial wielomian1(WielomianParser::parseWielomian(getTextPol2()));
        value = wielomian1.wyliczDlaWartości(getTextValue());
    }
    std::string a = std::to_string(value);
    a = a.substr(0, a.find(".") + 3);
    QString temp(QString::fromStdString(a));
    if(a == "0.00")
        ui->plainTextEdit_3->setPlainText("Dokonaj wyboru");
    else
        ui->plainTextEdit_3->setPlainText("Wynik: "+temp);
}

