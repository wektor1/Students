#include "Student.hpp"
#include "addStudent.hpp"
#include "deleteStudent.hpp"
#include "showMenu.hpp"
#include "showStudents.hpp"
#include <iostream>
#include <map>
#include <stdlib.h>

int main() {
  std::map<int, Student> map_students;
  int loop = 1, t = -1;
  while (loop == 1) {
    t = showMenu();
    system("clear");
    switch (t) {
    case 0:
      loop = 0;
      break;
    case 1:
      addStudent(map_students);
      break;
    case 2:
      deleteStudent(map_students);
      break;
    case 3:
      showStudents(map_students);
      std::cin.ignore();
      std::cin.get();
      break;
    }
  }
  return 0;
}
