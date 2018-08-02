#include "peselValidator.hpp"
#include <array>
#include <sstream>
#include <string>

bool peselValidator(const Person &person) {
  bool validation = true;
  std::string s_pesel = person.getPesel();
  std::array<int, 11> single_numbers;
  std::array<std::stringstream, 11> ss_pesel;
  for (int i = 0; i < 11; i++) {
    ss_pesel[i] << s_pesel[i];
    ss_pesel[i] >> single_numbers[i];
  }
  if (s_pesel.length() != 11) {
    validation = false;
  } else if ((single_numbers[10] % 2 == 0 && person.getSex() == "male") ||
             (single_numbers[10] % 2 == 1 && person.getSex() == "female")) {
    validation = false;
  } else if ((1 * single_numbers[0] + 3 * single_numbers[1] +
              7 * single_numbers[2] + 9 * single_numbers[3] +
              1 * single_numbers[4] + 3 * single_numbers[5] +
              7 * single_numbers[6] + 9 * single_numbers[7] +
              1 * single_numbers[8] + 3 * single_numbers[9] +
              1 * single_numbers[10]) %
                 10 !=
             0) {
    validation = false;
  }

  return validation;
}
