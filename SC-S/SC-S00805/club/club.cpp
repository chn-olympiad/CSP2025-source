#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, score[N][3], cnt[3];
//struct score {
//    int a, b, c, mx, mn, cnt, delta;
//    inline score(int a = 0, int b = 0, int c = 0) {
//        this->a = a, this->b = b, this->c = c;
//        this->mx = max(a, max(b, c));
//        this->mn = min(a, min(b, c));
//        this->delta = mx - mn;
//        this->cnt = 0;
//        if (a) this->cnt++;
//        if (b) this->cnt++;
//        if (c) this->cnt++;
//        return ;
//    }
//    inline void read() {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        *this = score(a, b, c);
//        return ;
//    }
//    inline void write() {
//        printf("(%d, %d, %d, %d, %d, %d, %d)\n", this->a, this->b, this->c,
//               this->mx, this->mn, this->delta, this->cnt);
//    }
//} a[N];
//inline bool cmp(const score &a, const score &b) {
//    if (a.cnt != b.cnt) return a.cnt > b.cnt;
//    if (a.mx != b.mx) return a.mx > b.mx;
//    if (a.a != b.a) return a.a > b.a;
//    if (a.b != b.b) return a.b > b.b;
//    return a.c > b.c;
//}
int dfs(int k) {
    if (k == n)
        return 0;
    int res = 0;
    if (cnt[0] < (n >> 1)) {
        cnt[0]++;
        res = max(dfs(k + 1) + score[k][0], res);
        cnt[0]--;
    }
    if (cnt[1] < (n >> 1)) {
        cnt[1]++;
        res = max(dfs(k + 1) + score[k][1], res);
        cnt[1]--;
    }
    if (cnt[2] < (n >> 1)) {
        cnt[2]++;
        res = max(dfs(k + 1) + score[k][2], res);
        cnt[2]--;
    }
    return res;
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &score[i][0], &score[i][1], &score[i][2]);
//        for (int i = 0; i < n; i++)
//            a[i].read();
//        sort(a, a + n, cmp);
//        for (int i = 0; i < n; i++)
//            a[i].write();
//        putchar('\n');
        printf("%d\n", dfs(0));
    }
    return 0;
}