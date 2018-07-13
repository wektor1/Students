#include "showMenu.hpp"
#include <iostream>
//#include <stdlib.h>

int showMenu() {
  int t = -1;
  do {
    //		system("clear");
    std::cout << "1 - Dodaj studenta  \n2 - Usun studenta  \n3 - Wyswietl "
                 "wszystkich studentow \n0 - Wyjscie z programu \nCo chcesz "
                 "robic: ";
    std::cin >> t;
  } while (t < 0 || t > 3);
  return t;
}
