#include "DataBase.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include "optionsMenu.hpp"
#include <algorithm>
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
              << "2 - Usun osobę \n"
              << "3 - Wyswietl wszystkich studentow \n"
              << "4 - Sortuj \n"
              << "5 - Znajdz osobe \n"
              << "6 - Wczytaj z pliku \n"
              << "7 - Zapisz do pliku \n"
              << "8 - Modyfikuj dane \n"
              << "0 - Wyjscie z programu \n"
              << "Co chcesz robic: ";
    std::cin >> t;
    std::cin.ignore(10, '\n');
  } while (t < '0' || t > '8');
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

  if (it != vec_persons.end()) {
    std::cout << "Student z podanym indexem już istnieje" << std::endl;
    std::cin.ignore(15, '\n');
    std::cin.get();
  } else {
    vec_persons.push_back(
        std::make_shared<Student>(index, surname, name, "23456", "fytsuh"));
  }
}

void DataBase::sortByIndex() {
  std::sort(begin(vec_persons), end(vec_persons),
            [](const std::shared_ptr<Person> &lhs,
               const std::shared_ptr<Person> &rhs) {
              return lhs->getIndex() < rhs->getIndex();
            });
}

void DataBase::sortBySalary() {
  std::sort(begin(vec_persons), end(vec_persons),
            [](const std::shared_ptr<Person> &lhs,
               const std::shared_ptr<Person> &rhs) {
              return lhs->getSalary() < rhs->getSalary();
            });
}

void DataBase::sortByPesel() {
  std::sort(begin(vec_persons), end(vec_persons),
            [](const std::shared_ptr<Person> &lhs,
               const std::shared_ptr<Person> &rhs) {
              return lhs->getPesel() < rhs->getPesel();
            });
}

void DataBase::deletePerson() {
  showStudents();
  if (vec_persons.empty()) {
    std::cin.get();
    return;
  }
  std::cout << "Podaj numer PESEL osoby: ";
  std::string pesel;
  std::cin >> pesel;
  while (!std::cin) {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(15, '\n');
    std::cout << "\nPodany PESEL nie jest liczba!\nPodaj index: ";
    std::cin >> pesel;
  }

  auto it_delete = std::find_if(vec_persons.begin(), vec_persons.end(),
                                [pesel](const std::shared_ptr<Person> person) {
                                  return person->getPesel() == pesel;
                                });

  if (it_delete == vec_persons.end()) {
    std::cout << "Nie ma takiego numeru PESEL." << std::endl;
  } else {
    vec_persons.erase(it_delete);
    std::cout << "Usunieto osobę o podanym numerze PESEL." << std::endl;
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
          std::make_shared<Student>(index, surname, name, pesel, addres));
    } else {
      vec_persons.push_back(
          std::make_shared<Employee>(salary, surname, name, pesel, addres));
    }
    std::getline(data, status, ',');
  }
  data.close();
}

void DataBase::findPerson() {
  std::cout << "Podaj nazwisko lub numer PESEL szukanej osoby: ";
  std::string data;
  std::cin >> data;

  auto itr = std::find_if(vec_persons.begin(), vec_persons.end(),
                          [data](const std::shared_ptr<Person> &person) {
                            return (person->getSurname() == data ||
                                    person->getPesel() == data);
                          });

  if (itr == vec_persons.end()) {
    std::cout << "Nie ma takiej osoby w bazie." << std::endl;
  } else {
    std::cout << "Dane szukanej osoby to: " << std::endl;
    std::cout << std::left << std::setw(13) << "Pesel" << std::setw(20)
              << "Imie" << std::setw(20) << "Nazwisko" << std::setw(20)
              << "Adres" << std::setw(10) << "Płeć" << std::setw(10) << "Pensja"
              << std::setw(10) << "Indeks" << std::endl;
    std::cout.fill('=');
    std::cout << std::setw(103) << "=" << std::endl;
    std::cout.fill(' ');
    std::cout << std::left << std::setw(13) << (*itr)->getPesel()
              << std::setw(20) << (*itr)->getName() << std::setw(20)
              << (*itr)->getSurname() << std::setw(20) << (*itr)->getAddres()
              << std::setw(10) << (*itr)->getSex() << std::setw(10)
              << (*itr)->getSalary() << std::setw(10) << (*itr)->getIndex()
              << std::endl;
  }
  getchar();
  std::cin.get();
}

void DataBase::saveDataBase() {
  std::ofstream saveFile("SaveData.csv");
  for (std::vector<std::shared_ptr<Person>>::const_iterator itr =
           vec_persons.begin();
       itr != vec_persons.end(); itr++) {
    if ((*itr)->getSalary() == 0)
      saveFile << "s";
    else
      saveFile << "e";
    saveFile << ",";
    saveFile << (*itr)->getName() << ",";
    saveFile << (*itr)->getSurname() << ",";
    saveFile << (*itr)->getPesel() << ",";
    saveFile << (*itr)->getAddres() << ",";
    saveFile << (*itr)->getSex() << ",";
    if ((*itr)->getSalary() == 0) {
      saveFile << ",";
      saveFile << (*itr)->getIndex() << "\n";
    } else {
      saveFile << (*itr)->getSalary() << ",\n";
    }
  }
}

void DataBase::modifyData() {
  std::string options[3]{"Wybierz co chcesz modyfikować:", "Adres", "Zarobki"};
  int size = 3;
  int selected_option = optionsMenu(size, options);
  showStudents();
  std::string pesel;
  std::cout << "Podaj pesel osoby do modyfikacji: ";
  std::cin >> pesel;
  auto it_modify = std::find_if(vec_persons.begin(), vec_persons.end(),
                                [pesel](const std::shared_ptr<Person> person) {
                                  return person->getPesel() == pesel;
                                });
  std::cin.ignore();
  if (it_modify != vec_persons.end()) {
    if (selected_option == 1) {
      std::cout << "Podaj adres: ";
      std::string addres;
      std::cin >> addres;
      (*it_modify)->setAddres(addres);
    } else {
      if ((*it_modify)->getSalary() != 0) {
        std::cout << "Podaj nową wartość zarobków: ";
        int salary;
        std::cin >> salary;
        while (!std::cin || salary < 0) {
          std::cin.clear();
          std::cin.sync();
          std::cin.ignore(15, '\n');
          std::cout << "\nPodany kwota jest niepoprawna!\nPodaj kwote: ";
          std::cin >> salary;
        }
        (*it_modify)->setIndexOrSalary(salary);
      } else {
        std::cout << "Studentowi się nie płaci!\n";
        std::cin.get();
      }
    }
  } else {
    std::cout << "Nie ma takiego peselu!\n";
    std::cin.get();
  }
}
