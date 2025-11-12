#include<bits/stdc++.h>
using namespace std;
long long m,n,k;
const int q=10000;
int u[q],v[q],w[q];
int c[q],a[q];
int main()
{
	freopen("road.in","r",std in);
	freopen("road.out","w",std out);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
} 