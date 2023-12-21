#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;

int a[maxn];
int N = 0;


void PartitionSort(int* arr, int st, int ed) {
    if (st >= ed) return;
    int mid = arr[(st + ed) / 2];   // arr may change, therefore cannot use arr[(st + ed)/ 2]
    int i = st;
    int j = ed;
    while (i <= j) {
        while (arr[i] < mid) i += 1; // 
        while (arr[j] > mid) j -= 1;
        if (i <= j) {
            std::swap(arr[i++], arr[j--]); //arr[j + 1..i - 1] = mid 
        }
    }
    PartitionSort(a, st, j);
    PartitionSort(a, i, ed);
}


int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    PartitionSort(a, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    system("pause");
    return 0;
}