#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int s[5005];
bool f[5005];
int sum = 0;
void dfs(int now,int now2)
{
	if(now == 0)
	{
		int maxn = -1;
		for(int i=1;i<=now2;i++) maxn = max(maxn,s[i]);
		long long ans = 0;
		for(int i=1;i<=now2;i++) ans+=s[i];
		if(ans >= (maxn * 2)) sum++;
		for(int i=1;i<=now2;i++)
		{
			s[i] = 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i] == false)
		{
			s[now] = a[i];
			f[i] = true;
			dfs(now-1,now2);
			f[i] = false;
			s[now] = 0;
		}
	}
}
int ans = 0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int bian=1;bian<=n;bian++)
	{
		dfs(bian,bian);
	}
	cout<<sum;
	return 0;
}
