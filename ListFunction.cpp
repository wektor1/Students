#include "ListFunction.hpp"
#include <iostream>
#include <string>

void addStudent(std::map<int, Student>& map_student) {
    int index;
    std::string name,surname;
    std::cout<<"Podaj imie studenta: ";
    std::cin.get();
    std::getline(std::cin,name);
    std::cout<<"Podaj nazwisko studenta: ";
    std::getline(std::cin,surname);
    std::cout<<"Podaj index: ";
    std::cin>>index;

    Student* p_student=new Student(index,surname,name);
    map_student.insert (std::pair <int,Student> (p_student->getIndex(),* p_student));
}
