#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500010],s[500010];
int u,o,p,pos;
int C(int x,int y)
{
	if(x==y) return 1;
	o=1,p=1;
	for(int i=2;i<=x;i++)
	{
		o*=i;
	}
	for(int i=2;i<=y-x;i++)
	{
		p*=i;
	}
	u=o*p;
	return pos/u;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	pos=1;
	for(int i=2;i<=n;i++)
	{
		pos*=i;
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=0;
		}
	}
	if(flag && k==0)
	{
		int ans=0;
		for(int i=2;i<=n;i+=2)
		{
			ans+=C(i,n);
		}
		cout<<ans;
		return 0;
	}
	if(flag && k==1)
	{
		int ans=0;
		for(int i=1;i<=n;i+=2)
		{
			ans+=C(i,n);
		}
		cout<<ans;
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}