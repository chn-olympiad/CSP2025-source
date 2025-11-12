#include<bits/stdc++.h>
using namespace std;
int t,n,dp[10001][10001];
struct st
{
	int a1,b1,c1;
}s[100001];
int dfs(int x,int a,int b,int v)
{
	if(x==n+1)return v;
	int aa=0,bb=0,cc=0;
	if(a+1<=n/2)
	{
		aa=dfs(x+1,a+1,b,v+s[x].a1);
	}
	if(b+1<=n/2)
	{
		bb=dfs(x+1,a,b+1,v+s[x].b1);
	}
	if(x-a-b<=n/2)
	{
		cc=dfs(x+1,a,b,v+s[x].c1);
	}
	return max(aa,max(bb,cc));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(s,0,sizeof(s));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>s[i].a1>>s[i].b1>>s[i].c1;
		}
		cout<<dfs(1,0,0,0);
	}
}
