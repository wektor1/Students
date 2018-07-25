#pragma once
#include <string>

class Person {
protected:
  std::string m_surname;
  std::string m_name;
  std::string m_pesel;
  std::string m_sex;
  std::string m_addres;

public:
  Person(std::string surname, std::string name, std::string pesel, std::string addres);

   virtual ~Person();

   void setAddres(std::string addres);
   virtual int getIndex() {return 0;}
   virtual int getSalary() {return 0;}
   std::string getSurname() const;
   std::string getName() const;
   std::string getAddres() const;
   std::string getPesel() const;
   std::string getSex() const;
};
