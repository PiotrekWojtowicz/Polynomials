#include "wielomianparser.h"

WielomianParser::WielomianParser()
{

}

WielomianParser::Wyrazenie WielomianParser::parseWyrazenie(std::string str)
{
    Wyrazenie term;
     term.wspolczynnik = 1.0;
     term.exponenta = 0;

     // Sprawdz czy zawiera wspolczynnik
     int wspolczynnikStart = 0;
     if (str[0] == '+' || str[0] == '-') {
         wspolczynnikStart = 1;
     }

     if(str[0] == '-'){
         term.wspolczynnik = -1.0;
     }

     // Znajdz pozycje exponenty
     int exponentaStart = str.find('^');
     if (exponentaStart == std::string::npos) {
         exponentaStart = str.length();
     }

     // Wyszegolnij exponete oraz wspolczynnik
     term.wspolczynnik *= stod(str.substr(wspolczynnikStart, exponentaStart - wspolczynnikStart));
     if (exponentaStart < str.length()) {
         term.exponenta = stoi(str.substr(exponentaStart + 1));
     }

     return term;
}

std::map<int, double> WielomianParser::parseWielomian(std::string str)
{
    std::map<int, double> tempWielomian;

      // Dodawaj kolejne wyrazenia wielomianu
      int termStart = 0;
      for (int i = 0; i < str.length(); i++) {
          if (str[i] == '+' || str[i] == '-') {
              std::string termStr = str.substr(termStart, i - termStart);
              if(termStr == " " || termStr.empty())
                  continue;
              Wyrazenie term = parseWyrazenie(termStr);
              tempWielomian[term.exponenta] += term.wspolczynnik;
              termStart = i;
          }
      }

      // Dodaj ostatni element
      std::string termStr = str.substr(termStart);
      Wyrazenie term = parseWyrazenie(termStr);
      tempWielomian[term.exponenta] += term.wspolczynnik;

      return tempWielomian;
}
