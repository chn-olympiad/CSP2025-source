#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,k,fa[N];
struct Edge{
	int u,v,w;
}e[N];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		int nx=find(e[i].u),ny=find(e[i].v);
		if(nx!=ny){
			fa[nx]=ny;
			cnt++;
			ans+=e[i].w;
		}
		if(cnt==n-1)break;
	}
	cout<<ans;
	return 0;
}