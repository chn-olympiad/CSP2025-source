#include <bits/stdc++.h>
using namespace std;
const long long h=1e9+10;
int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int u[10010],v[10010],w[h];
	int c[h],a[h];
	int cnt=0;
	int maxn=0;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		cnt+=w[i];
		if(w[i]>maxn) maxn=w[i];
	}
	
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for (int p=1;p<=n;p++)
		{
			cin>>a[p];
		}
	}
	int ans=cnt-maxn;
	cout<<ans<<endl;
	
	
	return 0;
 } 
