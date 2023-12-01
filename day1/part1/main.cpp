#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

int main() {
    std::size_t sum = 0;
    std::ifstream stream("input.txt");
    std::string text;
    auto is_digit = [](int c) { return std::isdigit(c); };
    while (std::getline(stream, text)) {
        auto first = std::find_if(text.begin(), text.end(), is_digit);
        auto last = std::find_if(text.rbegin(), text.rend(), is_digit);
        std::string a = std::to_string((*first - 48)) + std::to_string((*last - 48));
        sum += std::stoi(a);
    }

    std::cout << sum;

    return 0;
}