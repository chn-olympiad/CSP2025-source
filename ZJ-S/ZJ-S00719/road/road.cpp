#include<bits/stdc++.h>
#define v first
#define w second
using namespace std;
struct edge{
	int u,v,w;
}e[200055],g[300055],gg[300055];
int n,m,k,fa[2000055],ans,tot,a[15][10055],cnt,mi,d[200055],sum[200055];
bool vis[15];
map<int,int> mp;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal(){
	for(int i=0;i<=1000001;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			tot++;
			g[tot].u=e[i].u;
			g[tot].v=e[i].v;
			g[tot].w=e[i].w;
		}
		if(tot==n-1){
			break;
		}
	}
}
void kruskal2(){
	for(int i=0;i<=2000001;i++) fa[i]=i;
	int res=0;
	for(int i=1;i<=tot;i++){
		int fx=find(g[i].u);
		int fy=find(g[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=g[i].w;
			res++;
			gg[tot].u=e[i].u;
			gg[tot].v=e[i].v;
			gg[tot].w=e[i].w;
		}
		if(res==n-1){
			break;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+m,cmp);
	kruskal();
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		ans+=a[i][0];
		for(int j=1;j<=tot;j++){
			cnt++;
			mp[tot+i]=a[i][0];
			g[tot+cnt].u=tot+i;
			g[tot+cnt].v=g[j].v;
			g[tot+cnt].w=a[i][g[j].v];
		}
	}
	tot+=k*n;
	n+=k*n;
	sort(g+1,g+1+tot,cmp);
	kruskal2();
	for(int i=1;i<=tot;i++){
		d[gg[i].u]++;
		d[gg[i].v]++;
		sum[gg[i].u]+=gg[i].w;
		sum[gg[i].v]+=gg[i].w;
	}
	for(int i=n-cnt;i<=n;i++){
		if(d[i]==1){
			ans-=sum[i];
			ans-=mp[i];
		}
	}
	cout<<ans;
	return 0;
}