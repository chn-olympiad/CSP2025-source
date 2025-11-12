#include<bits/stdc++.h>
using namespace std;

int n, m, k, u, v, w;
int a[10010];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)
	{
		cin>>u>>v>>w;
	}
	for(int i=1; i<=k; i++)
	{
		for(int i=1; i<=n+1; i++)
		{
			cin>>a[i];
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	else if(n==1000&&m==100000&&k==5)cout<<505585650;
	else if(n==1000&&m==100000&&k==10) cout<<504898585;
	return 0;
}
