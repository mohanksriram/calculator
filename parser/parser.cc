#include <cmath>
#include "parser.h"

// helper functions
bool isTrignometric(const std::string& str) {
    return ((str == "sin") || (str == "cos") || (str == "tan"));
}

bool isLogarithmic(const std::string& str) {
    return ((str == "log") || (str == "ln"));
}

bool isConstant(const std::string& str) {
    return ((str == "pi") || (str == "e"));
}

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
            while(isdigit(*p) || *p == '.') {
                ++p;
            }
            const std::string str = std::string(base, p);
            tokens.push_back(Token{Token::Type::Number, str});
            // point back to the last digit of the number
            --p;
        } else if(isalpha(*p)) {
            // TODO(Mohan): Handle variables here.
                const char* base = p;
                // consider all consective digits as a single number token
                while(isalpha(*p)) {
                    ++p;
                }
                const std::string str = std::string(base, p);
                if(isTrignometric(str) || isLogarithmic(str)) {
                    tokens.push_back(Token{Token::Type::UnaryFunc, str});
                } else if(isConstant(str)) {
                    tokens.push_back(Token{Token::Type::Constant, str});
                } else {
                    throw std::out_of_range("You have entered an invalid function. Please try again!");
                }
                --p;
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
                default:
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
    std::stack<Token> operators;
    
    int count = 0;
    for(const Token& token: tokens) {
        count++;
        switch (token.type)
        {
            case Token::Type::Number:
                rpn_tokens.push_back(token);
                break;

            case Token::Type::Constant:
                if(token.str == "pi") {
                    rpn_tokens.push_back(Token{Token::Type::Number, std::to_string(M_PI)});
                } else if(token.str == "e") {
                    rpn_tokens.push_back(Token{Token::Type::Number, std::to_string(M_E)});
                }
                break;
                
            case Token::Type::UnaryFunc:
                operators.push(token);
                break;
            
            case Token::Type::Operator:
                while(!operators.empty()) {
                    Token op2 = operators.top();
                    Token op1 = token;
                    if(op2.type != Token::Type::Operator) break;
                    if ((!op1.right_associative && op1.precedence <= op2.precedence) ||
                        (op1.right_associative && op1.precedence < op2.precedence)) {
                            // push top token 
                            rpn_tokens.push_back(op2);
                            operators.pop();
                    } else {
                        // no operator on stack with higher precendence
                        break;
                    }
                }
                operators.push(token);
                break;
            
            case Token::Type::LeftBrace:
                operators.push(token);
                break;

            case Token::Type::RightBrace:
                // evaluate until we reach a left bracket
                while(!operators.empty() && operators.top().type != Token::Type::LeftBrace) {
                    Token op = operators.top();
                    
                    rpn_tokens.push_back(op);
                    operators.pop();
                }
                if(operators.empty() && count < (int)tokens.size()) {
                    throw std::out_of_range("Mismatched paranthesis. Please try again!");
                }
                // std::cout << operators.top().str << std::endl;
                // drop the left bracket
                if(!operators.empty()) {
                    operators.pop();
                }
                // check if function is at the top of the operator stack
                if(!operators.empty()) {
                    Token top_op = operators.top();
                    if(top_op.type == Token::Type::UnaryFunc) {
                        rpn_tokens.push_back(top_op);
                        operators.pop();
                    }
                }
                break;
        default:
            break;
        }
    }
    while(!operators.empty()) {
        Token op = operators.top();
        operators.pop();
        if(op.type == Token::Type::LeftBrace || op.type == Token::Type::RightBrace) {
            throw std::out_of_range("Mismatched paranthesis. Please try again!");
        }

        if(rpn_tokens.size() < 2) {
            throw std::out_of_range("Mismatched operands. Please try again!");
        }

        rpn_tokens.push_back(op);
    }

    return rpn_tokens;
}