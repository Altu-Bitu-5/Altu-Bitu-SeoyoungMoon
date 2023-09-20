#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<int> countCharacters(const std::string& word) {
    std::vector<int> counts(26, 0);
    for(char c : word) {
        counts[c - 'A']++;
    }
    return counts;
}

bool isSimilar(const std::vector<int>& a, const std::vector<int>& b) {
    int diff_count = 0;
    for(int i = 0; i < 26; ++i) {
        diff_count += abs(a[i] - b[i]);
    }
    return diff_count <= 2;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> words(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> words[i];
    }

    auto first_word_counts = countCharacters(words[0]);
    int similar_count = 0;

    for(int i = 1; i < n; ++i) {
        int length_diff = std::abs((int)words[i].length() - (int)words[0].length());
        if(length_diff > 1) continue;

        auto current_word_counts = countCharacters(words[i]);
        if(isSimilar(first_word_counts, current_word_counts)) {
            similar_count++;
        }
    }

    std::cout << similar_count << std::endl;

    return 0;
}
