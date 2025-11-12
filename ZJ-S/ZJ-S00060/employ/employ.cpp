#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,s[505],c[505],a[505],ti[20]={1},ans;
bool check()
{
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1&&c[a[i]]>cnt)
		{
			sum++;
		}
		else
		{
			cnt++;
		}
	}
	return sum>=m;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char p;
		cin>>p;
		if(p=='0')
			s[i]=0;
		else
			s[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=18;i++)ti[i]=ti[i-1]*i;
//	for(int i=1;i<=18;i++)cout<<ti[i]<<'\n';
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=ti[n];i++)
	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<a[j]<<' ';
//		}
//		cout<<'\n';
		if(check())
		{
			ans++;
			if(ans>=mod)ans-=mod;
		}
		next_permutation(a+1,a+n+1);
	}
	cout<<ans;
	return 0;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++