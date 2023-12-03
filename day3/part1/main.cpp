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
            if (vec[i][j] != '.' && !isdigit(vec[i][j])) {
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
                            sum += std::stoi(temp);
                        }
                    }
                }
            }
        }
    }

    std::cout << sum;

    return EXIT_SUCCESS;
}