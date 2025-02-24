/**
 * @file        lox.h
 * @brief       Declares the Lox interpreter class
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        24/02/2025
 */

#ifndef LOX_H
#define LOX_H

#include <string>

/**
 * @brief The Lox interpreter class
 */
class Lox {
public:
  Lox();
  ~Lox();

  /**
   * @brief Read and run a Lox script file
   *
   * @param script The path to the script file
   * @return int 0 on success, -1 on failure
   */
  int run_file(std::string script);

  /**
   * @brief Run the Lox REPL
   *
   * @return int 0 on success
   */
  int run_repl();

private:
  int run(std::string line);
};

#endif /* LOX_H */
