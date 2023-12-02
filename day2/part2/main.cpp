#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream stream("input.txt");
    std::string text;
    int sum = 0;

    while (std::getline(stream, text)) {
        int minr = 0, ming = 0, minb = 0, rmoffset = 2;
        auto z = text.find(':');
        for (int i = z; i < text.size(); ++i) {
            char current = text[i];
            char next = text[i + 1];
            char prev = text[i - 1];
            std::string temp;
            int torm = 0;

            if (isdigit(current) && !isdigit(prev)) {
                if (isdigit(next)) {
                    temp = std::string(1, current) + std::string(1, next);
                    torm = std::stoi(temp);
                    rmoffset = 3;
                } else {
                    torm = current - '0';
                    rmoffset = 2;
                }

                char toremove = text[i + rmoffset];

                switch (toremove) {
                    case 'r':
                        if (torm > minr) minr = torm;
                        break;
                    case 'g':
                        if (torm > ming) ming = torm;
                        break;
                    case 'b':
                        if (torm > minb) minb = torm;
                        break;
                }
            }
        }
        sum += (minr * ming * minb);
    }

    std::cout << "sum: " << sum;

    return 0;
}