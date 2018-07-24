#include "DataBase.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
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
              << "4 - Wczytaj z pliku\n"
              << "0 - Wyjscie z programu \n"
              << "Co chcesz robic: ";
    std::cin >> t;
    std::cin.ignore(10, '\n');
  } while (t < '0' || t > '4');
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
  auto it = std::find_if(vec_persons.begin(), vec_persons.end(),
                         [index](const std::shared_ptr<Person> student) {
                           return student->getIndex() == index;
                         });
  // auto it = std::find_if(vec_students.begin(),vec_students.end(),
  //                      [index](const Student & student){
  //  return student.getIndex() == index;
  //});

  if (it != vec_persons.end()) {
    std::cout << "Student z podanym indexem już istnieje" << std::endl;
    std::cin.ignore(15, '\n');
    std::cin.get();
  } else {
    vec_persons.push_back(std::make_shared<Student>(index, surname, name,
                                                    "23456", "man", "fytsuh"));
  }
}

void DataBase::deleteStudent() {
  showStudents();
  if (vec_persons.empty()) {
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
  /// tu skonczylas
  auto it_delete = std::find_if(vec_persons.begin(), vec_persons.end(),
                                [index](const std::shared_ptr<Person> student) {
                                  return student->getIndex() == index;
                                });

  // auto it_delete = std::find_if(vec_students.begin(),vec_students.end(),
  //                        [index](const Student & student){
  //   return student.getIndex() == index;
  //});

  if (it_delete == vec_persons.end()) {
    std::cout << "Nie ma takiego indeksu." << std::endl;
  } else {
    vec_persons.erase(it_delete);
    std::cout << "Usunieto studenta o podanym indeksie." << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}

void DataBase::showStudents() const {
  if (vec_persons.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(13) << "Pesel" << std::setw(20) << "Imie"
            << std::setw(20) << "Nazwisko" << std::setw(20) << "Adres"
            << std::setw(10) << "Płeć" << std::setw(10) << "Pensja"
            << std::setw(10) << "Indeks" << std::endl;
  std::cout.fill('=');
  std::cout << std::setw(103) << "=" << std::endl;
  std::cout.fill(' ');
  for (std::vector<std::shared_ptr<Person>>::const_iterator itr =
           vec_persons.begin();
       itr != vec_persons.end(); itr++) {
    std::cout << std::left << std::setw(13) << (*itr)->getPesel()
              << std::setw(20) << (*itr)->getName() << std::setw(20)
              << (*itr)->getSurname() << std::setw(20) << (*itr)->getAddres()
              << std::setw(10) << (*itr)->getSex() << std::setw(10)
              << (*itr)->getSalary() << std::setw(10) << (*itr)->getIndex()
              << std::endl;
  }
}

void DataBase::importData() {
  std::ifstream data("DataBase.csv");
  std::string status, name, surname, addres, sex, pesel, str_salary, str_index;
  int salary, index;
  std::getline(data, status, ',');
  while (!data.eof()) {
    std::getline(data, name, ',');
    std::getline(data, surname, ',');
    std::getline(data, pesel, ',');
    std::getline(data, addres, ',');
    std::getline(data, sex, ',');
    std::getline(data, str_salary, ',');
    std::getline(data, str_index, '\n');
    if (!str_salary.empty())
      salary = std::stoi(str_salary);
    if (!str_index.empty())
      index = std::stoi(str_index);
    if (status == "s") {
      vec_persons.push_back(
          std::make_shared<Student>(index, surname, name, pesel, sex, addres));
    } else {
      vec_persons.push_back(std::make_shared<Employee>(salary, surname, name,
                                                       pesel, sex, addres));
    }
    std::getline(data, status, ',');
  }
  data.close();
}
