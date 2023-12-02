#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream stream("input.txt");
    std::string text;
    int sum_gameid = 0;

    while (std::getline(stream, text)) {
        int maxr = 12, maxg = 13, maxb = 14, rmoffset = 2;
        auto z = text.find(':');
        int gameid = std::stoi(text.substr(5, z));
        for (int i = z; i < text.size(); ++i) {
            char current = text[i];
            char next = text[i + 1];
            char prev = text[i - 1];
            std::string temp;
            int torm = 0;

            if (current == ';') {
                maxr = 12;
                maxg = 13;
                maxb = 14;
            }

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
                        maxr -= torm;
                        break;
                    case 'g':
                        maxg -= torm;
                        break;
                    case 'b':
                        maxb -= torm;
                        break;
                }
            }
            if ((maxr < 0) || (maxg < 0) || (maxb < 0)) break;
        }
        if ((maxr >= 0) && (maxg >= 0) && (maxb >= 0)) {
            sum_gameid += gameid;
        }
    }

    std::cout << "sum game id: " << sum_gameid;

    return 0;
}