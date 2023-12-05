#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>

int main() {
    std::ifstream stream("input.txt");
    std::vector<int> keys;
    std::string text;
    std::string temp;
    std::map<int, long> map;
    int k{};

    while (std::getline(stream, text)) {
        auto start = text.find_first_of(':') + 1;
        auto start2 = text.find_first_of('|') + 1;

        auto w = text.substr(0, start - 1);
        std::string tmp;
        std::istringstream q(w);
        while (std::getline(q, tmp, ' ')) {
        }
        int currline = std::stoi(tmp);

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
                    ++k;
                }
            }
        }
        map[currline] += 1;

        for (int i = 1; i < k + 1; ++i) {
            map[currline + i] += map[currline];
        }
    }

    std::cout << "sum: "
              << std::accumulate(map.begin(), map.end(), 0,
                                 [](const int prev, const std::pair<int, long>& entry) { return prev + entry.second; });

    return EXIT_SUCCESS;
}