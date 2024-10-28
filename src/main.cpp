#include "lib.hpp"
#include <iostream>

int main() {
    std::string s;
    char x;
    size_t length;
    std::cin >> s >> x >> length;    

    int result = solve(s, x, length);
    std::cout << result << '\n';
    return 0;
}
