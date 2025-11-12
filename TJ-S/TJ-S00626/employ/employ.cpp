#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
char s[510] = {0};
int c[510] = {0}, p[510] = {0};
int main () {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    int res = 0;
    do {
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (s[i - 1] == '0' || (cnt >= c[p[i]])) {
                cnt ++;
                continue;
            }
        }
        if ((n - cnt) >= m) {
            res ++;
            res %= mod;
        }
    } while(next_permutation(p + 1, p + 1 + n));
    printf("%d\n", res);
    return 0;
}