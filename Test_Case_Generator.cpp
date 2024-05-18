#include "testlib.h"
#include <bits/stdc++.h>

const int MAX_N = 110000;
std::vector<int> gprimes;
std::vector<bool> is_prime(MAX_N + 1, true);

// We use the sieve of Erastosthenes to reduce the time complexity
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(MAX_N); ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            gprimes.push_back(i);
        }
    }
}

std::vector<int> generate_consecutive_primes(int start, int count) {
    std::vector<int> primes;
    int num = start;
    while (1) {
        if (is_prime[num]) break;
        else num++;
    }
    auto index = lower_bound(gprimes.begin(), gprimes.end(), num);  //We are using binary search here to make the code more efficient
    for (int i=0; i < count; i++) {
        primes.push_back(*(index+i));
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

bool all_pairs_same_color(const std::vector<std::pair<std::string, std::string>>& pairs) {
    std::string first_color = pairs[0].second;
    for (const auto& pair : pairs) {
        if (pair.second != first_color) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    //We get the no. of test cases
    int test_count = opt<int>("test-count");
    sieve();
    for (int test_case = 0; test_case < test_count; ++test_case) {
        std::vector<char> curses = {'A', 'B', 'C', 'D', 'E', 'F'};
        std::vector<std::string> colors = {"Red", "Green", "Blue"};

        std::vector<std::string> curse_colors;
        std::vector<std::pair<std::string, std::string>> pairs;
        
        // Ensure valid pairs
        do {
            // We assign colors randomly to each curse
            curse_colors.clear();
            curse_colors.resize(curses.size());
            for (int i = 0; i < (int)curses.size(); ++i) {
                curse_colors[i] = colors[rnd.next(0, 2)];
            }

            // Generate pairs
            pairs.clear();
            std::set<std::pair<char, char>> pairs_set;
            std::vector<char> remaining_curses = curses;
            while (pairs_set.size() < 3) {
                char first = remaining_curses.back();
                remaining_curses.pop_back();
                char second = remaining_curses.back();
                remaining_curses.pop_back();
                pairs_set.insert(std::minmax(first, second));
            }

            // Fill remaining pairs randomly, ensuring no duplicates
            while (pairs_set.size() < 6) {
                char first = curses[rnd.next(0, 5)];
                char second = curses[rnd.next(0, 5)];
                if (first != second) {
                    pairs_set.insert(std::minmax(first, second));
                }
            }

            // Generate the color combinations for the pairs
            for (const auto& p : pairs_set) {
                pairs.push_back({std::string() + p.first + p.second, combine_colors(curse_colors[p.first - 'A'], curse_colors[p.second - 'A'])});
            }

        } while (all_pairs_same_color(pairs));

        // Print pairs and sum of primes
        for (const auto& pair : pairs) {
            std::cout << pair.first << " " << pair.second << "\n";
        }

        int start_prime = rnd.next(2, 100000);
        std::vector<int> primes = generate_consecutive_primes(start_prime, 6);
        int sum_primes = std::accumulate(primes.begin(), primes.end(), 0);
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

        // We assign potencies based on sorted order
        for (int i = 0; i < (int)curse_infos.size(); ++i) {
            curse_infos[i].potency = primes[i];
        }

        std::sort(curse_infos.begin(), curse_infos.end(), [](const CurseInfo& a, const CurseInfo& b) {
            return a.curse < b.curse;
        });

//         Uncomment the following to view the correct answers of each test case
//         for (const auto& info : curse_infos) {
//             std::cout << info.curse << " " << info.color << " " << info.potency << "\n";
//         }
    }

    return 0;
}
