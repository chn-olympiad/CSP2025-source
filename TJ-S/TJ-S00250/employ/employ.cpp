#include<bits/stdc++.h>
using namespace std;
#define int long long

int mod=998244353;
string s;
int c[502];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int flag=1,cnt=0;
	for(int i=0;i<m;i++)
	{
		if(s[i]==0)
		{
			flag=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			cnt++;
		}
	}
	if(flag)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	else if(m==n&&cnt>=1)
	{
		cout<<0;	
	}
	else if(n==m&&cnt==0) 
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
}

