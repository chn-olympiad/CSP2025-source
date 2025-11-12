#include<bits/stdc++.h>
using namespace std;

struct People {
    int a[4], d;
} p[100005], sp[100005];

int T, n, num[4], rear;
long long ans;

bool cmp(const People &A, const People &B) {
    return A.d > B.d;
}

bool op(int idx, int x) {
    if (num[x] < n / 2) {
        num[x]++;
        ans += p[idx].a[x];
        return false;
    } else {
        return true;
    }
}

int first_max(int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return 1;
        else
            return 3;
    } else {
        if (b > c)
            return 2;
        else
            return 3;
    }
}

int second_max(int a, int b, int c) {
    if (a > b) {
        if (b > c)
            return 2;
        else {
            if (a > c)
                return 3;
            else
                return 1;
        }
    } else {
        if (a > c)
            return 1;
        else {
            if (b > c)
                return 3;
            else
                return 2;
        }
    }
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        rear = 0;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &p[i].a[1], &p[i].a[2], &p[i].a[3]);
            p[i].d = p[i].a[first_max(p[i].a[1], p[i].a[2], p[i].a[3])] - p[i].a[second_max(p[i].a[1], p[i].a[2], p[i].a[3])];
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            if (op(i, first_max(p[i].a[1], p[i].a[2], p[i].a[3]))) {
                op(i, second_max(p[i].a[1], p[i].a[2], p[i].a[3]));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
