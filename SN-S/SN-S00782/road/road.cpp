//马歆玥 西安滨河学校 SN-S00782 
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005],c[1000005],a[1000005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
		cin >> u[i] >> v[i] >> w[i];
	for(int i=1;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
			cin >> a[j];
	}
	
	return 0;
}
