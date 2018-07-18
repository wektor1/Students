#pragma once

#include "Student.hpp"
#include <map>
class DataBase {
  std::map<int, Student> map_students;
public:
  void showMenu();
  void addStudent();
  void deleteStudent();
  void showStudents();
};
