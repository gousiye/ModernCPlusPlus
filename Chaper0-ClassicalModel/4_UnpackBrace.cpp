#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> unpack(string& str, int& index) {
    vector<string> result;
    while (index < str.size()) {
        if (str[index] == '[') {
            index += 1;
            vector<string> inner = unpack(str, index);
            vector<string> memo = result;
            result.resize(result.size() * inner.size());
            int cnt = 0;
            for (int i = 0; i < memo.size(); i++) {
                for (int j = 0; j < inner.size(); j++) {
                    result[cnt++] = memo[i] + inner[j];
                }
            }
        }
        else if (str[index] == ']') {
            index += 1;
            return result;
        }
        else {
            result.emplace_back("");
            result.back().push_back(str[index]);
            index += 1;
        }
    }
    return result;
}

int main() {
    string str = "";
    string pattern = "";
    std::cin >> str;
    vector<string> ans;
    int st = 0;
    while (st < str.size()) {
        if (str[st] == '[') {
            vector<string> memo = ans;
            if (ans.empty()) {
                ans.push_back(pattern);
                memo = ans;
            }
            else {
                for (int i = 0; i < ans.size(); i++) {
                    memo[i] += pattern;
                }
            }
            pattern = "";
            st += 1;
            vector<string> inner = unpack(str, st);
            ans.resize(memo.size() * inner.size());
            int cnt = 0;
            for (int i = 0; i < memo.size(); i++) {
                for (int j = 0; j < inner.size(); j++) {
                    ans[cnt++] = memo[i] + inner[j];
                }
            }
        }
        else {
            pattern += str[st];
            st += 1;
        }
    }

    if (ans.empty()) {
        ans.push_back(pattern);
    }
    else {
        for (int i = 0; i < ans.size(); i++) {
            ans[i] += pattern;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << std::endl;
    }
    system("pause");
    return 0;
}