#include "showStudents.hpp"
#include <iomanip>

void showStudents(std::map<int, Student> &map_students) {
  if(map_students.empty()) {
    std::cout << "Baza studentow jest pusta" << std::endl;
    return;
  }
  std::cout << std::left << std::setw(20) << "Numer indeksu"
            << std::setw(20) << "Imie" 
            << std::setw(20) << "Nazwisko" << std::endl;
  std::cout.fill('=');
  std::cout << std::setw(60) << "=" << std::endl;
  std::cout.fill(' ');
  for (std::map<int, Student>::iterator itr = map_students.begin(); itr != map_students.end(); itr++) {
    std::cout << std::left << std::setw(20) << (itr->second).getIndex()
              << std::setw(20) << (itr->second).getName() 
              << std::setw(20) << (itr->second).getSurname() << std::endl;
  }
}
