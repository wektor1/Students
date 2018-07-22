#include "Student.hpp"
#include <string>

Student::Student(int index, std::string surname, std::string name) : 
  m_index(index),
  m_surname(surname),
  m_name(name) {}

Student::~Student() {}

void Student::setIndex(int index) { m_index = index; }

void Student::setName(std::string name) { m_name = name; }

void Student::setSurname(std::string surname) { m_surname = surname; }

int Student::getIndex() const { return m_index; }

std::string Student::getName() const { return m_name; }

std::string Student::getSurname() const { return m_surname; }
