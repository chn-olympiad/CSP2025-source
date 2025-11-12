#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans,a[501],s[501],c[501];
bool vis[501];
bool check()
{
	int sum,t;
	sum=t=0;
	for(int i=1;i<=n;i++)
		if(c[a[i]]>sum||s[i]==0)
			sum++;
		else
			t++;
	return t>=m;
}
void dfs(int step)
{
	if(step>n)
	{
		if(check())
			ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=true;
			a[step]=i;
			dfs(step+1);
			vis[i]=false;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	char ch;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		s[i]=ch-48;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
