#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <set>

bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

std::vector<int> generate_consecutive_primes(int start, int count) {
    std::vector<int> primes;
    int num = start;
    while ((int)primes.size() < count) {
        if (is_prime(num)) {
            primes.push_back(num);
        }
        ++num;
    }
    return primes;
}

std::string combine_colors(const std::string& c1, const std::string& c2) {
    if ((c1 == "Red" && c2 == "Green") || (c1 == "Green" && c2 == "Red")) return "Brown";
    if ((c1 == "Red" && c2 == "Blue") || (c1 == "Blue" && c2 == "Red")) return "Purple";
    if ((c1 == "Green" && c2 == "Blue") || (c1 == "Blue" && c2 == "Green")) return "Teal";
    if (c1 == "Red" && c2 == "Red") return "Red";
    if (c1 == "Green" && c2 == "Green") return "Green";
    if (c1 == "Blue" && c2 == "Blue") return "Blue";
    return "";
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int num_test_cases = 7;
    // We generate 7 test cases with this code
    for (int test_case = 0; test_case < num_test_cases; ++test_case) {
        std::vector<char> curses = {'A', 'B', 'C', 'D', 'E', 'F'};
        std::vector<std::string> colors = {"Red", "Green", "Blue"};

        // We assign colors randomly to each curse
        std::vector<std::string> curse_colors(curses.size());
        for (int i = 0; i < (int)curses.size(); ++i) {
            curse_colors[i] = colors[rnd.next(0, 2)];
        }

        // We generate 6 consecutive primes starting from a random prime number
        int start_prime = rnd.next(2, 100000) + test_case * 100; // Ensuring different starting points for each test case
        std::vector<int> primes = generate_consecutive_primes(start_prime, 6);
        int sum_primes = std::accumulate(primes.begin(), primes.end(), 0);

        // We generate random pairs of curses
        std::set<std::pair<char, char>> pairs_set;
        while (pairs_set.size() < 6) {
            char first = curses[rnd.next(0, 5)];
            char second = curses[rnd.next(0, 5)];
            if (first != second) {
                pairs_set.insert(std::minmax(first, second));
            }
        }

        std::vector<std::pair<std::string, std::string>> pairs;
        for (const auto& p : pairs_set) {
            pairs.push_back({std::string() + p.first + p.second, combine_colors(curse_colors[p.first - 'A'], curse_colors[p.second - 'A'])});
        }

    
        for (const auto& pair : pairs) {
            std::cout << pair.first << " " << pair.second << "\n";
        }

        
        std::cout << sum_primes << "\n";

        struct CurseInfo {
            char curse;
            std::string color;
            int potency;
        };

        std::vector<CurseInfo> curse_infos;
        for (int i = 0; i < (int)curses.size(); ++i) {
            curse_infos.push_back({curses[i], curse_colors[i], primes[i]});
        }

        // We sort curses by color and then lexicographically within the same color group
        std::sort(curse_infos.begin(), curse_infos.end(), [](const CurseInfo& a, const CurseInfo& b) {
            if (a.color == b.color) {
                return a.curse < b.curse;
            } else {
                if (a.color == "Red") return true;
                if (b.color == "Red") return false;
                if (a.color == "Green") return true;
                if (b.color == "Green") return false;
                return false;
            }
        });

        //We assign potencies based on sorted order
        for (int i = 0; i < (int)curse_infos.size(); ++i) {
            curse_infos[i].potency = primes[i];
        }

        std::sort(curse_infos.begin(), curse_infos.end(), [](const CurseInfo& a, const CurseInfo& b) {
            return a.curse < b.curse;
        });

        
        //Please uncomment the following if you want to view the correct answer of each test case
//        for (const auto& info : curse_infos) {
//            std::cout << info.curse << " " << info.color << " " << info.potency << "\n";
//        }

        std::cout << "===\n";
    }
    
    return 0;
}
