#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
signed main (){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<'\n';
	return 0;
}
