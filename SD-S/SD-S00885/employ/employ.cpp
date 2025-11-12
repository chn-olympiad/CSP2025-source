#include <iostream>
#include <algorithm>
#include <cstdio>
const long long MOD= 998244353;
using namespace std;
int n,m;
long long ans=0;
string s;
int heart[505];
int check[505],anss[505];
void dfs(int cnt,int have,int down)
{
	if(n-down<m)
	{
		return ;
	}
	if(cnt==n+1)
	{
		if(have>=m)
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(check[i]==0)
		{
			if(s[cnt]=='1' && heart[i]>down)
			{
				check[i]=1;
				dfs(cnt+1,have+1,down);
				check[i]=0;
			}
			else
			{
				check[i]=1;
				dfs(cnt+1,have,down+1);
				check[i]=0;
			}
		}
	}
}
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>heart[i];
	}
	sort(heart+1,heart+n+1);
	dfs(1,0,0);
	ans%=MOD;
	cout<<ans<<'\n';
	return 0;
}
