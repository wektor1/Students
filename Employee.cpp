#include "Employee.hpp"

Employee::Employee(int salary,  std::string surname,std::string name,std::string pesel,
          std::string sex,std::string addres)
    : Person(surname,name,pesel,sex,addres),m_salary(salary) {}

Employee::~Employee() {}

int Employee::getSalary() { return m_salary; }

void Employee::setSalary(int salary) { m_salary = salary; }
