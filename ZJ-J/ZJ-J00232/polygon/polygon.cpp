#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define endl '\n'
#define MOD 998224353ll

using namespace std;
using LL = long long;

const int N = 5005;
LL a[N], n;

bool check(LL x){
    LL sum = 0, maxa = -1, cnt = 0; 
    for(int i = 1; i <= n; i ++){
        if(x & 1){
            sum += a[i];
            cnt ++;
            maxa = max(maxa, a[i]);
        }
        x = (x>>1);
    }
    if(cnt >= 3 && sum > 2*maxa)return true;
    else return false;
}

int main(){

    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    IOS
    cin >> n;
    for(int i = 1; i <= n; i ++)cin >> a[i];

    if(n <= 20) {
        LL ans = 0;
        for(LL i = 0; i < (1<<n); i ++){
            if(check(i))ans = (ans+1)%MOD;
        }
        cout << ans << endl;
        return 0;
    }else{
        //当a[i]全为1时 每个数字都可以选或不选  答案为2^n - Cn1 - Cn2
        LL ans = 1;
        for(LL i = 1; i <= n; i ++){
            ans = (ans << 1) % MOD;
        }
        ans = (ans + MOD - n)%MOD;
        ans = (ans + MOD - n*n-1)%MOD; 
        cout << ans << endl;
        return 0;
    }

    return 0;
}
