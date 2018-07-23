#pragma once

#include "Student.hpp"
#include <vector>
#include <algorithm>

class DataBase {
  std::vector<Student> vec_students;

public:
  DataBase();
  ~DataBase();
  char showMenu() const;
  void addStudent();
  void deleteStudent();
  void showStudents() const;
};
