#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],u[N],v[N],w[N],h[N],n,m,k;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		
	}
	int maxx=-1;
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;maxx=max(c,maxx);
	}
	cout<<maxx;
	ios::sync_with_stdio(0);
	return 0;
//	queue<int> q;
//	while()
//	
	
	
	
	
}
