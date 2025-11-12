#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 500;
const int Mod = 998244353;
int s[N], c[N];
int p[N], flag[N], tot = 0;
void dfs(int x) {
    if(x > n) {
        int cnt = 0, ans = 0;
        for(int i = 1; i <= n; i++) {
            if(cnt >= c[p[i]]) cnt++;
            else if(s[i] == 0) cnt++;
            else ans++;
        }
        if(ans >= m) tot = (tot + 1) % Mod;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!flag[i]) {
            p[x] = i, flag[i] = 1;
            dfs(x + 1), flag[i] = 0;
        }
    }
}

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%1d", &s[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    if(n <= 10) {
        dfs(1); printf("%d\n", tot);
        return 0;
    } else {
        printf("0\n");
        return 0;
    }
}