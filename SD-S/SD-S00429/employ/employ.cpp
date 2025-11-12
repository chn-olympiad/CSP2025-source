#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,c[1000009],ans,b[1000009];
string s;
void dfs(int x,int fa)
{
	if(fa>n-m)
	{
		return ;
	}
	if(x>n)
	{
		ans++;
		if(ans>=p)
		{
			ans-=p;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			if(fa>=c[i])
			{
				dfs(x+1,fa+1);
			}
			else
			{
				if(s[x-1]=='0')
				{
					dfs(x+1,fa+1);
				}
				else
				{
					dfs(x+1,fa);
				}
			}
			b[i]=0;
		}
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
} 
