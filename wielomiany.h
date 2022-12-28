#ifndef WIELOMIANY_H
#define WIELOMIANY_H

#include <QMainWindow>
#include <qwt_text.h>
#include <qwt_math.h>
#include "polynomial.h"
#include "wielomianparser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Wielomiany; }
QT_END_NAMESPACE

class Wielomiany : public QMainWindow
{
    Q_OBJECT

public:
    Wielomiany(QWidget *parent = nullptr);
    ~Wielomiany();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Wielomiany *ui;
    std::string getTextPol1() const;
    std::string getTextPol2() const;
    double getTextValue() const;
};
#endif // WIELOMIANY_H
