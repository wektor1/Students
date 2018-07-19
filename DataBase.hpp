#pragma once

#include "Student.hpp"
#include <map>
class DataBase {
  std::map<int, Student> map_students;

public:
  DataBase();
  ~DataBase();
  char showMenu() const;
  void addStudent();
  void deleteStudent();
  void showStudents() const;
};
