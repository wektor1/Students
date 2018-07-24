#include "Person.hpp"
#include <string>

Person::Person(std::string surname, std::string name,
               std::string pesel,std::string sex,
               std::string addres)
               : m_surname(surname), m_name(name), m_pesel(pesel)
               , m_sex(sex), m_addres(addres) {}

Person::~Person() {}


void Person::setAddres(std::string addres) { m_addres = addres; }

std::string Person::getAddres() const { return m_addres; }

std::string Person::getName() const { return m_name; }

std::string Person::getSurname() const { return m_surname; }

std::string Person::getSex() const { return m_sex; }

std::string Person::getPesel() const { return m_pesel; }
