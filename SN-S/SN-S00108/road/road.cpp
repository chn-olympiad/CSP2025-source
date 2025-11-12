#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define float double
using namespace std;
struct Edge
{
	int v,w;
};
int n,m,k;
vector<Edge> e[10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int U,V,W;
		cin>>U>>V>>W;
		e[U].push_back({v,w});
		e[V].push_back({u,w});
	}
	
	return 0;
}

