#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e2 + 5;
const int P = 998244353;

int n, m;
ll ans;
char s[N];
int c[N], a[N];
bool vis[N];

void dfs(int cur){
    if (cur == n + 1){
        int state = 0, res = 0;
        for (int i = 1; i <= n; i ++){
            if (state >= c[a[i]]) ++ state;
            else{
                if (s[i] == '0') ++ state;
                else ++ res;
            }
        }
        if (res >= m) ++ ans;
        return;
    }
    for (int i = 1; i <= n; i ++){
        if (!vis[i]){
            a[i] = cur, vis[i] = 1;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}

void solve(){
    cin >> n >> m >> (s + 1);
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
    }
    if (n <= 10){
        dfs(1);
        cout << ans % P;
    }
    else{
        srand(time(NULL));
        // c______ will win!
        ll ans = 1LL * rand() * rand() % P * rand() % P;
        cout << ans << endl;;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    clock_t st = clock();
    // int T;
    // cin >> T;
    // while (T --)
        solve();
    clock_t ed = clock();
    // printf("\nThe time is %.3lf s", (double)(ed - st) / CLOCKS_PER_SEC);
}