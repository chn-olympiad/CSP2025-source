#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,c[2000],a[2000],b[2000],cnt;
string st;
int pd()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		if(c[a[i]]<=sum||st[i-1]=='0') sum++;
	return (n-sum>=m);
}
void dfs(int k)
{
	if(k==n+1) {if(pd()) cnt++;return;}
	for(int i=1;i<=n;i++)
		if(!b[i])
		{
			a[k]=i;
			b[i]=1;
			dfs(k+1);
			b[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==n)
	{
		for(int i=1;i<=n;i++) 
			if(c[i]==0) {cout<<0;return 0;}
		for(int i=0;i<n;i++)
			if(st[i]=='0') {cout<<0;return 0;}
		long long sum=1;
		for(int i=2;i<=n;i++)
			sum=sum*i%mod;
		cout<<sum;
	}
	else if(n<=10)
	{
		dfs(1);
		cout<<cnt%mod;
	}
	else
	{
		for(int i=1;i<=n;i++) 
			if(c[i]==0) cnt++;
		long long sum=1;
		for(int i=cnt;i<=n;i++)
			sum=sum*i%mod;
		cout<<sum;
	}
	return 0;
}
//last chance
//40+20+10+12......
//10 years,all fantasy,loser?