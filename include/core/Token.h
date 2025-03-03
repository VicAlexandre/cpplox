/**
 * @file        Token.h
 * @brief       Declares the Token class. A token represents a single unit of
 *              a Lox program, such as a keyword, literal, or operator.
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        02/03/2025
 */

#ifndef TOKEN_H
#define TOKEN_H

#include "enums/TokenType.h"

#include <string>
class Token {
public:
  Token(TokenType type, std::string lexeme, unsigned int line, void *literal)
      : type(type), lexeme(lexeme), line(line), literal(literal) {}
  ~Token() {}

  std::string to_string();

private:
  TokenType type;
  std::string lexeme;
  unsigned int line;
  void *literal;
};

#endif /* TOKEN_H */
