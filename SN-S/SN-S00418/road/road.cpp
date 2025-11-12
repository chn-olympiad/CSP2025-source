//林靖轩 SN-S00418 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k,ans=0;
int u[M],v[M],w[M];
int c[N*10],a[N][N];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}	
	for(int i=1;i<=n;i++)
		ans+=w[i];
	
	cout<<ans;
	return 0;
}
//4 4 2
// 1 4 6
// 2 3 7
// 4 2 5
// 4 3 4
// 1 1 8 2 4
// 100 1 3 2 4

