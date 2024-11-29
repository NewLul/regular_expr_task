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

TEST(regexpr, sum) {
    regular_expr a(2);
    regular_expr b(2);
    a.prefix[0] = 1;
    a.prefix[1] = 2;
    b.whole[0] = 0;
    b.whole[1] = 1;
    b.prefix[0] = 0;
    b.prefix[1] = 3;
    regular_expr result = sum(a, b, 2);
    std::vector<size_t> test = {0, 2};
    ASSERT_EQ(result.prefix, test);
    ASSERT_EQ(result.whole, b.whole);
}

TEST(regexpr, concat) {
    regular_expr a(2);
    regular_expr b(2);
    a.prefix[0] = 0;
    a.prefix[1] = 2;
    a.whole[0] = 0;
    b.whole[0] = 0;
    b.whole[1] = 1;
    b.prefix[0] = 0;
    b.prefix[1] = 3;
    regular_expr result = concat(a, b, 2);
    std::vector<size_t> test_prefix = {0, 2};
    std::vector<size_t> test_whole = {0, 1};
    ASSERT_EQ(result.prefix, test_prefix);
    ASSERT_EQ(result.whole, test_whole);
}

TEST(regexpr, clini) {
    regular_expr a(5);
    a.prefix[0] = 1;
    a.prefix[1] = 2;
    a.whole[2] = 2;
    regular_expr result = clini(a, 5);
    std::vector<size_t> test_prefix = {0, 2, 2, 4, 4};
    std::vector<size_t> test_whole = {0, size_t_max, 2, size_t_max, 4};
    ASSERT_EQ(result.prefix, test_prefix);
    ASSERT_EQ(result.whole, test_whole);
}