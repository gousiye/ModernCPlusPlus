#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using ull = unsigned long long;

using namespace std;

int m = 0;
int n = 0;

int ReflectGet(const char& ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    }
    else return -1;
}

void ReflectSet(char& ch, const int& num) {
    if (num >= 0 && num <= 9) {
        ch = num + '0';
    }
    else ch = num - 10 + 'A';
}

void Divide(string& str, char& remainder) {
    int borrow = 0;
    for (int i = 0; i < str.size(); i++) {
        int num = ReflectGet(str[i]) + m * borrow;
        borrow = num % n;
        num = num / n;
        ReflectSet(str[i], num);
    }
    ReflectSet(remainder, borrow);
    int index = 0;
    while (index < str.size() && str[index] == '0') {
        index += 1;
    }
    str.erase(str.begin(), str.begin() + index);
}

int main() {
    std::cin >> m >> n;
    string str = "";
    string ans = "";
    std::cin >> str;
    char remainder = '\0';
    while (str.size()) {
        Divide(str, remainder);
        ans.push_back(remainder);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] >= 'A' && ans[i] <= 'Z') {
            ans[i] += 32;
        }
    }
    std::cout << ans << std::endl;
    system("pause");
    return 0;
}