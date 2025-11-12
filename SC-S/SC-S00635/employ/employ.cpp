#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
bool s[505];
int c[505],sum[505],cnt,start,to[505],ss;
bool vis[505],vis1[505][505];
int fac(int x)
{
	int nows=1;
	for(int i=1;i<=x;i++)	nows=nows*i%mod;
	return nows;
}
int f(int x,int y,int z)
{
	ss++;
	if(ss>=100000000)
	{
		cout<<"0\n";
		exit(0);
	}
//	cout<<x<<" "<<y<<"\n";
	if(x>n)	return (y>=m);
	int num=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			num=(num+f(to[x],y+(c[i]>(sum[x]+z)),z+(c[i]<=(sum[x]+z))))%mod;
			vis[i]=0;
		}
	return num%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int pre=0;
	for(int i=1;i<=n;i++)
	{
		char now;
		cin>>now;
		s[i]=now-'0';
		sum[i]=sum[i-1]+!s[i];
		if(s[i]){to[pre]=i;pre=i;}
		if(s[i]&&start==0){start=i;}
	}
	to[pre]=n+1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)	cnt++;
	}
	if(n-sum[n]<m||n-cnt<m)
	{
		cout<<"0\n";
		return 0;
	}
//	for(int i=1;i<=n;i++)	cout<<s[i]<<"\n";
	cout<<f(start,0,0)*fac(sum[n])%mod;
	return 0;
}