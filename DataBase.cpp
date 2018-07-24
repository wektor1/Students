#include "DataBase.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>

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

    auto it = std::find_if(vec_students.begin(),vec_students.end(),
                           [index](const std::shared_ptr<Student> & student){
        return student->getIndex() == index;
 });

  if (it != vec_students.end()) {
    std::cout << "Student z podanym indexem już istnieje" << std::endl;
    std::cin.ignore(15, '\n');
    std::cin.get();
  }
  else{
   vec_students.push_back(std::make_shared<Student>(index,surname,name,"23456","man","fytsuh"));
  }
}

void DataBase::deleteStudent() {
  showStudents();
  if (vec_students.empty()) {
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
  ///tu skonczylas
  auto it_delete = std::find_if(vec_students.begin(),vec_students.end(),
                           [index](const std::shared_ptr<Student> & student){
        return student->getIndex() == index;
 });

  if (it_delete == vec_students.end()) {
    std::cout << "Nie ma takiego indeksu." << std::endl;
  } else {
    vec_students.erase(it_delete);
    std::cout << "Usunieto studenta o podanym indeksie." << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}

void DataBase::showStudents() const {
  if (vec_students.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(20) << "Numer indeksu" << std::setw(20)
            << "Imie" << std::setw(20) << "Nazwisko" << std::endl;
  std::cout.fill('=');
  std::cout << std::setw(60) << "=" << std::endl;
  std::cout.fill(' ');
  for (std::vector<std::shared_ptr<Student>>::const_iterator itr = vec_students.begin();
       itr != vec_students.end(); itr++) {
    std::cout << std::left << std::setw(20) << (*itr)->getIndex()
              << std::setw(20) << (*itr)->getName() << std::setw(20)
              << (*itr)->getSurname() << std::endl;
  }
}
