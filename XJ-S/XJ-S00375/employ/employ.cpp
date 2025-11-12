#include<bits/stdc++.h>
using namespace std;
const int N = 505;
const long long MOD = 998244353;
long long ans = 1;
string s;
int c[N],zr;
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    cin >> s;
    for(int i = 1;i <= n;i++){
        cin >> c[i];
        if(c[i] == 0)   zr++;
    }
    if(m > n-zr)    cout << 0;
    else{
        for(int i = 1;i <= n;i++){
            ans = (ans*i) % MOD;
        }
        cout << ans;
    }
    return 0;
}