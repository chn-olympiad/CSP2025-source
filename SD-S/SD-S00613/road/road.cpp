#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,x,y,z,p,q[N];
bool vis[N];
long long ans;
struct edge{
	int u;
	int v;
	int w;
}e;
vector<edge> g;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&x,&y,&z);
		e.u=x;
		e.v=y;
		e.w=z;
		g.push_back(e);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&x);
		for(int j=1;j<=n;j++)
			scanf("%d",&q[j]);
		for(int j=1;j<n;j++)
			for(int k=j+1;k<=n;k++){
				e.u=j;
				e.v=k;
				e.w=q[j]+q[k];
				g.push_back(e);
			}
	}
	sort(g.begin(),g.end(),cmp);
	for(int i=0;i<g.size();i++){
		if(!vis[g[i].u]||!vis[g[i].v]){
			ans+=g[i].w;
			vis[g[i].u]=vis[g[i].v]=true;
		}
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

