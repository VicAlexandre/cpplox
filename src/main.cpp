/**
 * @file        main.cpp
 * @brief       Main entry point for the Lox interpreter
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        24/02/2025
 */

#include "core/Lox.h"

#include <iostream>
#include <sysexits.h>

int main(int argc, char *argv[]) {
  Lox lox;

  if (argc > 2) {
    std::cout
        << "ERROR: Invalid number of arguments. Expected 0 or 1 argument.\n"
        << "Usage:\tcpplox [script] to run a script\n"
        << "\tcpplox to enter the REPL\n";
    exit(EX_USAGE);
  } else if (argc == 2) {
    lox.run_file(argv[1]);
  } else {
    lox.run_repl();
  }

  return 0;
}
