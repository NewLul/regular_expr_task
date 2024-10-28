#include "lib.hpp"
#include <cctype>
#include <string>
#include <vector>
#include <iostream>

int min_re(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return std::min(a, b);
}

regular_expr::regular_expr(size_t length) {
    prefix.assign(length, -1);
    whole.assign(length, -1);
}

regular_expr sum(const regular_expr& lhs, const regular_expr& rhs, size_t length) {
    regular_expr result(length);
    for (size_t i = 0; i < length; ++i) {
        result.prefix[i] = min_re(lhs.prefix[i], rhs.prefix[i]);
        result.whole[i] = min_re(lhs.whole[i], rhs.whole[i]);
    }
    return result;
}

regular_expr concat(const regular_expr& lhs, const regular_expr& rhs, size_t length) {
    regular_expr result(length);
    for (size_t i = 0; i < length; ++i) {
        if (lhs.prefix[i] != -1) {
            result.prefix[i] = min_re(result.prefix[i], lhs.prefix[i] + rhs.prefix[0]);
        }
        
        for (size_t j = 0; j <= i; ++j) {
            if (lhs.whole[j] != -1 && rhs.prefix[i - j] != -1) {
                result.prefix[i] = min_re(result.prefix[i], j + rhs.prefix[i - j]);
            }
        }

        for (size_t j = 0; j <= i; ++j) {
            if (lhs.whole[j] != -1 && rhs.whole[i - j] != -1)
            result.whole[i] = min_re(result.whole[i], i);
        }
    }
    return result;
}

regular_expr clini(const regular_expr& re, size_t length) {
    regular_expr result = re;
    result.prefix[0] = result.whole[0] = 0;
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j <= i && i + j < length; ++j) {
            if (result.whole[i] == -1 || result.whole[j] == -1) continue;
            result.whole[i + j] = i + j;
        }
    }
    
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j < length; ++j) {
            if (result.whole[i] == -1 || result.prefix[j] == -1) continue;
            for (size_t k = 0; k < std::min(length, i + j + 1); ++k) {
                result.prefix[k] = min_re(result.prefix[k], i + result.prefix[j]);
            }
        }
    }
    return result;
}

int solve(std::string str, char x, size_t length) {
    ++length;
    std::vector<regular_expr> st;
    for (size_t i = 0; i < str.size(); ++i) {
        if (isalpha(str[i])) {
            st.push_back(regular_expr(length));
            st.back().prefix[0] = 1;
            if (str[i] == x) {
                st.back().prefix[1] = 1;
                st.back().whole[1] = 1;
            }
        } else if (str[i] == '.') {
            auto lhs = st[st.size() - 2];
            auto rhs = st[st.size() - 1];
            st.pop_back(), st.pop_back();
            st.push_back(concat(lhs, rhs, length));
        } else if (str[i] == '+') {
            auto lhs = st[st.size() - 2];
            auto rhs = st[st.size() - 1];
            st.pop_back(), st.pop_back();
            st.push_back(sum(lhs, rhs, length));
        } else {
            auto re = st[st.size() - 1];
            st.pop_back();
            st.push_back(clini(re, length));
        }
    }
    return st.back().prefix[length - 1];;
}