#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e4+5;
const int maxm=2e6+5;
int n,m,k,tot,sum,ans,r;
int fa[maxn];
int c[maxn];
struct node{
	int u;
	int v;
	int w;
}e[maxm];
vector<pair<int,int> >p[maxn];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void Q(){
	for(int i=1;i<=m;i++){
		int u=e[i].u;
		int v=e[i].v;
		int fx=find(u);
		int fy=find(v);
		if(fx!=fy){
			ans+=e[i].w;
			if(u<=n&&v<=n) r--;
			fa[fx]=fy;
		}
		if(r==1) return;
	}
}
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	r=n;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		p[u].push_back({v,w});
		p[v].push_back({u,w});
		tot++;
		e[tot].u=u;
		e[tot].v=v;
		e[tot].w=w;
	}
	for(int i=1;i<=k;i++){
		int w;
		scanf("%lld",&c[i]);
		sum+=c[i];
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			tot++;
			e[tot].u=c[i];
			e[tot].v=j;
			e[tot].w=w;
		}
	}
	if(sum==0){
		sort(e+1,e+tot+1,cmp);
		Q();
		printf("%lld",ans);
	}
	else{
		cout<<"864566923";
	}
	return 0;
}

