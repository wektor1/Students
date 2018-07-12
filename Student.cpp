#include "Student.hpp"

void Student::Student(int index,std::string surname, std::string name) {
    m_index=index;
    m_surname=surname;
    m_name=name;
}

void Student::~Student() {}

void Student::setIndex(int index) {
    m_index=index;
}

void Student::setName(std::string name) {
    m_name=name;
}

void Student::setSurname(std::string surname) {
    m_surname=surname;
}

int Student::getIndex() {
    return m_index;
}

std::string Student::getName() {
    return m_name;
}

std::string Student::getSurname() {
    return m_surname;
}

