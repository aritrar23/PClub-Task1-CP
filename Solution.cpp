#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000000;
vector<int> gprimes;
vector<bool> is_prime(MAX_N + 1, true);

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
//This is a function that will return the nearest prime to a number, greater than the number if bullion == 1
//and lesser than the number if bullion == 0
int find_nearest_prime(int num, int bullion) {
    if (bullion) {
        num++;
        while (1) {
            if (is_prime[num]) return num;
            else num++;
        }
    } else {
        num--;
        while (1) {
            if (is_prime[num]) return num;
            else num --;
        }
    }
}

// Function to find the 6 consecutive primes whose sum equals the given sum
// To reduce the time complexity, we first find the average of the sum, then find nearest primes to that average,
// using the current average of the primes as an indicator of whether we would find the next prime 
// greater than all the current primes or lesser than all the current primes.
vector<int> find_consecutive_primes_with_sum(int sum) {
    double real_avg = (double)sum/6;
    vector <int> primes;
    int num = find_nearest_prime((int) real_avg,1);
    primes.push_back(num);
    double current_avg = (double)(accumulate(primes.begin(), primes.end(), 0))/(primes.size());
    
    while (primes.size() < 6) {
        if (current_avg < real_avg) {
            num = find_nearest_prime(primes[primes.size()-1], 1);
        } else {
            num = find_nearest_prime(primes[0], 0);
        }
        primes.push_back(num);
        sort(primes.begin(), primes.end());
        current_avg = (accumulate(primes.begin(), primes.end(), 0))/(primes.size());
    }
    return primes;
}

string combine_colors(const string& c1, const string& c2) {
    if ((c1 == "Red" && c2 == "Green") || (c1 == "Green" && c2 == "Red")) return "Brown";
    if ((c1 == "Red" && c2 == "Blue") || (c1 == "Blue" && c2 == "Red")) return "Purple";
    if ((c1 == "Green" && c2 == "Blue") || (c1 == "Blue" && c2 == "Green")) return "Teal";
    if (c1 == c2) return c1;
    return "";
}

bool backtrack(int index, vector<char>& curses, vector<string>& colors, unordered_map<string, string>& pair_color_map, unordered_map<char, string>& curse_color_map) {
    if (index == (int)curses.size()) {
        // Check if the current assignment satisfies all pairs
        for (const auto& pair : pair_color_map) {
            char first = pair.first[0];
            char second = pair.first[1];
            string result_color = pair.second;
            if (combine_colors(curse_color_map[first], curse_color_map[second]) != result_color) {
                return false;
            }
        }
        return true;
    }

    char current_curse = curses[index];
    for (const string& color : colors) {
        curse_color_map[current_curse] = color;
        if (backtrack(index + 1, curses, colors, pair_color_map, curse_color_map)) {
            return true;
        }
        curse_color_map.erase(current_curse);
    }
    return false;
}

int main() {
    sieve(); 

    vector<pair<string, string>> pairs(6);
    int s;

    for (int i = 0; i < 6; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    cin >> s;

    vector<int> consecutive_primes = find_consecutive_primes_with_sum(s);
    
    vector<char> curses = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<string> colors = {"Red", "Green", "Blue"};
    
    unordered_map<string, string> pair_color_map;
    for (const auto& pair : pairs) {
        pair_color_map[pair.first] = pair.second;
    }
    
    unordered_map<char, string> curse_color_map;
    if (!backtrack(0, curses, colors, pair_color_map, curse_color_map)) {
        cerr << "No valid color assignment found.\n";
        return 1;
    }
    
    struct CurseInfo {
        char curse;
        string color;
        int potency;
    };

    vector<CurseInfo> curse_infos;
    for (char c = 'A'; c <= 'F'; ++c) {
        curse_infos.push_back({c, curse_color_map[c], 0});
    }

    // We sort curses by color and then lexicographically within the same color group
    sort(curse_infos.begin(), curse_infos.end(), [](const CurseInfo& a, const CurseInfo& b) {
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
        curse_infos[i].potency = consecutive_primes[i];
    }

    sort(curse_infos.begin(), curse_infos.end(), [](const CurseInfo& a, const CurseInfo& b) {
        return a.curse < b.curse;
    });

    for (const auto& info : curse_infos) {
        cout << info.curse << " " << info.color << " " << info.potency << "\n";
    }

    return 0;
}
