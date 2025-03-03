/**
 * @file        Scanner.cpp
 * @brief       Implements the Scanner class for the Lox interpreter.
 *
 * @author      Victor Miranda <victoralexandre499@gmail.com>
 * @version     1.0.0
 * @date        03/03/2025
 */

#include "core/Scanner.h"
#include "core/Lox.h"

std::vector<Token> Scanner::scan_tokens() {
  while (!source.empty()) {
    start = current;
    scan_token();
  }

  /* add EOF token after all tokens have been scanned */
  add_token(TokenType::EOF_LOX);

  return tokens;
}

void Scanner::scan_token() {
  /* scan the next token */
  char c = source[current];
  current++;

  switch (c) {
  case '(':
    add_token(TokenType::LEFT_PAREN);
    break;
  case ')':
    add_token(TokenType::RIGHT_PAREN);
    break;
  case '{':
    add_token(TokenType::LEFT_BRACE);
    break;
  case '}':
    add_token(TokenType::RIGHT_BRACE);
    break;
  case ',':
    add_token(TokenType::COMMA);
    break;
  case '.':
    add_token(TokenType::DOT);
    break;
  case '-':
    add_token(TokenType::MINUS);
    break;
  case '+':
    add_token(TokenType::PLUS);
    break;
  case ';':
    add_token(TokenType::SEMICOLON);
    break;
  case '*':
    add_token(TokenType::STAR);
    break;
  case '!':
    add_token(match_token('=') ? TokenType::BANG_EQUAL : TokenType::BANG);
    break;
  case '=':
    add_token(match_token('=') ? TokenType::EQUAL_COMPARE
                               : TokenType::EQUAL_ASSIGN);
    break;
  case '<':
    add_token(match_token('=') ? TokenType::LESS_EQUAL : TokenType::LESS);
    break;
  case '>':
    add_token(match_token('=') ? TokenType::GREATER_EQUAL : TokenType::GREATER);
    break;
  case '/':
    if (!match_token('/')) {
      add_token(TokenType::SLASH);
      break;
    }

    /* Consume comment until new line loop */
    while (source[current] != '\n' && current < source.size()) {
      current++;
    }

    break;
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    line++;
    break;
  default:
    Lox::report_error("Unexpected character.", "", line);
    break;
  }
}

void Scanner::add_token(TokenType type) { add_token(type, nullptr); }

void Scanner::add_token(TokenType type, void *literal) {
  std::string text = source.substr(start, current - start);
  tokens.push_back(Token(type, text, line, literal));
}

bool Scanner::match_token(char expected) {
  if (current >= source.size()) {
    return false;
  }
  if (source[current] != expected) {
    return false;
  }

  current++;
  return true;
}
