//SN-S00010 qiaoyuxiao
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[110];
string s;
long long ans;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	cout<<ans;
	return 0;
}
