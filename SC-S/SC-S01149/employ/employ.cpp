#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n,m,a[510],b[510],cnt=0;
	bool check=1;
	string x;
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++)
	{
		a[i]=x[i-1]-'0';
		cin>>b[i];
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0||b[i]==0)
			{
				cout<<0;
				return 0;
			}
		}
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
 	return 0;
}
