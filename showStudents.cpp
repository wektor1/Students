#include "showStudents.hpp"

void showStudents(std::map<int, Student> &mapStudents) {
  for (std::map<int, Student>::iterator itr = mapStudents.begin();
       itr != mapStudents.end(); itr++) {
    std::cout << (itr->second).getIndex() << " \t\t\t\t "
              << (itr->second).getName() << " \t\t\t\t "
              << (itr->second).getSurname() << std::endl;
  }
  std::cin.ignore();
  std::cin.get();
}
