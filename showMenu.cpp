#include "showMenu.hpp"
#include <iostream>
#include <stdlib.h>

char showMenu() {
 char t = '-';
  do {
    system("clear");
    std::cout << "1 - Dodaj studenta  \n" <<
                 "2 - Usun studenta  \n" <<
                 "3 - Wyswietl wszystkich studentow \n" <<
                 "0 - Wyjscie z programu \n" <<
                 "Co chcesz robic: ";
    std::cin >> t;
    std::cin.ignore(10, '\n');
  } while (t < '0' || t > '3');
  return t;
}

