#include<iostream>
#include"showMenu.hpp"
#include"Student.hpp"
#include<map>

int main() {
        std::map<int,Student> map_students;
        int loop=1, t = -1;
        while(loop==1) {

                t = showMenu();
                switch (t) {
                        case 0:
                                loop=0;
                                break;
                        case 1:
                        //	addStudent(map_students);
                                break;
                        case 2:
                        //	deleteStudent(map_students);
                                break;
                        case 3:
                        //	showStudents(map_students);
                                break;
                }
        }
    return 0;
}
