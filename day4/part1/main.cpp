#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream stream("input.txt");
    std::vector<int> keys;
    std::string text;
    std::string temp;
    int k{};
    int points = 0;

    while (std::getline(stream, text)) {
        auto start = text.find_first_of(':') + 1;
        auto start2 = text.find_first_of('|') + 1;
        keys.clear();
        std::istringstream t(text.substr(start, start2));
        while (std::getline(t, temp, ' ')) {
            if (temp == "|") break;
            if (!temp.empty()) keys.push_back(std::stoi(temp));
        }

        std::istringstream z(text.substr(start2));
        k = 0;
        while (std::getline(z, temp, ' ')) {
            if (!temp.empty()) {
                if (std::find(keys.begin(), keys.end(), std::stoi(temp)) != keys.end()) {
                    k == 0 ? k += 1 : k *= 2;
                }
            }
        }
        points += k;
    }

    std::cout << "points: " << points;

    return EXIT_SUCCESS;
}