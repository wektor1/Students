#include "DataBase.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>

DataBase::DataBase() {}

DataBase::~DataBase() {}

char DataBase::showMenu() const {
  char t = '-';
  do {
    system("clear");
    std::cout << "1 - Dodaj studenta  \n"
              << "2 - Usun studenta  \n"
              << "3 - Wyswietl wszystkich studentow \n"
              << "0 - Wyjscie z programu \n"
              << "Co chcesz robic: ";
    std::cin >> t;
    std::cin.ignore(10, '\n');
  } while (t < '0' || t > '3');
  return t;
}

void DataBase::addStudent() {
  int index;
  std::string name, surname;
  while (name.empty()) {
    std::cout << "Podaj imie studenta: ";
    std::getline(std::cin, name);
  }
  while (surname.empty()) {
    std::cout << "Podaj nazwisko studenta: ";
    std::getline(std::cin, surname);
  }
  std::cout << "Podaj index: ";
  std::cin >> index;
  while (!std::cin || index < 0) {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(15, '\n');
    std::cout << "\nPodany index jest niepoprawny!\nPodaj index: ";
    std::cin >> index;
  }

  std::pair<std::map<int, Student>::iterator, bool> inserted;
  inserted = map_students.insert(
      std::pair<int, Student>(index, Student(index, surname, name)));
  if (inserted.second == false) {
    std::cout << "Student z podanym indexem już istnieje" << std::endl;
    std::cin.ignore(15, '\n');
    std::cin.get();
  }
}

void DataBase::deleteStudent() {
  showStudents();
  if (map_students.empty()) {
    std::cin.get();
    return;
  }
  std::cout << "Podaj numer indeksu studenta: ";
  int index;
  std::cin >> index;
  while (!std::cin) {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(15, '\n');
    std::cout << "\nPodany index nie jest liczba!\nPodaj index: ";
    std::cin >> index;
  }
  std::map<int, Student>::iterator it_delete;
  it_delete = map_students.find(index);
  if (it_delete == map_students.end()) {
    std::cout << "Nie ma takiego indeksu." << std::endl;
  } else {
    map_students.erase(it_delete);
    std::cout << "Usunieto studenta o podanym indeksie." << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}

void DataBase::showStudents() const {
  if (map_students.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(20) << "Numer indeksu" << std::setw(20)
            << "Imie" << std::setw(20) << "Nazwisko" << std::endl;
  std::cout.fill('=');
  std::cout << std::setw(60) << "=" << std::endl;
  std::cout.fill(' ');
  for (std::map<int, Student>::const_iterator itr = map_students.begin();
       itr != map_students.end(); itr++) {
    std::cout << std::left << std::setw(20) << (itr->second).getIndex()
              << std::setw(20) << (itr->second).getName() << std::setw(20)
              << (itr->second).getSurname() << std::endl;
  }
}
