#include<bits/stdc++.h>
using namespace std;
long long  flag[1015][1015];
long long  ans[1015][1015];
long long n,m,k;
long long build[1015];
long long  buildd[1015][1015];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		flag[a][b]=c;
		flag[b][a]=c;
		ans[a][b]=1000000001;
		ans[b][a]=1000000001;		
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			if(j==1)
			{
				cin>>build[j+n];
			}
			else
			{
				cin>>flag[n+j][n];
				flag[n+j][n]=flag[n+j][n];
				ans[n+j][n]=1000000001;
				ans[n+j][n]=1000000001;
			}
		}
	}
	for(int v=1;v<=n+k;v++)
	{
		for(int i=1;i<=n+k;i++)
		{
			for(int j=1;j<=n+k;j++)
			{
				if(((flag[i][k]>0)&&(flag[k][j]>0))&&(buildd[i][k]==1)&&(buildd[k][j]==1))
				ans[i][j]=min(ans[i][j],flag[i][k]+flag[k][j]);
				//cout<<" vvbb"<<endl; 
			}
		}
	}
	cout<<ans[1][n];
	return 0;
}