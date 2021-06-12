// A Scientific Calculator
#include <iostream>
#include <string>
#include <cstdio>
#include "parser/parser.h"

int main() {
    std::cout << "Welcome to Calculator!" << "\n";
    std::cout << "Please enter the expression to compute" << "\n";

    std::string expr;
    std::getline(std::cin, expr);

    CalculatorParser parser;
    std::deque<Token> tokens = parser.tokenize(expr);

    for(const Token& token: tokens) {
        std::cout << token.str << std::endl;
    }
    return 0;   
}
