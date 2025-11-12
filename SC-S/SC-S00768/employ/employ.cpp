#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const ll mod=998244353;
ll n,m;
string s;
ll c[555];
ll op[555];
ll res;
bool vs[555];
bool ch()
{
	ll op1=0;
	ll sr=0;
	for(int i=0;i<n;i++)
	{
		if(op1>=c[op[i+1]]||s[i]=='0')
		{
			op1++;
		}
		else
		{
			sr++;
			if(sr>=m)return 1;
		}
	}
	if(sr>=m)return 1;
	else return 0;
}
ll ji(ll x)
{
	ll res=1;
	for(int i=x;i>=1;i--)
	{
		res=res*i%mod;
	}
	return res;
}
void dfs(ll x,ll rr,ll jj)
{
	if(x==n+1)
	{
		if(ch())
		{
			res++;
			res%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vs[i])
		{
			op[x]=i;
			if(((c[i]>jj)&&(s[x-1]=='1'))+rr>=m)
			{
				res=res+ji(n-x);
				continue;
			}
			vs[i]=1;
			dfs(x+1,rr+((c[i]>jj)&&(s[x-1]=='1')),jj+(!((c[i]>jj)&&(s[x-1]=='1'))));
			vs[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool ooo=1;
	bool gh=1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(s[i-1]=='0')ooo=0;
		if(c[i]==0)gh=0;
	}
	if(ooo)
	{
		if(gh)
		{
			cout<<ji(n);
		}
		else
		{
			dfs(1,0,0);
			cout<<res;
		}
	}
	else
	{
		dfs(1,0,0);
		cout<<res;
	}
	return 0;
}