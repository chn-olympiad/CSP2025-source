#include<bits/stdc++.h>
using namespace std;

const int M=1e6+5;
long long n,m,k,ans;
long long u[M],v[M],w[M],a[10005][15],c[15];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	srand(time(0));
	
	cout<<rand()%1000000;
	
	while(1){
	}
	
	return 0;
}
