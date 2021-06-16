// A Scientific Calculator
#include <cstdio>
#include <exception>
#include <iostream>
#include <limits>
#include <string>

#include "parser/parser.h"
#include "evaluator/evaluator.h"

#define DEBUG 0

int main() {
    std::cout << "Welcome to Calculator!" << "\n";
    std::cout << "Please enter the mode of operation " << "\n";
    std::cout << "1: Infix or 2: Postfix" << "\n";
    std::string mode;
    std::cin >> mode;
    std::cout << "Please enter the expression to compute" << std::endl;
    std::cin >> std::ws;

    std::string expr;
    std::getline(std::cin, expr);

    CalculatorParser parser;
    Evaluator evaluator;
    double res = 0.0;
    try {
        std::deque<Token> tokens = parser.tokenize(expr);
        if (DEBUG) {
            for(int i = 0, size = tokens.size(); i < size; ++i) {
                    std::cout << tokens[i].str << (i < size-1 ? " ": "\n"); 
            }
        }
        if(mode == "1") {
            std::deque<Token> rpn_tokens = parser.rpn(tokens);
            if (DEBUG) {
                for(int i = 0, size = rpn_tokens.size(); i < size; ++i) {
                    std::cout << rpn_tokens[i].str << (i < size-1 ? " ": "\n"); 
                }
            }
            res = evaluator.evaluate(rpn_tokens);
        } else {
            res = evaluator.evaluate(tokens);
        }
        
        std::cout << "res: " << res << std::endl;

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
