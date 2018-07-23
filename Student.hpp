#pragma once
#include "Person.hpp"
#include <string>

class Student : public Person {
  int m_index;

public:
  Student(int index, std::string name, std::string surname, std::string addres,
          std::string sex, std::string pesel);
  ~Student();
  void setIndex(int index);
  int getIndex();
};
