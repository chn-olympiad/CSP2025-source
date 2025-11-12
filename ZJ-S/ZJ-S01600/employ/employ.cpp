#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,c[501];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	bool f=1;
	for(int i=0;i<n;i++)
		if(s[i]=='0')
			f=0;
	long long ans=1,nn=n;
	for(int i=1;i<=n;i++)
		if(c[i]==0)
			nn--;
	if(nn<m)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		if(f==0||nn<n)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%p;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		long long ans=1,nn=n;
		for(int i=1;i<=n;i++)
			if(c[i]==0)
				nn--;
		for(int i=1;i<=n-1;i++)
			ans=ans*i%p;
		cout<<nn*ans%p;
		return 0;
	}
	if(f==1)
	{
		for(int i=1;i<=nn;i++)
		{
			ans=ans*i%p;
		}
		for(int i=1;i<=n-nn;i++)
		{
			ans=ans*i%p;
		}
		cout<<ans;
	}
	return 0;
}
