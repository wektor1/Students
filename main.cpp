#include "DataBase.hpp"
#include <iostream>
#include <stdlib.h>

int main() {
  DataBase students_list;
  int loop = 1;
  char t = 'm';
  while (loop == 1) {
    t = students_list.showMenu();
    system("clear");
    switch (t) {
    case '0':
      loop = 0;
      break;
    case '1':
      students_list.addStudent();
      break;
    case '2':
      students_list.deleteStudent();
      break;
    case '3':
      students_list.showStudents();
      std::cin.get();
      break;
    case '4':
      students_list.importData();
      break;
    }
  }
  return 0;
}
