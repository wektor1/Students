#include "deleteStudent.hpp"
#include "showStudents.hpp"
#include <iostream>

void deleteStudent(std::map<int, Student> &map_student) {
  showStudents(map_student);
  if (map_student.empty()) {
  //  std::cin.ignore();
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
    std::cout << "\nPodany index nie jest liczbą!\nPodaj index: ";
    std::cin >> index;
  }
  std::map<int, Student>::iterator it_delete;
  it_delete = map_student.find(index);
  if (it_delete == map_student.end()) {
    std::cout << "Nie ma takiego indeksu." << std::endl;
  } else {
    map_student.erase(it_delete);
    std::cout << "Usunieto studenta o podanym indeksie." << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}
