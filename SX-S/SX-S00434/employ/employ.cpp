#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],t,as=1,ans,vis[505],vvs[505],u;
string s;
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int step)
{
	if(step>n)
	{
		int ts=0;
		for(int i=1;i<=n;i++) if(ts>=c[vvs[i]]||s[i-1]=='0') ts++;
		if(n-ts>=m)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vvs[step]=i;
			vis[i]=1;
			dfs(step+1);
			vis[i]=0;
			vvs[step]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<int(s.size());i++) if(s[i]=='0') t++;
	sort(c+1,c+n+1,cmp);
	while(n-u>0&&c[n-u]==0) u++;
	if(n-max(t,u)<m)
	{
		cout<<0;
		return 0;
	}
	if(t==0)
	{
		for(int i=2;i<=n;i++)
		{
			as*=i;
			as%=998244353;
		}
		cout<<as;
		return 0;
	}
	else
	{
		dfs(1);
		cout<<ans%998244353;
		return 0;
	}
	return 0;
}