#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10001;

vector<int> EularSelect(int n) {
    vector<int> prime;
    vector<bool> isPrime(n + 10, true);
    isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == true) {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            isPrime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
    return prime;
}

int main() {
    int n = 0;
    vector<int> memo = EularSelect(maxn);
    while (std::cin >> n) {
        bool flag = false;
        for (int i = 0; i < memo.size(); i++) {
            if (memo[i] % 10 == 1 && memo[i] < n) {
                flag = true;
                std::cout << memo[i] << " ";
            }
        }
        if (!flag) {
            std::cout << -1 << std::endl;
        }
        else {
            std::cout << std::endl;
        }
    }
    system("pause");
    return 0;
}