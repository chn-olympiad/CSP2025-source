#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int ans=1;
	for(int i=1;i<=n;i++)
		ans*=i,ans%=mod;
	cout<<ans<<endl;
	return 0;
}
