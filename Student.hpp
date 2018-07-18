#pragma once
#include <string>

class Student {
private:
  int m_index;
  std::string m_surname;
  std::string m_name;

public:
  Student(int index, std::string surname, std::string name);
  ~Student();

  void setIndex(int index);
  void setName(std::string name);
  void setSurname(std::string surname);

  int getIndex() const;
  std::string getSurname() const;
  std::string getName() const;
};
