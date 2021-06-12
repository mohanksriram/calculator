#include <deque>
#include <string>
#include <iostream>

class Token {
    public:
        enum class Type {
            Unknown,
            Number,
            Operator,
            LeftBrace,
            RightBrace
        };
        Token(Type t, const std::string&, int precedence, bool ra);
        const Type type;
        const std::string str;
        const int precedence;
        const bool right_associative;
};

class Parser {
    public:
        virtual std::deque<Token> tokenize(const std::string& expr) = 0;
        virtual std::deque<Token> rpn(const std::deque<Token>& tokens) = 0;
};

class CalculatorParser: Parser {
    public:
        std::deque<Token> tokenize(const std::string& expr) override;
        std::deque<Token> rpn(const std::deque<Token>& tokens) override;
};