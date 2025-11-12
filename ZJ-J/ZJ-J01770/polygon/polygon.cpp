#include<bits/stdc++.h>
using namespace std;
long long n,x,c,s,ans,a[5005],b[5005],k;
int mod=998244353;
void dfs(int x,int f,int y)
{
	if(y)
		b[f]=y;
	if(x>n)
	{
		c=0;
		s=0;
		if(f<3)
		return;
		for(int i=1;i<=f;i++)
		{
			c+=b[i];
			s=max(s,b[i]);
		}
		if(c>s*2)
			ans++;
		return;
	}
	dfs(x+1,f+1,a[x]);
	dfs(x+1,f,0);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(x==1)
	{
		k=n*(n-1)/2;
		for(int i=3;i<=n;i++)
		{
			k=k*(n-i+1)/i;
			k%=mod;
			ans+=k;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans%mod;
	return 0;
}
