/**
 * @file        Token.cpp
 * @brief       Implements the Token class. A token represents a single unit of
 *              a Lox program, such as a keyword, literal, or operator.
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        02/03/2025
 */

#include "core/Token.h"

std::string Token::to_string() {
  return "Token<" + to_str(type) + ", " + lexeme + ">";
}
