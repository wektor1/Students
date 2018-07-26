#include "Student.hpp"

Student::Student(int index, std::string surname, std::string name,
                 std::string pesel, std::string addres)
    : Person(surname, name, pesel, addres), m_index(index) {}

Student::~Student() {}

int Student::getIndex() { return m_index; }

void Student::setIndex(int index) { m_index = index; }
