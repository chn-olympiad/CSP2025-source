#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=998244353;
int n,m,c[N],a[N],vis[N];
long long ans=0;
string s;
void dfs(int x)
{
	if(x==n+1)
	{
		int fangqi=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')fangqi++;
			else if(fangqi>=c[a[i]])fangqi++;
			else sum++;
			//cout<<i<<endl;
			//cout<<fangqi<<" "<<c[a[i]]<<" "<<sum<<endl;
			if(sum>=m)break;
		}
		//cout<<sum<<endl;
		if(sum>=m)
		{
			ans++;
			if(ans>=mod)ans-=mod;
			//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
			//puts("");
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	int c0=0,s1=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)c0++;
		if(s[i]=='1')s1++;
	}
	if(s1<m)
	{
		cout<<0;
		return 0;
	}
	/*if(s1==n)
	{
		if(n-c0<m)cout<<0;
		else
		{
			ans=1;
			//for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans;
		}
		return 0;
	}*/
	dfs(1);
	cout<<ans;
	return 0;
}
/*
10 5
1111111111
6 0 4 2 1 2 5 4 3 3
100 47
11111111111111111111111111111111111111111111111
11111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4
 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 
 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 
 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54
  0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
  
161088479

*/