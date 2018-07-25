#include "Person.hpp"
#include <string>

Person::Person(std::string surname, std::string name,
               std::string pesel, std::string addres)
               : m_surname(surname), m_name(name), m_pesel(pesel)
               , m_addres(addres){
                  if(m_name[m_name.size()-1]== 'a') m_sex="female";
                  else m_sex="male";
}

Person::~Person() {}


void Person::setAddres(std::string addres) { m_addres = addres; }
/*
void Person::setName(std::string name) { m_name = name; }

void Person::setSurname(std::string surname) { m_surname = surname; }

void Person::setPesel(std::string pesel) { m_pesel = pesel; }

void Person::setSex(std::string sex) { m_sex = sex; }
*/
std::string Person::getAddres() const { return m_addres; }

std::string Person::getName() const { return m_name; }

std::string Person::getSurname() const { return m_surname; }

std::string Person::getSex() const { return m_sex; }

std::string Person::getPesel() const { return m_pesel; }
