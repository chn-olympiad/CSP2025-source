#include<bits/stdc++.h>
using namespace std;
int t;
long long a[100010][3];
int n;
long long ans=-1;
int vis[3];
long long liu[100010];
void dfs(int x,long long add)
{
	if(x>n)
	{
		ans=max(ans,add);
		return;
	}
	for(int i=0;i<=2;i++)
	{
		if(ans!=-1&&add>=ans)
			continue;
		if(vis[i]<n/2)
		{
			vis[i]++;
			liu[x]=a[x][i];
			dfs(x+1,add+a[x][i]);
			vis[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof vis);
		ans=-1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}



