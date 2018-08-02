#pragma once

#include "Person.hpp"
#include <memory>
#include <stdlib.h>
#include <vector>

class DataBase {
  std::vector<std::shared_ptr<Person>> vec_persons;

public:
  DataBase();
  ~DataBase();
  int showMenu() const;
  void addPerson();
  void sortByIndex();
  void sortBySalary();
  void sortByPesel();
  void deletePerson();
  void showPersons() const;
  void importData();
  void findPerson();
  void saveDataBase();
  void modifyData();
  void randomData();
};
