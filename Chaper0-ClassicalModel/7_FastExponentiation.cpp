#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ull = unsigned long long;


int main() {
    int a = 0;
    int b = 0;
    int mode = 0;
    string std = "";
    std::cin >> a >> b >> mode;
    ull tmp = a;
    int ans = 1;
    int tb = b;
    while (tb > 0) {
        if (tb % 2) {
            ans = (ans * tmp) % mode;
        }
        tmp = (tmp * tmp) % mode;
        tb /= 2;
    }
    // std::cout << ans % mode << std::endl;
    printf("%d^%d mod %d=%d\n", a, b, mode, ans % mode);
    system("pause");
    return 0;
}