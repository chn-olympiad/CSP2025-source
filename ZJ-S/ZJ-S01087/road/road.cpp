#include<bits/stdc++.h>
using namespace std;
const long long NR=10000000000000,N=10020;
long long out,os,uo[N],n,m,k,u,v,w,s[N],road[N][N],a[20][N],ar[20][N],i,j,q;
bool ud,ua[N][5],uz[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=N;i++)
		for(j=1,s[i]=NR;j<=N;j++)
			road[i][j]=NR;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),road[u][v]=road[v][u]=min(road[u][v],w);
	for(i=1;i<=k;i++)
	{
		cin>>a[i][0];
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
				ar[i][++ar[i][0]]=j;
		}
		if(a[i][0]==0)for(j=1;j<=n;j++)
			for(q=1;q<=ar[i][0];q++)
				road[j][ar[i][q]]=road[ar[i][q]][j]=min(road[ar[i][q]][j],a[i][j]);
	}
	s[1]=0,ud=1;
	while(ud)
	{
		for(ud=0,i=1;i<=n;i++)if(s[i]!=NR)
			for(j=1;j<=n;j++)if(s[i]+road[i][j]<s[j])
				s[j]=s[i]+road[i][j],uo[j]=i,ud=1;
	}
	for(i=2;i<=n;i++)
		out+=road[i][uo[i]];
	cout<<out;
}//À×±Ìß÷ß÷×î¿É°®£¡£¡ 
