#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1,mod=998244353,m;
string s;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=1,x;i<=n;i++)
	{
		ans=ans*i%mod;
		cin>>x;
	 } 
	cout<<ans;
	return 0;
}

