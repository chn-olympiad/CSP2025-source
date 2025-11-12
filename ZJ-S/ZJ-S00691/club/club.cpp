#include<bits/stdc++.h>
using namespace std;
// const int N = 1e5 + 5;
#define LL long long
const int N = 2e2 + 5;
int n,a[N][3];
LL f[N][N][N];
LL buf[N];
void solve(){
    cin>>n;
    bool fl = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++)
            cin >> a[i][j];
        if(a[i][1]!=0||a[i][2]!=0)
            fl = 0;
        buf[i] = a[i][0];
    }
    if(fl){
        LL ans = 0;
        sort(buf + 1, buf + 1 + n);
        for (int i = n; i > n / 2;i--)
            ans += buf[i];
        cout << ans << '\n';
        return;
    }
    LL ans = 0;
    memset(f,0xcf,sizeof f);
    f[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i && j <= n / 2;j++)
            for (int k = 0; k + j <= i && k <= n / 2;k++){
                if(i-j-k>n/2) continue;
                if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][0]);
                if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][1]);
                if(i-j-k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][2]);
                if(i==n)
                    ans = max(ans, f[i][j][k]);
            }
    }
    // init(n);
    cout << ans << '\n';
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--) solve();
    return 0;
}
/*

*/
