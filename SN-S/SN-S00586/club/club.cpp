#include<bits/stdc++.h>
using namespace std;
 
int t,n;
struct nod{
	int a,b,c;
}e[200005];



int dp[205][205][205];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&e[j].a ,&e[j].b ,&e[j].c );	
		}
		memset(dp,0,sizeof(dp));
		for(int aa=0;aa<=n/2;aa++)
		{
			for(int bb=0;bb<=n/2;bb++)
			{
				for(int cc=0;cc<=n/2;cc++)
				{
					if(aa>=1)
						dp[aa][bb][cc]=max(dp[aa][bb][cc],dp[aa-1][bb][cc]+e[aa+bb+cc].a);
					if(bb>=1)
						dp[aa][bb][cc]=max(dp[aa][bb][cc],dp[aa][bb-1][cc]+e[aa+bb+cc].b);
					if(cc>=1)
						dp[aa][bb][cc]=max(dp[aa][bb][cc],dp[aa][bb][cc-1]+e[aa+bb+cc].c);
					if(aa+bb+cc==n)	ans=max(ans,dp[aa][bb][cc]);
				//	printf("%d %d %d %d\n",dp[aa][bb][cc],aa,bb,cc);
					
				}
				
			}
		}
		
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

