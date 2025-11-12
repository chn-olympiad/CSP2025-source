#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int maxn=1e5+5;
int map[maxn][5];
int T;
int linshi[maxn],linshi1[maxn];
int ji[maxn][5][5];
int dp[maxn][5];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=-1;
		int flag=0;
		cin>>n;
		int xian=n/2;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>map[i][j];
				if(j==2&&map[i][j]!=0)
				{
					flag=1;
				}
				if(j==3&&map[i][j]!=0)
				{
					flag=2;
				}
				dp[i][j]=map[i][j];
				ji[i][j][j]=1;
			}
		}
		if(flag==0)
		{
			int ansn=0;
			for(int i=1;i<=n;i++)
			{
				linshi[i]=map[i][1];
				cout<<linshi[i]<<" ";
			}
			sort(linshi+1,linshi+n+1);
			for(int i=n;i>n/2;i--)
			{
				ansn+=linshi[i];
			}
			cout<<ansn<<"\n";
			continue;
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{int link;
				for(int k=1;k<=3;k++)
				{
					
					if(ji[i-1][k][j]+ji[i][j][j]<=xian&&(dp[i-1][k]+map[i][j]>dp[i][j]))
					{
						dp[i][j]=dp[i-1][k]+map[i][j];
						link=k;
						//dp[i][j]=max(dp[i-1][k]+map[i][j],dp[i][j]);
						/*for(int f=1;f<=3;f++)
						{
							if(f==j) ji[i][j][f]=ji[i-1][k][f]+1;
							else ji[i][j][f]=ji[i-1][k][f];
						}*/
						//cout<<i<<" "<<j<<" "<<k<<"\n";
					}	
					ans=max(dp[i][j],ans);		
				}
				for(int f=1;f<=3;f++)
						{
							if(f==j) ji[i][j][f]=ji[i-1][link][f]+1;
							else ji[i][j][f]=ji[i-1][link][f];
						}
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				for(int k=1;k<=3;k++)
				{
					cout<<ji[i][j][k]<<"\n";
				}
			}
		}*/

		cout<<ans<<"\n";
	}
	return 0;
}