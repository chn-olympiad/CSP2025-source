#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,c[505],mod=998244353,nepl,fai,ansdfs;
string s;
bool vis[505];
void solveA()
{
	ll ans=1,p=0;
	for(int i=0;i<n;i++)
	{
		if(c[i]!=0)
		p++;
	}
	if(p<m)
	{
		cout<<0;
		return;
	}
	for(int i=1;i<=p;i++)
	{
		ans*=i;
		ans=ans%mod;
	}
	cout<<ans%mod;
	return;
}
void dfs(int q)
{
	if(q>n)
	{
		if(nepl>=m)
		ansdfs++;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			if(s[q-1]=='1'&&fai<c[i])
			{
				nepl++;
				dfs(q+1);
				nepl--;
			}
			else
			{
				fai++;
				dfs(q+1);
				fai--;
			}
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	ll k;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
		k++;
	}
	if(k==0)
	{
		solveA();
		return 0;
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(c[i]==0)
			cout<<0;
			return 0;
		}
		if(k!=0)
		cout<<0;
		else
		{
			solveA();
		}
		return 0;
	}
	dfs(1);
	cout<<ansdfs;
	return 0;
}
