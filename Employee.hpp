#pragma once
#include "Person.hpp"
#include <string>

class Employee : public Person {
  int m_salary;

public:
  Employee(int salary, std::string name, std::string surname,
           std::string addres, std::string sex, std::string pesel);
  ~Employee();
  void setSalary(int salary);
  int getSalary();
};
