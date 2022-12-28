#ifndef WIELOMIANPARSER_H
#define WIELOMIANPARSER_H
#include <map>
#include <string>

class WielomianParser
{
private:
    struct Wyrazenie {
        double wspolczynnik;
        int exponenta;
    };

    std::map<int, double> wielomian;

public:
    WielomianParser();
    static Wyrazenie parseWyrazenie(std::string str);
    static std::map<int, double> parseWielomian(std::string str);
};

#endif // WIELOMIANPARSER_H
