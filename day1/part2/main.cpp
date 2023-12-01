#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <string_view>

int util(std::string_view sv) {
    auto is_digit = [](int c) { return std::isdigit(c); };
    auto first = std::find_if(sv.begin(), sv.end(), is_digit);
    auto last = std::find_if(sv.rbegin(), sv.rend(), is_digit);
    std::string a = std::to_string((*first - 48)) + std::to_string((*last - 48));
    return std::stoi(a);
}

int main() {
    std::size_t sum = 0;
    const std::unordered_map<std::string, int> vals{{"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
                                                    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    std::ifstream stream("input.txt");
    std::string text;
    while (std::getline(stream, text)) {
        std::string temp;
        for (const auto& [key, val] : vals) {
            while (text.contains(key)) {
                auto f = text.find(key);
                temp = text.replace(f, key.length() - 2, key.substr(0, 2) + std::to_string(val));
            }
        }
        if (!temp.empty()) {
            sum += util(temp);
        } else {
            sum += util(text);
        }
    }

    std::cout << sum;

    return 0;
}