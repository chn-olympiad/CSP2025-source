#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
signed main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
int n,m;
cin>>n>>m;
int ans=1;
for(int i=2;i<=n;i++){
	ans=ans*i%mod;
}
cout<<ans;
	   return 0;
}


