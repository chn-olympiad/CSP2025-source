#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,z;
};
int T;
int n;
//node a[100010];
int a[100010],b[100010],c[100010];
int ans;
map<int,map<int,map<int,int> > > vis;
void dfs(int p,int num,int x,int y,int z)
{
	if(p==n+1)
	{
		ans=max(num,ans);
		return;
	}
	if(vis[x][y][z]<=num)
	{
		vis[x][y][z]=num;
	}
	else
	{
		return;
	}
	if(x<n/2)
	{
		dfs(p+1,num+a[p],x+1,y,z);
	}
	if(y<n/2)
	{
		dfs(p+1,num+b[p],x,y+1,z);
	}
	if(z<n/2)
	{
		dfs(p+1,num+c[p],x,y,z+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		vis.clear();
		ans=0;
		int flag=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]==0)
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
		}
		if(n<=300)
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
		}
		else
		{
			if(flag==1)
			{
				for(int i=1;i<=n;i++)
				{
					ans+=a[i]+b[i];
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}