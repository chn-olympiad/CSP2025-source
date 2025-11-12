#include<iostream>
using namespace std;
const int maxn=1e5+5;
int map[maxn][maxn];
int n,m,k;
int pri[maxn];
int flag[maxn];
int minn=1000000009;
void dfs(int num,int she,int ans)
{
	if(she==0)
	{
		minn=min(ans,minn);
		return;
	}
	for(int i=1;i<=n+k;i++)
	{
			if(flag[i]==0&&map[num][i]!=0)
			{
				flag[i]=1;
				if(i<=n)
				she--;
				if(i<=n) ans+=map[num][i];
				else ans+=map[num][i]+pri[i];
				dfs(i,she,ans);
			}
	}
}



int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,val;
		cin>>a>>b>>val;
		map[a][b]=map[b][a]=val;
	}	
	for(int i=1;i<=k;i++)
	{
		cin>>pri[i+n];
		for(int j=1;j<=n;j++)
		{
			int a;
			cin>>a;
			map[j][n+j]=map[n+j][j]=a;
		}
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,n,0);
		for(int j=1;j<=n+k;j++)
		{
			flag[j]=0;
		}
	}
	cout<<minn;
	return 0;
}