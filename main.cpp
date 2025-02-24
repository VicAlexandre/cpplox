/**
 * @file        main.c
 * @brief       Main entry point for the Lox interpreter
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        24/02/2025
 */

#include "lox.h"
#include <iostream>

/**
 * @def USAGE_ERROR
 * @brief The exit code for bad cli usage, as defined in sysexits.h
 */
#define USAGE_ERROR 64

int main(int argc, char *argv[]) {
  Lox lox;

  if (argc > 2) {
    std::cout
        << "ERROR: Invalid number of arguments. Expected 0 or 1 argument.\n"
        << "Usage:\tcpplox [script] to run a script\n"
        << "\tcpplox to enter the REPL\n";
    exit(USAGE_ERROR);
  } else if (argc == 2) {
    lox.run_file(argv[1]);
  } else {
    lox.run_repl();
  }

  return 0;
}
