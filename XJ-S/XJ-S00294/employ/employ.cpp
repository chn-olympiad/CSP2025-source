#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n=0;
    long long ans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans=ans*i%mod;
    }
    cout<<ans;
    return 0;
}