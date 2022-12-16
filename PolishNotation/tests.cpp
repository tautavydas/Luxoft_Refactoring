#include "PolishNotation.hpp"
#include <gtest/gtest.h>

TEST(Refactoring, Test1) {
  PolishNotation stack;
  EXPECT_EQ(stack.process("1"), 0);
  stack.clean();
  EXPECT_EQ(stack.process("1+"), 1);
}

TEST(Refactoring, Test2) {
  PolishNotation stack;
  EXPECT_EQ(stack.process("1+"), 1);
}