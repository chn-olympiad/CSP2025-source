#include<bits/stdc++.h>
using namespace std;
int const mod=998244353;
int main(){
    int res=1;
    for (int i=1;i<=100;++i) res=1ll*res*i%mod;
    cout<<res<<'\n';
}