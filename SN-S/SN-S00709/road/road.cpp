#include <bits/stdc++.h>
using namespace std;
//struct gg{
//	int x;
//	int y;
//	long long c;
//};
int xy(int x,int y)
{
	if(x<=y) return 1;
	else return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int r[10001][10001]={};
//	gg rr[1000]; 
	for(int i=0;i<m;i++)
	{
		long long x,v,u;
		cin>>x>>v>>u;
		r[x][v]=u;
		r[v][x]=u;
//		rr[i].x=x;rr[i].y=v;
//		rr[i].c=u;
	}
	int fre[10000];
	int io[100];
	int kf[100]={};
	for(int i=0;i<k;i++)
	{
//		int qwedrt;
//		cin>>qwedrt;//this is useless,because i will focus on AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
		cin>>io[i];
//		if(io[i]==0) kf[i]+=1;
		for(int j=0;j<n;j++)
		{
			cin>>fre[j];
		}
		for(int j=0;j<n;j++)
		{
			for(int u=j+1;u<n;u++)
			{
				if((fre[j]+fre[u])<r[u][j])
				{
					kf[i]+=r[u][j]-fre[j]+fre[u];
					r[u][j]=fre[j]+fre[u];
					r[j][u]=r[u][j];
				}
				else if(r[u][j]==0)
				{
					r[u][j]=fre[j]+fre[u];
					r[j][u]=r[u][j];
				}
			}
		}
	}
	int qwe[100000];
	int ct=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(r[i][j]!=0) qwe[ct++]=r[i][j];
		}
	}
	sort(qwe,qwe+ct,xy);
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		ans+=qwe[i];
	}
//	for(int i=0;i<ct;i++)
//	{
//		cout<<qwe[i]<<' ';
//	}
	for(int i=0;i<k;i++)
	{
		if(kf[i]>=io[i]) ans+=io[i];
	}
	cout<<ans;
	return 0;
}
