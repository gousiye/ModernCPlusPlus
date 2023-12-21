#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 30;

int arr[MAXN];
int memo[MAXN];
int index = 0;
int n = 0;

int BinarySearch(int left, int right, int val) {
    while (left + 1 != right) {
        int mid = (left + right) / 2;
        if (memo[mid] >= val) left = mid;
        else right = mid;
    }
    return right;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (i == 0) {
            memo[0] = arr[0];
        }
        else {
            if (arr[i] <= memo[index]) {
                index += 1;
                memo[index] = arr[i];
            }
            else {
                int tIndex = BinarySearch(-1, index + 1, arr[i]);
                //找到memo中第一个小于arr[i]的坐标， 肯定存在， 否则else判断矛盾
                memo[tIndex] = arr[i];
            }
        }
    }
    printf("%d", index + 1);
    system("pause");
    return 0;
}