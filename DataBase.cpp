#include "DataBase.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include "optionsMenu.hpp"
#include "peselValidator.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

DataBase::DataBase() {}

DataBase::~DataBase() {}
int size = 11;
int DataBase::showMenu() const {
  std::string options[] = {"Wybierz opcję:",
                           "1 - Dodaj osobę",
                           "2 - Usun osobę",
                           "3 - Wyświetl baze danych",
                           "4 - Sortuj",
                           "5 - Znajdz osobe",
                           "6 - Wczytaj z pliku",
                           "7 - Zapisz do pliku",
                           "8 - Modyfikuj dane",
                           "9 - Losowe generowanie osób",
                           "10 - Wyjscie z programu"};
  return optionsMenu(size, options);
}

void DataBase::addPerson() {
  int indexOrSalary, role;
  std::string name, surname, pesel, addres;

  while (pesel.empty()) {
    std::cout << "Podaj numer PESEL osoby: ";
    std::getline(std::cin, pesel);
  }
  auto it = std::find_if(vec_persons.begin(), vec_persons.end(),
                         [pesel](const std::shared_ptr<Person> person) {
                           return person->getPesel() == pesel;
                         });

  if (it != vec_persons.end()) {
    std::cout << "Osoba z podanym numerem PESEL już istnieje" << std::endl;
    std::cin.ignore(15, '\n');
    std::cin.get();
  } else {
    while (name.empty()) {
      std::cout << "Podaj imię osoby: ";
      std::getline(std::cin, name);
    }
    while (surname.empty()) {
      std::cout << "Podaj nazwisko osoby: ";
      std::getline(std::cin, surname);
    }
    while (addres.empty()) {
      std::cout << "Podaj adres osoby: ";
      std::getline(std::cin, addres);
    }
    std::string options[] = {"Wybierz osobę do wprowadzenia:", "Student",
                             "Pracownik"};
    role = optionsMenu(3, options);
    if (role == 1) {
      std::cout << "Podaj index: ";
      std::cin >> indexOrSalary;
      while (!std::cin || indexOrSalary < 0) {
        std::cin.clear();
        std::cin.sync();
        std::cin.ignore(15, '\n');
        std::cout << "\nPodany index jest niepoprawny!\nPodaj index: ";
        std::cin >> indexOrSalary;
      }
      auto it =
          std::find_if(vec_persons.begin(), vec_persons.end(),
                       [indexOrSalary](const std::shared_ptr<Person> student) {
                         return student->getIndex() == indexOrSalary;
                       });

      if (it != vec_persons.end()) {
        std::cout << "Student z podanym indexem już istnieje" << std::endl;
        std::cin.ignore(15, '\n');
        std::cin.get();
      } else {
        vec_persons.push_back(std::make_shared<Student>(indexOrSalary, surname,
                                                        name, pesel, addres));
      }
    } else {
      std::cout << "Podaj zarobki: ";
      std::cin >> indexOrSalary;
      while (!std::cin || indexOrSalary < 0) {
        std::cin.clear();
        std::cin.sync();
        std::cin.ignore(15, '\n');
        std::cout << "\nPodane zarobki da niepoprawne\nPodaj zarobki: ";
        std::cin >> indexOrSalary;
      }
      vec_persons.push_back(std::make_shared<Employee>(indexOrSalary, surname,
                                                       name, pesel, addres));
    }
    auto itr = vec_persons.rbegin();
    if (peselValidator(**itr) == false)
      vec_persons.pop_back();
  }

  std::cin.ignore(15, '\n');
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
  showPersons();
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

void DataBase::showPersons() const {
  if (vec_persons.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(13) << "Pesel" << std::setw(20) << "Imie"
            << std::setw(20) << "Nazwisko" << std::setw(20) << "Adres"
            << std::setw(10) << "Plec" << std::setw(10) << "Pensja"
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
  showPersons();
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
      }
    }
  } else {
    std::cout << "Nie ma takiego peselu!\n";
  }
  std::cin.ignore(10, '\n');
}

void DataBase::randomData() {
  std::ifstream data("rand.csv");
  std::string line;
  std::cout << "Podaj ilość nowych wpisów: ";
  int quantity;
  std::cin >> quantity;
  while (!std::cin) {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(15, '\n');
    std::cout << "\nBŁĄÐ!\nPodaj ilość nowych wpisów: ";
    std::cin >> quantity;
  }
  std::cin.ignore(15, '\n');
  int name, surname, addres, pesel, salary, index;

  std::vector<std::vector<std::string>> file;
  while (std::getline(data, line)) {
    std::stringstream lineStream(line);
    std::string cell;
    std::vector<std::string> oneType;
    while (std::getline(lineStream, cell, ',')) {
      oneType.push_back(cell);
    }

    file.push_back(oneType);
  }
  srand(time(NULL));

  for (int i = 0; i < quantity; ++i) {
    name = (std::rand() % file[0].size());
    surname = (std::rand() % file[1].size());
    pesel = (std::rand() % file[2].size());
    addres = (std::rand() % file[3].size());
    if ((std::rand() % 100) % 2 == 0) {
      salary = (std::rand() % file[5].size());
      vec_persons.push_back(std::make_shared<Employee>(
          std::stoi(file[5][salary]), file[1][surname], file[0][name],
          file[2][pesel], file[3][addres]));
    } else {
      index = (std::rand() % file[4].size());
      vec_persons.push_back(std::make_shared<Student>(
          std::stoi(file[4][index]), file[1][surname], file[0][name],
          file[2][pesel], file[3][addres]));
    }
  }
}
