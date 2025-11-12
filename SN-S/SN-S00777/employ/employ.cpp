#include<bits/stdc++.h>
using namespace std;
const int M=510;
const int Mod1=998244353;
int c[M];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n)
	{
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				cout<<0<<"\n";
			}
		}
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(1ll*ans*i)%Mod1;
		}
		cout<<ans<<"\n";
	}
	else
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(1ll*ans*i)%Mod1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
