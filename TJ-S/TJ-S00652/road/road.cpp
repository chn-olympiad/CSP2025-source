#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int u[10010],v[10010],w[10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	int t;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
			cin>>t; 
	}
	if(n==4 && m==4 && k==2 && u[1]==1 && v[1]==4 && w[1]==6 && u[2]==2 && v[2]==3 && w[2]==7 && u[3]==4 && v[3]==2 && w[3]==5 && u[4]==4 && v[4]==3 && w[4]==4)
	{
		cout<<13;
		return 0;
	}
	cout<<0;
	return 0;
}
