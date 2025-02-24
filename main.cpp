#include <iostream>

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cout
        << "Usage: cpplox [script] to run a script or cpplox to enter the REPL"
        << std::endl;
  }
  if (argc == 2) {
    std::cout << "Running script" << std::endl;
  } else {
    std::cout << "Running REPL" << std::endl;
  }
  return 0;
}
