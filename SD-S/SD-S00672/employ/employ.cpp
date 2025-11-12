#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio> 
#define int long long
using namespace std;
const int mod=998244353;
int c[1005],vis[1005],n,m;
string s;
int dfs(int ot,int sum,int now)
{
	if(now==n)
	{
		if(sum>=m)return 1;
		return 0;
	}
	int res=0; 
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		if(s[now]=='1')
		{
			res+=dfs(ot+1,sum,now+1);
			res%=mod;
		}
		else
		{
			if(c[i]>ot)
			{
				res+=dfs(ot,sum+1,now+1);
				res%=mod;
			}
			else
			{
				res+=dfs(ot+1,sum,now+1);
				res%=mod;
			}
		}
		vis[i]=0;
	} 
	return res;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	int ans=dfs(0,0,1);
	cout<<ans<<endl;
	return 0;
}
