#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int m,n,k;
const int N=1e4+1;
struct edge{
	int u,v,w;
}arr[N];
int new[11][N];
int fa[N];
void init(){for(int i=1;i<=n;i++) fa[i]=i;}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		arr[i]=(arr[i].w==0||arr[i].w>w)?{u,v,w}:arr[i];
	}
	for(int K=0;K<k;k++)
	[
		cin>>new[k][0];
		for(int i=1;i<=n;i++) cin>>new[k][i];
	]
	return 0;
}
