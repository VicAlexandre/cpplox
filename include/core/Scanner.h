/**
 * @file        Scanner.h
 * @brief       Defines the Scanner class for the Lox interpreter.
 *
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        03/03/2025
 */

#ifndef SCANNER_H
#define SCANNER_H

#include "core/Token.h"

#include <string>
#include <vector>

/**
 * @brief The lexical analyzer class, also known as the scanner, for the Lox
 * interpreter.
 */
class Scanner {
public:
  Scanner(std::string source) : source(source) {}
  ~Scanner() {}

  /**
   * @brief Scans the source code and returns a vector of tokens.
   *
   * @return std::vector<Token> The vector of processed tokens.
   */
  std::vector<Token> scan_tokens();

private:
  std::string source;
  std::vector<Token> tokens;
  unsigned int start = 0;
  unsigned int current = 0;
  unsigned int line = 1;

  void scan_token();

  void add_token(TokenType type);

  void add_token(TokenType type, void *literal);

  bool match_token(char expected);
};

#endif /* SCANNER_H */
