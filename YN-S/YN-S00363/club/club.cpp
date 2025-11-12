#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100000][4];
int ans;
int cnt1,cnt2,cnt3;
int vis[100000];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int y,int z,int i,int sum)
{
	if(x==n/2||y==n/2||z==n/2)
	{
		ans=max(ans,sum);
		return;
	}
	dfs(x+1,y,z,i+1,sum+a[i][1]);
	dfs(x,y+1,z,i+1,sum+a[i][2]);
	dfs(x,y,z+1,i+1,sum+a[i][3]);
}
bool chick()
{
	for(int i=1;i<=n;i++)
	{
		if(a[i][2]!=0||a[i][3]!=0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		if(n==2)
		{
			cout<<max(a[1][1]+a[2][1],max(a[1][2]+a[2][1],max(a[1][3]+a[2][1],max(a[1][1]+a[2][2],max(a[1][2]+a[2][2],max(a[1][3]+a[2][2],max(a[1][1]+a[2][3],max(a[1][2]+a[2][3],a[1][3]+a[2][3]))))))))<<endl;
			continue;
		}
		else if(chick())
		{
			
			for(int i=1;i<=n;i++)
			{
				vis[i]=a[i][1];
			}
			sort(vis+1,vis+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=vis[i];
			}
			cout<<ans<<endl;
			continue;
		}
		else
		{
			dfs(0,0,0,1,0);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
	}
	return 0;
}
