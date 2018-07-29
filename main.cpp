#include "DataBase.hpp"
#include <iostream>
#include <stdlib.h>

int main() {
  DataBase students_list;
  int loop = 1;
  int t;
  while (loop == 1) {
    t = students_list.showMenu();
    system("clear");
    switch (t) {
    case 10: {
      loop = 0;
      break;
    }
    case 1: {
      students_list.addPerson();
      break;
    }
    case 2: {
      students_list.deletePerson();
      break;
    }
    case 3: {
      students_list.showStudents();
      std::cin.ignore(30, '\n');
      break;
    }
    case 4: {
      int choice = 0;
      std::cout << "1 - Sortuj po numerze PESEL  \n"
                << "2 - Sortuj po indeksie  \n"
                << "3 - Sortuj po zarobkach \n"
                << "Co chcesz robic: ";
      std::cin >> choice;
      switch (choice) {
      case 1: {
        students_list.sortByPesel();
        break;
      }
      case 2: {
        students_list.sortByIndex();
        break;
      }
      case 3: {
        students_list.sortBySalary();
        break;
      }
      default: {
        std::cout << "zly wybór";
        break;
      }
      }
      break;
    }
    case 5: {
      students_list.findPerson();
      break;
    }
    case 6: {
      students_list.importData();
      break;
    }
    case 7: {
      students_list.saveDataBase();
      break;
    }
    case 8: {
      students_list.modifyData();
      break;
    }
    case 9: {
      students_list.generateData();
      break;
    }
    }
  }
  return 0;
}
