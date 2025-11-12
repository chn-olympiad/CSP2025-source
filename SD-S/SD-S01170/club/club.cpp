#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200+7;
const int DN=1e5+7;
int n;
int a[N][4],da[DN],db[DN],vis[10];
int dfs(int x,int sum,int id)
{
	vis[x]++;
	//cout<<vis[1]<<" "<<vis[2]<<" "<<vis[3]<<"\n";
	for(int i=1;i<=3;i++)
	{
		if(vis[i]>n/2){
		//vis[x]--;
		//cout<<"***"<<"\n";
		return 0;
	}
	}
	if(vis[1]+vis[2]+vis[3]==n)
	{
		vis[x]--;
		//cout<<sum<<"\n";
		return sum+a[id][x];
	}
	int ans=0;
	for(int i=1;i<=3;i++)
	{
		if(vis[i]+1<=n/2&&vis[1]+vis[2]+vis[3]<=n){
			ans=max(dfs(i,sum+a[id][x],id+1),ans);
		}
		
	}
	vis[x]--;
	return ans;
 } 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--)
	{
		//cout<<T+1<<"\n";
		cin>>n;
		bool fa=1,fb=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(j==2||j==3)
				{
					if(a[i][j]!=0)
					{
						fa=0;
					}
				}
				if(j==3)
				{
					if(a[i][j]!=0)
					{
						fb=0;
					}
				}
			}
		}
		if(fa)
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				da[i]=a[i][1];
			}
			sort(da+1,da+n+1);
			for(int i=n;i>n/2;i++)
			{
				ans+=da[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(fb)
		{
			int ans=0;
		}
		int maxx=0;
		for(int i=1;i<=3;i++)
		{
			maxx=max(dfs(i,0,1),maxx);
		}
		for(int i=1;i<=3;i++)vis[i]=0;
		cout<<maxx<<"\n";
	}
	return 0;
}

