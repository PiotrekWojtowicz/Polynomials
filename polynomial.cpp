#include "polynomial.h"

Polynomial::Polynomial(const std::vector<double> &wspolczynniki): wspolczynnik(wspolczynniki) {}

Polynomial::Polynomial(std::map<int, double> wielomian)
{
    auto x = std::max_element(wielomian.begin(), wielomian.end(),
                              [](const std::pair<int, double>& p1, const std::pair<int, double>& p2) {
                                  return p1.first < p2.first; });

    std::vector<double>temp(x->first);
    for(std::pair<int, double> a : wielomian) {
        temp.emplace(temp.begin()+ a.first, a.second);
    }
    this->wspolczynnik = temp;
}

Polynomial Polynomial::operator+(const Polynomial &other) const
{
    std::vector<double> tempWspolczynniki(std::max(wspolczynnik.size(), other.wspolczynnik.size()));
    for (size_t i = 0; i < tempWspolczynniki.size(); i++) {
        tempWspolczynniki[i] = getWspolczynnik(i) + other.getWspolczynnik(i);
    }
    return {tempWspolczynniki};
}

Polynomial Polynomial::operator-(const Polynomial &other) const
{
    std::vector<double> tempWspolczynniki(std::max(wspolczynnik.size(), other.wspolczynnik.size()));
    for (size_t i = 0; i < tempWspolczynniki.size(); i++) {
        tempWspolczynniki[i] = getWspolczynnik(i) - other.getWspolczynnik(i);
    }
    return {tempWspolczynniki};
}

Polynomial Polynomial::operator*(const Polynomial &other) const
{
    std::vector<double> tempWspolczynniki(wspolczynnik.size() + other.wspolczynnik.size() - 1);
    for (size_t i = 0; i < tempWspolczynniki.size(); i++) {
        for (size_t j = 0; j < other.wspolczynnik.size(); j++) {
            tempWspolczynniki[i + j] += wspolczynnik[i] * other.wspolczynnik[j];
        }
    }
    return {tempWspolczynniki};
}

double Polynomial::wyliczDlaWartości(double x)
{
    //Schemat Hornera do wyliczenia wartości wielomianu
    double rezultat = wspolczynnik.at(wspolczynnik.size()-1);
    for (auto a = wspolczynnik.end()-2; a != wspolczynnik.begin()-1; a--) {
        rezultat = rezultat * x + *(a);
    }
    return rezultat;
}

std::string Polynomial::wielomianToString()
{
    std::string checkEmpty;
    std::string temp = "";
    for (size_t i = 0; i < this->wspolczynnik.size(); i++) {
        checkEmpty = std::to_string(this->getWspolczynnik(i)).substr(0, std::to_string(this->getWspolczynnik(i)).find(".") + 3);
        if(checkEmpty != "0.00"){
            temp+=checkEmpty;
            temp += "x^";
            temp += std::to_string(i);
            if (i > 0) {
                temp += " + ";
            }
        }
    }
    return temp.substr(0, temp.size()-3);
}

double Polynomial::getWspolczynnik(size_t power) const {
    if (power >= wspolczynnik.size()) {
        return 0;
    }
    return wspolczynnik[power];
}

std::ostream& operator<<(std::ostream& out, const Polynomial& p) {
    for (size_t i = 0; i < p.wspolczynnik.size(); i++) {
        if (i > 0) {
            out << " + ";
        }
        out << p.getWspolczynnik(i) << "x^" << i;
    }
    return out;
}
