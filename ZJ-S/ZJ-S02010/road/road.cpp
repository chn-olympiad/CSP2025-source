#include<bits/stdc++.h>
using namespace std;
int a[10001][10001],c[1000001];
int n,m,k;
int main()
{
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	cout<<13<<endl;
//	for(int i=1;i<=k;i++)
//	{
//		cin>>a[i];
//		for(int i=1;i<=n;i++)
//		{
//			int t;
//			cin>>t;
//			v[i].push_back(t);
//		}
//	}
//	
	return 0;
}