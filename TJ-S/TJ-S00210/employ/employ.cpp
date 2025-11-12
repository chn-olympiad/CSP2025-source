#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[100005],plan[100005];
bool flag[100005];
int ans=0;
int U;
void dfs(int step)
{
	if(step==n+1)
	{
		int lose=0,win=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1'&&a[plan[i]]>lose) win++;
			else lose++;
		}
		ans+=(win>=m);
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		flag[i]=1;
		plan[step]=i;
		dfs(step+1);
		flag[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}

