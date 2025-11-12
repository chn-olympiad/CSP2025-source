#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int a[maxn][5] = {0};
pair <int, int> b[maxn];
ll res = 0;
int n;
void dfs (int dep, int c1, int c2, int c3, ll sum) {
    if (dep == n + 1) {
        if (max(c1, max(c2, c3)) <= (n / 2)) {
            res = max(res, sum);
        }
        return;
    }
    dfs(dep + 1, c1 + 1, c2, c3, sum + a[dep][0]);
    dfs(dep + 1, c1, c2 + 1, c3, sum + a[dep][1]);
    dfs(dep + 1, c1, c2, c3 + 1, sum + a[dep][2]);
}
void chmax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}
int P[10] = {0};
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < 3; j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    res = 0;
    if (n <= 16) {
        res = 0;
        dfs(1, 0, 0, 0, 0);
        printf("%lld\n", res);
        // for (int i = 1; i <= n; i ++) {
        //     printf("%d ", lis[i]);
        // }
        // printf("\n");
    }
    else {
        P[1] = 1, P[2] = 2, P[3] = 3;
        ll ans = 0;
        do {
            set <int > S;
            for (int i = 1; i <= n; i ++) {
                S.insert(i);
            }
            ll num = 0;
            for (int p = 1; p <= 3; p ++) {
                set <int > :: iterator it = S.begin();
                int tot = 0;
                for (; it != S.end(); it++) {
                    int i = (*it);
                    b[++ tot].first = a[i][P[p] - 1] - max(a[i][P[p] % 3], a[i][(P[p] + 1) % 3]);
                    b[tot].second = i;
                }
                sort(b + 1, b + 1 + tot);
                int cnt = 0, siz = S.size();
                // for (int i = siz; i >= 1; i --) {
                //     printf("(%d %d) ", b[i].first, b[i].second);
                // }
                // printf("\n");
                for (int i = siz; i >= 1; i --) {
                    if (cnt < (n >> 1) && (b[i].first >= 0 || p == 3)) {
                        cnt ++;
                        num += a[b[i].second][P[p] - 1];
                        // printf("%d ", a[b[i].second][P[p] - 1]);
                        S.erase(b[i].second);
                    }
                    else {
                        break;
                    }
                }
                // printf("\n");
            }
            ans = max(ans, num);
        } while(next_permutation(P + 1, P + 4));
        printf("%lld\n", ans);
    }
}
int main () {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T --) {
        solve();
    }
    return 0;
}