#include "optionsMenu.hpp"
#include "kbhit.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int optionsMenu(int number_of_lines, std::string *options) {
  char c;
  int line = 1, loop = 1;
  while (loop) {
    system("clear");

    for (int i = 0; i < number_of_lines; i++) {
      if (i == line) {
        std::cout << "\033[1;43m" << options[i] << "\033[0m" << std::endl;
      } else {
        std::cout << options[i] << std::endl;
      }
    }
    while (!kbhit(c)) {
      usleep(7000);
    }
    changeLine(c, line, loop, number_of_lines);
  }
  return line;
}

void changeLine(char c, int &line, int &loop, int number_of_lines) {
  if (c == 65 && line > 1)
    line--;
  if (c == 66 && line < number_of_lines)
    line++;
  if (c == 10)
    loop = 0;
}
