#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

using ll = long long;

const int MAXM = 100010;
constexpr int MAXN = 400040;

int n, m;
ll val[MAXN];
ll arr[MAXM];
int left[MAXN], right[MAXN];
int lch[MAXN], rch[MAXN];
ll lazy[MAXN];
int cnt;

ll BuildTree(int index, int st, int ed) {
    left[index] = st;
    right[index] = ed;
    if (st == ed) {
        val[index] = arr[st];
        return val[index];
    }
    int mid = (st + ed) / 2;
    cnt = cnt + 1;
    lch[index] = cnt;
    cnt = cnt + 1;
    rch[index] = cnt;
    ll leftSum = BuildTree(lch[index], st, mid);
    ll rightSum = BuildTree(rch[index], mid + 1, ed);
    val[index] = leftSum + rightSum;
    return val[index];
}

void Modify(int index, int st, int ed, ll k) {
    //修改区间与当前区间没有交集
    if (st > right[index] || ed < left[index]) return;
    // 修改区间完全覆盖当前节点区间
    if (st <= left[index] && ed >= right[index]) {
        val[index] = val[index] + (right[index] - left[index] + 1) * k;
        lazy[index] += k;
        return;
    }
    //修改区间与当前节点区间有部分交集
        //如果当前区间有lazy标签，下放到子标签
    if (lazy[index] != 0) {
        lazy[lch[index]] += lazy[index];
        lazy[rch[index]] += lazy[index];
        val[lch[index]] += (right[lch[index]] - left[lch[index]] + 1) * lazy[index];
        val[rch[index]] += (right[rch[index]] - left[rch[index]] + 1) * lazy[index];
        lazy[index] = 0;
    }
    //遍历左孩子，右孩子
    Modify(lch[index], st, ed, k);
    Modify(rch[index], st, ed, k);
    //更新当前节点的值
    val[index] = val[lch[index]] + val[rch[index]];
}

ll Query(int index, int st, int ed) {
    int l = left[index], r = right[index];
    // 查询区间与当前节点区间没有交集
    if (st > right[index] || ed < left[index]) return 0;
    // 查询区间完全覆盖当前节点区间
    if (st <= left[index] && ed >= right[index]) {
        return val[index];
    }
    //查询区间与当前节点有部分交集
        //如果有lazy标记，下放到子节点
    if (lazy[index]) {
        lazy[lch[index]] += lazy[index];
        lazy[rch[index]] += lazy[index];
        val[lch[index]] += (right[lch[index]] - left[lch[index]] + 1) * lazy[index];
        val[rch[index]] += (right[rch[index]] - left[rch[index]] + 1) * lazy[index];
        lazy[index] = 0;
    }
    ll leftSum = Query(lch[index], st, ed);
    ll rightSum = Query(rch[index], st, ed);
    return leftSum + rightSum;
}

int main() {
    memset(lch, -1, sizeof(lch));
    memset(rch, -1, sizeof(rch));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    ll temp = BuildTree(0, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int flag = 0;
        int st = 0, ed = 0;
        ll k = 0;
        scanf("%d %d %d", &flag, &st, &ed);
        if (flag == 2) {
            ll tmpAns = Query(0, st - 1, ed - 1);
            printf("%lld\n", tmpAns);
        }
        else {
            scanf("%lld", &k);
            Modify(0, st - 1, ed - 1, k);
        }
    }
    system("pause");
    return 0;
}