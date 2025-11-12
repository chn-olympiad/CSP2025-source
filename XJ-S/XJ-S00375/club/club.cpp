#include<bits/stdc++.h>
using namespace std;
const int N = 205,M = 1e5+10;
long long a[M][5],c[M],dp[N][N][N];
int n,T;
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T--){
        memset(dp,0,sizeof dp);
        cin >> n;
        long long b;
        for(int i = 1;i <= n;i++){
            cin >> a[i][1] >> a[i][2] >> a[i][3];
            b += a[i][2]+a[i][3],c[i] = a[i][1];
        }
        if(b == 0){
            sort(c+1,c+n+1,cmp);
            long long ans = 0;
            for(int i = 1;i <= n/2;i++){
                ans += c[i];
            }
            cout << ans << '\n';
            continue;
        }
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            for(int u2 = 0;u2 <= min(i,n/2);u2++){
                for(int u3 = 0;u3 <= min(i,n/2);u3++){
                    int u1 = i-u2-u3;
                    if(u1 > n/2)    continue;
                    if(u1) dp[i][u1][u2] = max(dp[i][u1][u2],dp[i-1][u1-1][u2]+a[i][1]);
                    if(u2) dp[i][u1][u2] = max(dp[i][u1][u2],dp[i-1][u1][u2-1]+a[i][2]);
                    if(u3) dp[i][u1][u2] = max(dp[i][u1][u2],dp[i-1][u1][u2]+a[i][3]);
                    ans = max(ans,dp[i][u1][u2]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}