#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std; 
const int MAXN=1e5+5;
int t,n;
struct Node
{
	int x,y,z;
}a[MAXN];
struct DP
{
	int x,y,z;
	int cx=0,cy=0,cz=0;
}dp[MAXN];
//while(1) rp++;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
 		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		dp[1].x=a[1].x,dp[1].y=a[1].y,dp[1].z=a[1].z;
		dp[1].cx=dp[1].cy=dp[1].cz=1;
		for(int i=2;i<=n;i++)
		{
			int maxx=max(dp[i-1].x,max(dp[i-1].y,dp[i-1].z));
			if(dp[i-1].cx<n/2&&maxx==dp[i-1].x)
			{
				dp[i].x=dp[i-1].x+a[i].x;
				dp[i].cx=dp[i-1].cx+1;
			}
			else
			{
				dp[i].x=max(max(dp[i-1].y,dp[i-1].z)+a[i].x,dp[i-1].x);
				dp[i].cx=dp[i-2].cy+1;
			}
			if(dp[i-1].cy<n/2&&maxx==dp[i-1].y)
			{
				dp[i].y=dp[i-1].y+a[i].y;
				dp[i].cy=dp[i-1].cy+1;
			}
			else
			{
				dp[i].y=max(max(dp[i-1].x,dp[i-1].z)+a[i].y,dp[i-1].y);
				dp[i].cy=dp[i-2].cy+1;
			}
			if(dp[i-1].cz<n/2&&maxx==dp[i-1].z)
			{
				dp[i].z=dp[i-1].z+a[i].z;
				dp[i].cz=dp[i-1].cz+1;
			}
			else
			{
				dp[i].z=max(max(dp[i-1].x,dp[i-1].y)+a[i].z,dp[i-1].z);
				dp[i].cz=dp[i-2].cz+1;
			}
		}
		cout<<max(dp[n].x,max(dp[n].y,dp[n].z))<<endl;
	}
	return 0;
}
