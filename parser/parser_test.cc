#include "gtest/gtest.h"
#include "parser/parser.h"

TEST(ParserTest, BracesTest) {
    CalculatorParser parser;
    std::string expr = "(2+3)";
    std::deque<Token> tokens = parser.tokenize(expr);
    std::deque<Token> expected_tokens;

    expected_tokens.push_back(Token{Token::Type::UnaryFunc, "(", 0, 0});
    expected_tokens.push_back(Token{Token::Type::UnaryFunc, "2", 0, 0});
    expected_tokens.push_back(Token{Token::Type::UnaryFunc, "+", 0, 0});
    expected_tokens.push_back(Token{Token::Type::UnaryFunc, "3", 0, 0});
    expected_tokens.push_back(Token{Token::Type::UnaryFunc, ")", 0, 0});

    for(int i=0; i<tokens.size(); i++) {
        ASSERT_EQ(tokens[i].str, expected_tokens[i].str);
    }
}
