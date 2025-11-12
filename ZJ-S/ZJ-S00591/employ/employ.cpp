#include<bits/stdc++.h>
using namespace std;
const int N=507,MOD=998244353;
int n,m,c[N],pre[N];
char s[N];
bool vis[N];
long long dfs(int x,int y)
{
	if(x==n)
		if(y>=m)
			return 1;
		else
			return 0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(pre[i]>=c[i])
			{
				vis[i]=1;
				if(s[i-1]=='1')
					pre[i]++;
				ans=(ans+dfs(x+1,y))%MOD;
				vis[i]=0;
				if(s[i-1]=='1')
					pre[i]++;
			}
			else
			{
				vis[i]=1;
				ans=(ans+dfs(x+1,y+1))%MOD;
				vis[i]=0;
			}
		}
	}
	return ans;
}
void solve1()
{
	cout <<dfs(0,0)<<endl;
	return ;
}
void solve2()
{
	int cnt0=0;
	for(int i=1;i<=n;i++)
		if(c[i]==0)
			cnt0++;
	if(n-cnt0<m)
	{
		cout <<0;
		return ;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=ans*i%MOD;
	}
	cout <<ans<<endl;
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+(s[i-1]=='0');
	if(n<=18)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	return 0;
}
