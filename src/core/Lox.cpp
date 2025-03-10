/**
 * @file        lox.cpp
 * @brief       Implements the Lox interpreter class
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        24/02/2025
 */

#include "core/Lox.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sysexits.h>

Lox::Lox() {}

Lox::~Lox() {}

int Lox::run_file(std::string script) {
  std::cout << "Running script " << script << std::endl;

  std::filesystem::path script_path(script);
  std::ifstream script_file(script_path);

  if (!script_file.is_open()) {
    std::cerr << "ERROR: Could not open file " << script << std::endl;
    return -1;
  }

  std::string line;
  while (std::getline(script_file, line)) {
    run(line);

    if (had_error) {
      exit(EX_DATAERR);
    }
  }

  return 0;
}

int Lox::run_repl() {
  std::string line;
  while (std::getline(std::cin, line)) {
    run(line);
  }

  return 0;
}

int Lox::run(std::string line) {
  std::cout << line << std::endl;

  return 0;
}

int Lox::report_error(std::string msg, std::string where, int line) {
  std::cerr << "[line " << line << "] Error" << where << ": " << msg
            << std::endl;

  had_error = true;

  return 0;
}
