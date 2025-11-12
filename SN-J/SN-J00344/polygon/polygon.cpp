#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,l=0,sum=0,ma=0,m=0;
long long a[5010];
void dfs(long long now)
{
	if(now>n)
	{
		if(l<3)
		{
			return;
		}
		if(ma*2<sum)
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	l++;
	sum+=a[now];
	long long b=ma;
	ma=max(ma,a[now]);
	dfs(now+1);
	l--;
	sum-=a[now];
	ma=b;
	dfs(now+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}
