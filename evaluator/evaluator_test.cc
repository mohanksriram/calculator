#include "gtest/gtest.h"
#include "evaluator/evaluator.h"

TEST(EvaluatorTest, EqualTest) {
    CalculatorParser parser;
    Evaluator evaluator;

    std::string expr = "(3^2+4^2)^0.5";
    std::deque<Token> tokens = parser.tokenize(expr);
    std::deque<Token> rpn_tokens = parser.rpn(tokens);
    double res = evaluator.evaluate(rpn_tokens);
    ASSERT_EQ(res, 5.0);
}
