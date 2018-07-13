#include "showMenu.hpp"
#include <iostream>

int showMenu() {
  int t = -1;
  do {
    std::cout << "1 - Dodaj studenta  \n" <<
                 "2 - Usun studenta  \n" <<
                 "3 - Wyswietl wszystkich studentow \n" <<
                 "0 - Wyjscie z programu \n" <<
                 "Co chcesz robic: ";
    std::cin >> t;
  } while (t < 0 || t > 3);
  return t;
}
