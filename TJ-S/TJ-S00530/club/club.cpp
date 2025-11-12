#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int t;
	int n;
	scanf("%d", &t);
	for(t;t>0;t--)
	{
		n = 0;
		scanf("%d", &n);
		int a[n][3];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 3; j++) 
			{
				scanf("%d", &a[i][j]);
			}
		}
//		
//		int dp[n];
//		for(int x = 0;x<n;x++)
//		{
//			dp[x] = 0;
//		}
//		int d[3] = {n/2,n/2,n/2};
//		for(int i = 0; i < 3; i++)
//		{
//			for(int j = 0; j < n; j++)
//			{
//				
//			}
//		}
//		
		int mx;// = max(a[1][1],max(a[1][2],a[1][3]));
//		int my = 0;
//		if(mx = a[1][1]) d[0]-1;
//		else if(mx = a[1][2]) d[1]-1;
//		else d[2]-1;
//		dp[1] = mx;
		int ans = 0;
		for(int i = 0;i < n;i++)
		{
			mx = max(a[i][1],max(a[i][2],a[i][0]));
			ans += mx;
		}
		printf("%d",ans);
		
		
		
	}
	
	return 0;
}
