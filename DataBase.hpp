#pragma once

#include "Student.hpp"
#include <stdlib.h>
#include <vector>
#include <memory>


class DataBase {

  std::vector<std::shared_ptr<Student>> vec_students;

public:
  DataBase();
  ~DataBase();
  char showMenu() const;
  void addStudent();
  void deleteStudent();
  void showStudents() const;
};
