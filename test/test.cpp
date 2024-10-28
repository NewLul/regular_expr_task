#include <gtest/gtest.h>
#include "lib.hpp"

TEST(regexpr, sample1) {
    ASSERT_EQ(solve("ab+c.aba.*.bac.+.+*", 'c', 4), -1);
}

TEST(regexpr, sample2) {
    ASSERT_EQ(solve("acb..bab.c.*.ab.ba.+.+*a.", 'b', 2), 4);
}

TEST(regexpr, cool) {
    ASSERT_EQ(solve("bb.*", 'b', 5), 6);
}