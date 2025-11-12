#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll t;
ll n;
struct no{
	ll a,b,c;
}as[111111];
ll f[111111];
ll res=0;
void dfs(ll x,ll l1,ll l2,ll l3,ll op)
{
	if(x==n+1)
	{
		res=max(res,f[n]);
		return ;
	}
	if(l1<n/2)
	{
		f[x]=f[x-1]+as[x].a;
		dfs(x+1,l1+1,l2,l3,f[x]);
	}
	if(l2<n/2)
	{
		f[x]=f[x-1]+as[x].b;
		dfs(x+1,l1,l2+1,l3,f[x]);
	}
	if(l3<n/2)
	{
		f[x]=f[x-1]+as[x].c;
		dfs(x+1,l1,l2,l3+1,f[x]);
	}
}
bool cmp(no a,no b)
{
	if(a.a!=b.a)return a.a>b.a;
	else if(a.b!=b.b)return a.b>b.b;
	return a.c>b.c; 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		res=0;
		cin>>n;
		bool t3=1;
		bool t2=1; 
		for(int i=1;i<=n;i++)
		{
			cin>>as[i].a>>as[i].b>>as[i].c;
			if(as[i].c)t3=0;
			if(as[i].b)t2=0;
		}
		if(n<=30)
		{
			dfs(1,0,0,0,0);
			cout<<res<<endl;
		}
		else if(t3&&t2)
		{
			sort(as+1,as+1+n,cmp);
			ll res=0;
			for(int i=1;i<=n/2;i++)
			{
				res+=as[i].a;
			}
			cout<<res<<endl;
		}
	
	}
	return 0;
}