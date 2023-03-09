#include "lexer.hpp"
#include <cctype>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

void tokenizer(std::ifstream &src) {
  std::vector<Token> tokens;
  std::string line;
  while (std::getline(src, line)) {
    auto begin = line.begin() - 1;
    while (begin++ != line.end()) {
      // Punctuations
      if (*begin == '(' || *begin == ')' || *begin == '{' || *begin == '}')
        tokens.push_back((Token){T_Type::PUNCTUATION, std::string(1, *begin)});
      // Binary operators
      else if (*begin == '*' || *begin == '+' || *begin == '-' || *begin == '/')
        tokens.push_back(
            (Token){T_Type::BINARY_OPERATOR, std::string(1, *begin)});
      // Equal
      else if (*begin == '=')
        tokens.push_back((Token){T_Type::EQUAL, std::string(1, *begin)});
      // Strings
      else if (*begin == '"') {
        begin++;
        std::string str;
        while (begin != line.end() && *begin != '"')
          str += *begin++;
        tokens.push_back((Token){T_Type::STRING, str});
      }
      // Ints
      else if (isdigit(*begin)) {
        std::string num;
        while (begin != line.end() && isdigit(*begin))
          num += *begin++;
        tokens.push_back((Token){T_Type::INT, num});
        begin--;
        // Symbols
      } else if (isalpha(*begin) || *begin == '_') {
        std::string id;
        while (begin != line.end() && (isalnum(*begin) || *begin == '_'))
          id += *begin++;
        tokens.push_back((Token){T_Type::SYMBOL, id});
        begin--;
      }
    }
  }
  printTokens(tokens);
}

int main(int argc, char *argv[]) {
  std::ifstream src("../test/test1.dpy");

  tokenizer(src);
  src.close();
  return 0;
}
