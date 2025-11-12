#include<bits/stdc++.h>
#define int long long
#define P 998244353
#define N 5010
using namespace std;

int n, m, a[N], f[N][N][2];

signed main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; ++i)
        cin >> a[i], m=max(m, a[i]);
    sort(a+1, a+n+1);
    m+=5;
    for(int i=1; i<=n; ++i)
        f[i][a[i]][0]=1;
    for(int i=1; i<n; ++i)
        for(int j=0; j<=m; ++j) {
            f[i+1][j][0]=(f[i+1][j][0]+f[i][j][0])%P;
            f[i+1][j][1]=(f[i+1][j][1]+f[i][j][1])%P;

            f[i+1][min(m, j+a[i+1])][1]=
                (f[i+1][min(m, j+a[i+1])][1]+
                f[i][j][0]+f[i][j][1])%P;
        }

    int rsl=0;
    for(int i=1; i<=n; ++i)
        for(int j=a[i]+1; j<=m; ++j)
            rsl=(rsl+f[i-1][j][1])%P;
    cout << rsl << '\n';
    return 0;
}