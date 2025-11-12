#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int c[N];
int n,m;
int ans;
int vid[N];
string s;
int check()
{
	int x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0'||x>=vid[i])
		{
			x++;
			if(n-x<m)
				return 0;
		}
		else
		{
			y++;
			if(y>=m)
				return 1;
		}
	} 
} 
void dfs(int id)
{
	if(id==n+1)
	{
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vid[i]==0)
		{
			vid[i]=c[id];
			dfs(id+1);
			vid[i]=0;
		}
	} 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
} 