#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream stream("input.txt");
    std::string text;

    std::vector<std::string> vec;
    size_t sum = 0;
    std::string temp;

    while (std::getline(stream, text)) {
        vec.push_back(text);
    }

    for (size_t i = 0; i < vec[i].size(); ++i) {
        for (size_t j = 0; j < vec[i].size(); ++j) {
            if (vec[i][j] == '*') {
                int counter = 0;
                int val1{}, val2{};
                for (int m = -1; m < 2; ++m) {
                    for (int k = -1; k < 2; ++k) {
                        if (isdigit(vec[i + m][j + k])) {
                            int a = 0;
                            while (isdigit(vec[i + m][j + k - a])) {
                                ++a;
                            }
                            temp = "";
                            while (isdigit(vec[i + m][j + k - a + 1])) {
                                temp += vec[i + m][j + k - a + 1];
                                vec[i + m][j + k - a + 1] = '.';
                                --a;
                            }
                            ++counter;
                            if (val1 == 0) {
                                val1 = std::stoi(temp);
                            } else {
                                val2 = std::stoi(temp);
                            }
                        }
                    }
                }
                if (counter >= 2) {
                    sum += val1 * val2;
                }
            }
        }
    }

    std::cout << sum;

    return EXIT_SUCCESS;
}