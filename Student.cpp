#include "Student.hpp"

Student:: Student(int index,  std::string surname,std::string name,std::string pesel,
          std::string sex,std::string addres)
    : Person(surname,name,pesel,sex,addres),m_index(index) {}

Student::~Student() {}

//void Student::setIndex(int index) { m_index = index; }

int Student::getIndex() { return m_index; }
