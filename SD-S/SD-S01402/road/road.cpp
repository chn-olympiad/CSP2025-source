#include<bits/stdc++.h>
#define int long long
#define y second
#define x first
using namespace std;

const int N=1e4+5,M=1e6+5,K=1e1+5;
vector<pair<int,int> >e[N];
int n,m,k,c[K],a[K][N];

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	cout<<n*m-k<<"\n";
	return 0;
}
