#include "deleteStudent.hpp"
#include "showStudents.hpp"
#include <iostream>

void deleteStudent(std::map<int, Student> &map_student) {
  std::cout << "Naciśnij enter, by podać index.\n\n";
  showStudents(map_student);
  std::cout << "Podaj numer indeksu studenta: ";
  int index;
  std::cin >> index;
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
