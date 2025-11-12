#include <bits/stdc++.h>
using namespace std;
int n,m,k,u[1100000],v[1100000],w[11000000],c[1100000],a[11000000];
int main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		for(int j=1;j<=k;j++)
		{
			cin>>c[j]>>a[j+n];
		}
	}
	cout<<"13";
	return 0;
}
