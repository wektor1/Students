#pragma once

class Student {
private:
    int m_index;
    std::string m_surname;
    std::string m_name;
public:
    void Student(int index,std::string surname,std::string name);
    void ~Student();

    void setIndex(int index);
    void setName(std::string name);
    void setSurname(std::string surname);

    int getIndex();
    std::string getSurname();
    std::string getName();
};

