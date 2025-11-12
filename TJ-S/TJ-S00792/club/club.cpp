#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef long long LL;
inline LL read() {
    LL num = 0, sign = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') sign = (ch == '-' ? -1 : 1), ch = getchar();
    while ('0' <= ch && ch <= '9') num = (num << 3) + (num << 1) + ch - '0', ch = getchar();
    return (sign == 1 ? num : -num);
}
const int MAXN = 1e5 + 8;
int n, a[MAXN][4], d[MAXN];
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T = read();
    while (T--) {
        n = read();
        LL lmt = (n >> 1), ans = 0, sz[4] = {};
        priority_queue<tuple<LL, int, int> > pq[4];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) a[i][j] = read();
            if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
                d[i] = 1, ans += a[i][1], sz[1]++;
                pq[1].push({a[i][2] - a[i][1], i, 2});
                pq[1].push({a[i][3] - a[i][1], i, 3});
            } else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
                d[i] = 2, ans += a[i][2], sz[2]++;
                pq[2].push({a[i][1] - a[i][2], i, 1});
                pq[2].push({a[i][3] - a[i][2], i, 3});
            } else {
                d[i] = 3, ans += a[i][3], sz[3]++;
                pq[3].push({a[i][1] - a[i][3], i, 1});
                pq[3].push({a[i][2] - a[i][3], i, 2});
            }
        }
        while (sz[1] > lmt || sz[2] > lmt || sz[3] > lmt) {
            if (sz[1] > lmt) {
                auto [dif, idx, dst] = pq[1].top();
                pq[1].pop();
                int otr = 6 - 1 - dst;
                if (d[idx] != 1 || sz[dst] >= lmt) continue;
                ans += dif, d[idx] = dst, sz[1]--, sz[dst]++;
                pq[dst].push({a[idx][1] - a[idx][dst], idx, 1});
                pq[dst].push({a[idx][otr] - a[idx][dst], idx, otr});
            } else if (sz[2] > lmt) {
                auto [dif, idx, dst] = pq[2].top();
                pq[2].pop();
                int otr = 6 - 2 - dst;
                if (d[idx] != 2 || sz[dst] >= lmt) continue;
                ans += dif, d[idx] = dst, sz[2]--, sz[dst]++;
                pq[dst].push({a[idx][2] - a[idx][dst], idx, 2});
                pq[dst].push({a[idx][otr] - a[idx][dst], idx, otr});
            } else {
                auto [dif, idx, dst] = pq[3].top();
                pq[3].pop();
                int otr = 6 - 3 - dst;
                if (d[idx] != 3 || sz[dst] >= lmt) continue;
                ans += dif, d[idx] = dst, sz[3]--, sz[dst]++;
                pq[dst].push({a[idx][3] - a[idx][dst], idx, 3});
                pq[dst].push({a[idx][otr] - a[idx][dst], idx, otr});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
