#include "showStudents.hpp"
#include <iomanip>

void showStudents(std::map<int, Student> &mapStudents) {
  if(mapStudents.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  for (std::map<int, Student>::iterator itr = mapStudents.begin(); itr != mapStudents.end(); itr++) {
    std::cout << std::left << std::setw(15) << (itr->second).getIndex()
              << std::setw(15) << (itr->second).getName() << std::setw(15)
              << (itr->second).getSurname() << std::endl;
  }
}
