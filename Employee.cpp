#include "Employee.hpp"

Employee::Employee(int salary, std::string name, std::string surname,
                   std::string addres, std::string sex, std::string pesel)
    : m_salary(salary) {
  setName(name);
  setAddres(addres);
  setSurname(surname);
  setSex(sex);
  setPesel(pesel);
}
Employee::~Employee() {}

int Employee::getSalary() { return m_salary; }

void Employee::setSalary(int salary) { m_salary = salary; }
