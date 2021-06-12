// A Scientific Calculator
#include <cstdio>
#include <exception>
#include <iostream>
#include <string>

#include "parser/parser.h"

int main() {
    std::cout << "Welcome to Calculator!" << "\n";
    std::cout << "Please enter the expression to compute" << "\n";

    std::string expr;
    std::getline(std::cin, expr);

    CalculatorParser parser;
    try {
        std::deque<Token> tokens = parser.tokenize(expr);
        for(const Token& token: tokens) {
            std::cout << token.str << std::endl;
        }
    }
    catch (...) {
        try {
            throw;
        }
        catch(std::out_of_range& e) {
             std::cout << e.what() << std::endl;
        }
        
    }

    return 0;   
}
