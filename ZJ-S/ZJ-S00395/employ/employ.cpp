// 意义不明的骗不到分的代码 

#include <bits/stdc++.h>
#define fr {freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);}
#define qr {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define int long long
#define N 505
#define P 998244353
using namespace std;

int n,m;
string s;
int c[N];
int ans = 1;
int cnt = 0;
int min_=  1000;

signed main(){
    qr;
    fr;
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        if(c[i] != 0) cnt++,min_ = min(min_,c[i]);
    }
    for(int i = n;i >= 1;i--){
        ans *= i;
        ans %= P;
    }
    cout << ans;
    return 0;
}
