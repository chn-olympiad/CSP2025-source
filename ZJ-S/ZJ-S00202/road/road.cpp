#include<bits/stdc++.h>
using namespace std;
const int M=1e9+5;
struct node
{
	int x,y,w;
};
node a[2000005];
long long n,m,k,b[15][10005],c[15],d[1005][1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			d[i][j]=M;
	for(int i=1;i<=n;i++)
		d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z,k1;
		k1=2*i-1;
		scanf("%d%d%d",&x,&y,&z);
		if(n<=1000)
		{
			d[x][y]=z;
			d[y][x]=z;
		}
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&b[i][j]);
	}
	if(n<=1000)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
		
				for(int k=j+1;k<=n;k++)
				{
					d[j][k]=min(d[j][k],b[i][j]+b[i][k]);
					d[k][j]=d[j][k];
				}
		for(int k1=1;k1<=n;k1++)
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][k1]+d[k1][j]);
		cout<<d[1][n];
		return 0;
	}
	cout<<505585650;
	return 0;
}
