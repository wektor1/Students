#include "addStudent.hpp"
#include <iostream>
#include <string>

void addStudent(std::map<int, Student> &map_student) {
  int index;
  std::string name, surname;
  std::cout << "Podaj imie studenta: ";
  std::cin.get();
  std::getline(std::cin, name);
  std::cout << "Podaj nazwisko studenta: ";
  std::getline(std::cin, surname);
  std::cout << "Podaj index: ";
  std::cin >> index;
  while (!std::cin) {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(15,'\n');
    std::cout << "\nPodany index nie jest liczbą!\nPodaj index: ";
    std::cin >> index;
  }

  std::pair<std::map<int, Student>::iterator, bool> inserted;
  inserted = map_student.insert(
      std::pair<int, Student>(index, Student(index, surname, name)));
  if (inserted.second == false) {
    std::cout << "Student z podanym indexem już istnieje" << std::endl;
    std::cin.ignore(15,'\n');
    std::cin.get();
  }
}
