#include"showMenu.hpp"
#include<iostream>

int showMenu() {
	int t = -1;
	std::cout << "1 - Dodaj studenta  \n2 - Usun studenta  \n3 - Wyswietl wszystkich studentow \n0 - Wyjscie z programu \nCo chcesz robic: ";
	std::cin >> t;
	return t;
}
