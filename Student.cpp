#include "Student.hpp"

Student::Student(int index, std::string name, std::string surname,
                 std::string addres, std::string sex, std::string pesel)
    : m_index(index) {
  setName(name);
  setSurname(surname);
  setAddres(addres);
  setSex(sex);
  setPesel(pesel);
}
Student::~Student() {}

void Student::setIndex(int index) { m_index = index; }

int Student::getIndex() { return m_index; }
