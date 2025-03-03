/**
 * @file        TokenType.h
 * @brief       Defines the TokenType enum class for the scanner.
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        02/03/2025
 */

#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

#include <string>

/**
 * @brief All token types recognized by the scanner.
 */
enum class TokenType {
  /* Single-character tokens. */
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  /* One or two character tokens. */
  BANG,
  BANG_EQUAL,
  EQUAL_ASSIGN,
  EQUAL_COMPARE,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  /* Literals. */
  IDENTIFIER,
  STRING,
  NUMBER,

  /* Keywords. */
  AND,
  CLASS,
  ELSE,
  FALSE,
  FUN,
  FOR,
  IF,
  NIL,
  OR,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,

  EOF_LOX,
};

std::string to_str(TokenType type);

#endif /* TOKEN_TYPE_H */
