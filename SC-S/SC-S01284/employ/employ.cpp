#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll mod=998244353;

int main(){
    #ifndef Reimu
        freopen("employ.in","r",stdin);
        freopen("employ.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    ll ans=1;
    for(int i=1;i<=n;i++)ans=ans*i%mod;
    cout<<ans;
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/