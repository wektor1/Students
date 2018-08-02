#include "DataBase.hpp"
#include "optionsMenu.hpp"
#include <iostream>
#include <stdlib.h>

int main() {
  DataBase persons_list;
  int loop = 1;
  int t;
  while (loop == 1) {
    t = persons_list.showMenu();
    system("clear");
    switch (t) {

    case 10: {
      loop = 0;
      break;
    }
    case 1: {
      persons_list.addPerson();
      break;
    }
    case 2: {
      persons_list.deletePerson();
      break;
    }
    case 3: {
      persons_list.showPersons();
      std::cin.ignore(30, '\n');
      break;
    }
    case 4: {
      int choice = 0;
      std::string options[]={"Wybierz rodzaj sortowania:", "Sortuj po numerze PESEL"
                ,"Sortuj po indeksie"
                ,"Sortuj po zarobkach"};
      choice=optionsMenu(sizeof(options)/sizeof(std::string),options);
      switch (choice) {
      case 1: {
        persons_list.sortByPesel();
        break;
      }
      case 2: {
        persons_list.sortByIndex();
        break;
      }
      case 3: {
        persons_list.sortBySalary();
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
      persons_list.findPerson();
      break;
    }
    case 6: {
      persons_list.importData();
      break;
    }
    case 7: {
      persons_list.saveDataBase();
      break;
    }
    case 8: {
      persons_list.modifyData();
      break;
    }
        case 9:{

    persons_list.randomData();
    break;
    }

    }
  }
  return 0;
}
