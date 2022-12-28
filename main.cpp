#include "wielomiany.h"
#include "wielomianparser.h"
#include "polynomial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wielomiany w;

    std::map<int, double> wynik = WielomianParser::parseWielomian("-5x^2+30.15 + 1250x^1 + 23.31");
    std::vector<double> cofki(5);

    for(std::pair<int, double> a : wynik) {
        cofki.emplace(cofki.begin()+ a.first, a.second);
    }

    Polynomial p3(wynik);
    std::cout << "p3: " << p3 << std::endl;
    std::cout << p3.wyliczDlaWartości(1.33) << std::endl;

    w.show();
    return a.exec();
}
