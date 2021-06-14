#include <cmath>
#include <deque>
#include <map>
#include <stack>
#include "parser/parser.h"

class Evaluator {
    public:
        double evaluate(std::deque<Token> rpn_tokens);
};