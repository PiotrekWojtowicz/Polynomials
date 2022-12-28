#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

class Polynomial
{
public:
    //Konstruktory
    Polynomial(const std::vector<double>& wspolczynniki);
    Polynomial(std::map<int, double> wielomian);
    //Operator dodwania wielomianów
    Polynomial operator+(const Polynomial& other) const;
    //Operator odejmowania wielomianów
    Polynomial operator-(const Polynomial& other) const;
    //Operator mnożenia wielomianów
    Polynomial operator*(const Polynomial& other) const;
    //Wylicz wartość
    double wyliczDlaWartości(double x);
    //Wyświetl wielomian
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& p);
    //Wielomian do std::string
    std::string wielomianToString();

private:
    double getWspolczynnik(size_t power) const;
    std::vector<double> wspolczynnik;
};

#endif // POLYNOMIAL_H
