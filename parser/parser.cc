#include "parser.h"

Token::Token(Type t, const std::string& s, int precedence = -1, bool ra = false)
    : type{t}, str{s}, precedence{precedence}, right_associative{ra} {}

std::deque<Token> CalculatorParser::tokenize(const std::string& expr) {
    std::deque<Token> tokens;

    for(const char* p = expr.c_str(); *p; ++p) {
        if(isblank(*p)) {
            // skip blank space
        } else if(isdigit(*p)) {
            const char* base = p;
            // consider all consective digits as a single number token
            while(isdigit(*p)) {
                ++p;
            }
            const std::string str = std::string(base, p);
            tokens.push_back(Token{Token::Type::Number, str});
            // point back to the last digit of the number
            --p;
        //} else if(isalpha(*p)) {
            // TODO(Mohan): Handle trignometric, log functions, constants, and variables here. 
        } else {
            Token::Type t = Token::Type::Unknown;
            int precendence = -1;
            bool right_associative = false;
            switch(*p) {
                case '(':
                    t = Token::Type::LeftBrace; 
                    break;
                case ')':
                    t = Token::Type::RightBrace;
                    break;
                case '^':
                    t = Token::Type::Operator;
                    precendence = 4;
                    right_associative = true;
                    break;
                case '*':
                    t = Token::Type::Operator;
                    precendence = 3;
                    break;
                case '/':
                    t = Token::Type::Operator;
                    precendence = 3;
                    break;
                case '+':
                    t = Token::Type::Operator;
                    precendence = 2;
                    break;
                case '-':
                    t = Token::Type::Operator;
                    precendence = 2;
                    break;
            }
            // exit with error if the token is unknown
            if(t == Token::Type::Unknown) {
                //std::cout << "about to throw an exception!" << std::endl;
                throw std::out_of_range("You have entered an invalid expression. Please try again!");
            }
            const std::string str = std::string(1, *p);
            tokens.push_back(Token{t, str, precendence, right_associative});
        }
    }
    return tokens;
}

std::deque<Token> CalculatorParser::rpn(const std::deque<Token>& tokens) {
    std::deque<Token> rpn_tokens;
    return rpn_tokens;
}