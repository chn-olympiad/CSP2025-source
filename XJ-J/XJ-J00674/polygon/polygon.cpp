#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,mod=998244353;
int n,a[N];
long long ans=1;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ans+=(n-i)*(n-i-1)%mod;
    }
    cout<<ans;
    return 0;
}