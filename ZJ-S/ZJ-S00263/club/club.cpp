#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'


using namespace std;
using LL = long long;

const int N = 1e5+5;
LL a[N][3], n;

LL dp[205][205][205];

LL f(int i, int j, int k){
    if(i + j + k == n && i <= n/2 && j <= n/2 && k <= n/2)return 0;

    if(dp[i][j][k] == 0){
        LL maxx = 0;
        if(i + 1 <= n/2)maxx = max(maxx, f(i+1, j, k) + a[i+1+j+k][0]);
        if(j + 1 <= n/2)maxx = max(maxx, f(i, j+1, k) + a[i+j+1+k][1]);
        if(k + 1 <= n/2)maxx = max(maxx, f(i, j, k+1) + a[i+j+k+1][2]);
        dp[i][j][k] = maxx;
    }

    return dp[i][j][k];
}

void  solve(){
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 3; j ++)cin >> a[i][j];
    }

    if(n < 1e5){
        LL ans = f(0, 0, 0);
        cout << ans << endl;
        return;
    }else if(n >= 1e5 && a[1][1] == 0 && a[1][2] == 0 && a[2][1] == 0 && a[2][2] == 0){
        vector<LL> b(n+5);
        for(int i = 1; i <= n; i ++)b[i] = a[i][0];

        sort(b.begin()+1, b.begin()+n+1);

        LL ans = 0;
        for(int i = n; i >= n/2; i--)ans += b[i];
        cout << ans << endl;
        return;
    }else{
        LL ans = 0;
        for(int i = 1; i <= n; i ++){
            ans += max(a[i][0], a[i][1]);
        }
        cout << ans << endl;
        return;
    }
}


int main(){

    IOS
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)solve();


    return 0;
}