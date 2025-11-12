#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
int a[100005][4],n;
inline int dfs(int x,int ans,int sum1,int sum2,int sum3)//x:µ±Ç°µã
{
	if(x>n)
	{
		return ans;
	}
	int maxx=-1;
	for(int i=1;i<=3;i++)
	{
		if(sum1==n/2&&i==1)
		{
			continue;
		}
		if(sum2==n/2&&i==2)
		{
			continue;
		}
		if(sum3==n/2&&i==3)
		{
			continue;
		}
		maxx=max(maxx,dfs(x+1,ans+a[x][i],sum1+(i==1),sum2+(i==2),sum3+(i==3)));
	}
	return maxx;
} 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
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
		cout<<dfs(1,0,0,0,0)<<endl;
	} 
	return 0;
} 
