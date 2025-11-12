#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int b[100005];
int visited[4];
long long ans;
void dfs(int n,int c,long long s)
{
	if(c>n)
	{
		ans=max(ans,s);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(visited[i]>=n/2)
		{
			continue;
		}
		visited[i]++;
		dfs(n,c+1,s+a[c][i]);
		visited[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==100000)
		{
			for(int i=1;i<=n;i++)
			{
				int x;
				cin>>b[i]>>x>>x;
			}
			sort(b+1,b+n+1);
			long long ans=0;
			for(int i=n;i>=n/2+1;i--)
			{
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		ans=0;
		dfs(n,1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
