#pragma once
#include "Person.hpp"
#include <string>

class Employee : public Person {
  int m_salary;

public:
  Employee(int salary,std::string surname,std::string name,std::string pesel,
          std::string sex,std::string addres);
  ~Employee();
  void setSalary(int salary);
  int getSalary();
};
