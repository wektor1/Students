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

  //virtual void setIndex(int index) = 0;
  //virtual void setSalary(int salary) = 0;

  //virtual void setName(std::string name);
  //virtual void setSurname(std::string surname);
   void setAddres(std::string addres);
  //virtual void setPesel(std::string pesel);
  //virtual void setSex(std::string sex);


  virtual int getIndex() {return 0;}
  virtual int getSalary() {return 0;}
   std::string getSurname() const;
   std::string getName() const;
   std::string getAddres() const;
   std::string getPesel() const;
   std::string getSex() const;
};
