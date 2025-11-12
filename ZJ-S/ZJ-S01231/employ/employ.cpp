#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 600;
const int mod =  998244353;

int c[MAXN];
string s;
int n,m;
int flag = 1;
int fac[MAXN];

void init(int n){
    fac[0] = 1;
    for(int i = 1;i<=n;i++){
        fac[i] = (fac[i-1]*i) % mod;
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<=n;i++){
        if(!s[i-1]) flag = 0;
    }
    for(int i = 1;i<=n;i++){
        cin>>c[i];
    }
    init(n);
    if(flag){
        cout<<fac[n];
    }
}