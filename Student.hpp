#pragma once
#include "Person.hpp"
#include <string>

class Student : public Person {
  int m_index;

public:
  Student(int index,  std::string surname,std::string name,std::string pesel,
          std::string sex,std::string addres);
  ~Student();
  //void setIndex(int index);
  int getIndex();
};
