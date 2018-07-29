#include "DataBase.hpp"
#include "Employee.hpp"
#include "Student.hpp"
#include "optionsMenu.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>

DataBase::DataBase() {}

DataBase::~DataBase() {}
int size = 11;
int DataBase::showMenu() const {
  std::string options[] = {"Wybierz opcję:",
                           "1 - Dodaj osobę",
                           "2 - Usun osobę",
                           "3 - Wyswietl wszystkich studentow",
                           "4 - Sortuj",
                           "5 - Znajdz osobe",
                           "6 - Wczytaj z pliku",
                           "7 - Zapisz do pliku",
                           "8 - Modyfikuj dane",
                           "9 - Generuj losowe dane",
                           "10 - Wyjście z programu"};
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
      }
    }
  } else {
    std::cout << "Nie ma takiego peselu!\n";
  }
  std::cin.ignore(10, '\n');
}

void DataBase::generateData() {
  srand(time(NULL));
  std::string s_line;
  std::stringstream ss_line;
  std::ifstream random_data("RandomData.csv");
  std::getline(random_data, s_line, '\n');
  std::vector<std::string> names;
  std::vector<std::string> surnames;
  std::vector<std::string> addreses;
  std::vector<std::string> pesels;
  std::vector<int> salaries;
  std::vector<int> indexies;
  std::string single_data;
  std::string category;
  while (!random_data.eof()) {
    // std::cout<<s_line<<'\n';
    ss_line << s_line;
    // std::cout<<ss_line<<'\n';
    std::getline(ss_line, category, ',');
    // std::cout<<category<<" ";
    if (category == "imie") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        // std::cout<<single_data<<'\n';
        names.push_back(single_data);
        // std::getline(line,single_data,',');
      }
    }
    if (category == "nazwisko") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        surnames.push_back(single_data);
        // std::getline(line,single_data,',');
      }
    }
    if (category == "adres") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        addreses.push_back(single_data);
        // std::getline(line,single_data,',');
      }
    }
    if (category == "pesel") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        pesels.push_back(single_data);
        // std::getline(line,single_data,',');
      }
    }
    if (category == "indeks") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        indexies.push_back(std::stoi(single_data));
        // std::getline(line,single_data,',');
      }
    }
    if (category == "wypłata") {
      // std::getline(line,single_data,',');
      while (std::getline(ss_line, single_data, ',')) {
        salaries.push_back(std::stoi(single_data));
        // std::getline(line,single_data,',');
      }
    }
    category.clear();
    std::stringstream().swap(ss_line);
    std::getline(random_data, s_line, '\n');
  }
  std::string options[] = {
      "Wybierz ile pozycji wygenerować:", "1", "2", "3", "4", "5"};
  int size = 6;
  int quantity = optionsMenu(size, options);
  if (rand() % 2 == 0)
    std::generate_n(vec_persons.end(), quantity, [&] {
      return std::make_shared<Student>(
          indexies[rand() % indexies.size()],
          surnames[rand() % surnames.size()], names[rand() % names.size()],
          pesels[rand() % pesels.size()], addreses[rand() % addreses.size()]);
    });
  else
    std::generate_n(vec_persons.end(), quantity, [&] {
      return std::make_shared<Employee>(
          salaries[rand() % salaries.size()],
          surnames[rand() % surnames.size()], names[rand() % names.size()],
          pesels[rand() % pesels.size()], addreses[rand() % addreses.size()]);
    });
}
