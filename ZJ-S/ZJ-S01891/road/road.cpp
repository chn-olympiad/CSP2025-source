#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=1e6+100;
inline int read(){
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while('0'<=ch&&ch<='9'){
		res=(res<<1)+(res<<3)+(ch-'0');
		ch=getchar();
	}
	return res;
}
int n,m,k;
ll c[15],a[15][N];
int fa[N];
int find(int u){
	return ((fa[u]==u)?fa[u]:(fa[u]=find(fa[u])));
}
void merge(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}
struct edge{
	int u,v;
	ll w;
};
vector<edge> e[4]; 
struct cmp_w{
	bool operator() (edge A,edge B){
		return A.w<B.w;
	}
};

ll Kruskal(int p){
	ll res=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	e[2].clear();
	for(edge ed:e[p]){
		int u=ed.u,v=ed.v;ll w=ed.w;
		if(find(u)!=find(v)){
			res+=w;
			merge(u,v);
			e[2].push_back(ed);
		}
	}
	return res;
}
ll ans;
void solve(){
	int p=0;//现在花费最小的边集 
	ans=Kruskal(1);//计算的边集 
	for(edge ed:e[2]) e[p].emplace_back(ed);
	for(int j=1,p=0;j<=k;++j){
		e[p^1].clear();
		for(edge ed:e[p]){
			e[p^1].emplace_back(ed);
		}
		for(int i=1;i<=n;++i){
			e[p^1].emplace_back((edge){n+j,i,a[j][i]});
		}
		sort(e[p^1].begin(),e[p^1].end(),cmp_w());
		ll res=Kruskal(p^1);
		if(res+c[j]<ans){
			ans=res+c[j];
			p^=1;e[p].clear();
			for(edge ed:e[2]){
				e[p].emplace_back(ed);
			}
		}
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i){
		int u,v;ll w;
		u=read(),v=read(),w=read();
		e[1].emplace_back((edge){u,v,w});
	}
	sort(e[1].begin(),e[1].end(),cmp_w());
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j) a[i][j]=read();
	}
	solve();
	return 0;
}
