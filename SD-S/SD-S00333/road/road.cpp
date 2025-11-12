#include<bits/stdc++.h>
using namespace std;
int h[10005][10005];
int cc[15],c[15][10005];
int n,m,k,u,v,w;
int p[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,0x7f,sizeof(h));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		h[u][v]=w;
		h[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>cc[i];
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	for(int jj=1;jj<=k;jj++)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				
					h[i][j]=min(h[i][j],cc[jj]+c[jj][i]+c[jj][j]);
				}
			}
		}
	int rr=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			rr++;
			p[rr]=h[i][j];	
		}
	}
	sort(p+1,p+rr+1);
	long long num=0;
	for(int i=1;i<=3;i++)
	{
		num+=p[i];
	}
	cout<<num;
	return 0;
}

