#ifndef LEXER
#define LEXER

#include <fstream>
#include <iostream>
#include <vector>

enum T_Type { SYMBOL, STRING, CHAR, BINARY_OPERATOR, PUNCTUATION, EQUAL, INT };

// Token
struct Token {
  T_Type type;
  std::string content;
};
// Main function in the lexer, gets the source code and converts it into tokens
void tokenizer(const std::ifstream &src);

inline void printTokens(const std::vector<Token> &tokens) {
  for (const auto &token : tokens) {
    switch (token.type) {
    case SYMBOL:
      std::cout << "SYMBOL: " << token.content << '\n';
      break;
    case STRING:
      std::cout << "STRING: " << token.content << '\n';
      break;
    case CHAR:
      std::cout << "CHAR: " << token.content << '\n';
      break;
    case BINARY_OPERATOR:
      std::cout << "BINARY_OPERATOR: " << token.content << '\n';
      break;
    case PUNCTUATION:
      std::cout << "PUNCTUATION: " << token.content << '\n';
      break;
    case EQUAL:
      std::cout << "EQUAL: " << token.content << '\n';
      break;
    case INT:
      std::cout << "INT: " << token.content << '\n';
      break;
    default:
      std::cout << "Unknown token type\n";
      break;
    }
  }
}
#endif // !LEXER
