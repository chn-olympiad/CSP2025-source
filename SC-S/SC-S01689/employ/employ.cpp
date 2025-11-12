#include<iostream>
using namespace std;
const int mod=998244353;
int n,m;
int c[501];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	bool f=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			f=1;
			break;
		}
	}
	if(!f)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
			{
				++cnt;
			}
		}
		if(n-cnt<m)
		{
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}