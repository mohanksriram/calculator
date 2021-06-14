#include "evaluator.h"

typedef double (*EvaluateFunc)(const double &a, const double &b);

struct OperatorContract {
    EvaluateFunc func;
    OperatorContract(EvaluateFunc f): func{f} {}
};

static std::map<std::string, OperatorContract> op_contracts = {
    {"+", OperatorContract([](const double &a, const double &b) { return a + b; })},
    {"-", OperatorContract([](const double &a, const double &b) { return a - b; })},
    {"*", OperatorContract([](const double &a, const double &b) { return a * b; })},
    {"/", OperatorContract([](const double &a, const double &b) { return a / b; })},
    {"^", OperatorContract([](const double &a, const double &b) { return std::pow(a, b); })}
    };


double Evaluator::evaluate(std::deque<Token> rpn_tokens) {
    std::stack<Token> number_tokens;
    
    while(!rpn_tokens.empty()) {

        Token op = rpn_tokens.front();

        if(op.type == Token::Type::Operator) {
            // pop two operands
            try {
                Token operand1 = number_tokens.top();
                number_tokens.pop();
                Token operand2 = number_tokens.top();
                number_tokens.pop();

                std::map<std::string, OperatorContract>::iterator search = op_contracts.find(op.str);
                if (search != op_contracts.end()) {
                    // Evaluate with function pointer
                    double val = search->second.func(std::stod(operand2.str), std::stod(operand1.str));
                    const std::string str = std::to_string(val);
                    number_tokens.push(Token{Token::Type::Number, str, 0, 0});
                } else {
                    throw std::out_of_range("Operator: " + op.str + " not supported. Please try again!");                 
                }
            }
            catch(...) {
                throw;
            }
            rpn_tokens.pop_front();
        } else if(op.type == Token::Type::Number) {
            number_tokens.push(op);
            rpn_tokens.pop_front();
        } else {
            throw std::out_of_range("Mismatched operators. Please try again!"); 
        }
    }
    return std::stod(number_tokens.top().str);
}