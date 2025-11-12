#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e6+5;
int n,m,k,f[maxn],ans,cnt,x,y,z,qwq;
struct node{
	int u,v,w;
	bool operator<(const node &x) const{
		return w<x.w;
	}
}e[maxn];
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
	 {
	 	cin>>qwq;
	 	for(int j=1;j<=n;j++)
	 	 {
	 	 	cin>>x;
	 	 	if(qwq==0) e[++m]=(node){i,j,x};
		 }
	 }
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	 {
	 	auto[u,v,w]=e[i];
	 	if(f[find(u)]!=find(v))
	 	 {
	 	 	f[find(u)]=find(v);
	 	 	cnt++;ans+=w;
	 	 	if(cnt==n-1) {cout<<ans;break;}
		  }
	 }
	return 0;
}