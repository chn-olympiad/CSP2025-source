#include<bits/stdc++.h>
using namespace std;
int n,m,k,pd[10010],M[100010];
vector < vector < long long > > a;
void mak(int x)//buhui
{
	long long mins=1e9+10;
	int num;
	for(int i=1;i<=a[x][0];i++)
	{
		if(a[x][i]<mins) 
		{
			mins=a[x][i];
			
		} 
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		M[i]=w;//
//		a[u][v]=w;
//		a[v][u]=w;
//		a[u][0]++;
//		a[v][0]++;
	}
	if(k==0)
	{
		mak(1);
	}
	else
	{
		srand(time(0));
		long long num=0;
		for(int i=1;i<=m;i++)
		{
			int x=rand()%2;
			if(x==1) num+=M[i];
		}
		cout<<num;
	}
	return 0;
}
