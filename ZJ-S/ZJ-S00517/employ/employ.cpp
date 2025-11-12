#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ans,n;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n;
	ans=1;
	for (int i=1;i<=n;i++){
	  ans=ans*i%mod;
//	  if (ans==161088479) cout<<i<<endl;
}
	cout<<ans;
}