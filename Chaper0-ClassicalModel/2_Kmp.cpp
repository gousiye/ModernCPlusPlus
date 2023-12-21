#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> memo;

int number;

void PrinMemo() {
    for (int i = 0; i < memo.size(); i++) {
        printf("%d ", memo[i]);
    }
}


void GetMemo(const string& pattern) {
    memo[0] = 0;
    for (int i = 1; i < pattern.size(); i++) {
        int j = i - 1;
        while (1) {
            if (pattern[i] == pattern[memo[j]]) {
                memo[i] = memo[j] + 1;
                break;
            }
            else if (j == 0) {
                memo[i] = 0;
                break;
            }
            else {
                j = memo[j] - 1;
                j = max(j, 0);
            }
        }
    }
}

void Kmp(const string str, const string pattern) {
    int i = 0;
    int j = 0;
    while (i < str.size()) {
        if (str[i] == pattern[j]) {
            i += 1;
            j += 1;
        }
        else if (j > 0) {
            j = memo[j - 1];
        }
        else {
            i += 1;
        }
        if (j == pattern.size()) {
            //printf("%d\n", i - pattern.size() + 1);
            j = memo[j - 1];
            number += 1;
        }
    }
}


int main() {
    string str = "";
    string pattern = "";
    std::cin >> str >> pattern;
    memo.resize(pattern.size());
    GetMemo(pattern);
    Kmp(str, pattern);
    // PrinMemo();
    std::cout << number;
    system("pause");
    return 0;
}