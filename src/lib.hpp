#include <limits>
#include <vector>
#include <string>

constexpr size_t size_t_max = std::numeric_limits<size_t>::max();

struct regular_expr {
    std::vector<size_t> prefix; // minimal length of word, that s[1 .. prefix[i]] is [x]^i
    std::vector<size_t> whole; // whole[j] = j if it can be [x]^j
    // size of vectors is equal to [length]

    regular_expr(size_t length);
};

regular_expr sum(const regular_expr& lhs, const regular_expr& rhs, size_t length);

regular_expr concat(const regular_expr& lhs, const regular_expr& rhs, size_t length);

regular_expr clini(const regular_expr& re, size_t length);

size_t solve(std::string str, char x, size_t length);