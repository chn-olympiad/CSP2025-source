#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,cnt=0,gg=0,plp=0,kk=0;
ll c[15],a[15][10005],ans=0,summ=0;
struct DSU{
	int fa[20005];
	inline void init(int n){
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(x==fa[x]) return x;
		return fa[x]=find(fa[x]);
	}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y) fa[x]=y;
	}
}dsu;
struct node{
	int u,v,id;
	ll w;
}e[1000005],g[600005];
inline bool cmp(node x,node y){
	return x.w<y.w;
}
inline bool cmp1(node x,node y){
	return x.id<y.id;
}
//int pp=0;
inline void dfs(int x,int sum){
	if(x>k){
		if(sum==0) return ;
		gg=cnt,plp=n,kk=0,summ=0;
		for(int i=k;i>=1;i--){
			if((sum>>(i-1))&1){
				plp++;
				for(int j=1;j<=n;j++){
					g[++gg].u=plp;
					g[gg].v=j;
					g[gg].w=a[i][j];
					g[gg].id=gg;
				}
				summ+=c[i];
			}
		}
		sort(g+1,g+gg+1,cmp);
//		pp+=gg*log2(gg);
		dsu.init(plp);
		for(int i=1;i<=gg;i++){
			int u=g[i].u,v=g[i].v,w=g[i].w;
			if(dsu.find(u)!=dsu.find(v)){
				dsu.merge(u,v);
				kk++;
				summ+=w;
			}
			if(summ>=ans){
				sort(g+1,g+gg+1,cmp1);
				return ;
			}
			if(kk==plp-1) break;
		}
		ans=min(ans,summ);
		sort(g+1,g+gg+1,cmp1);
		return ;
	}
	dfs(x+1,sum);
	dfs(x+1,sum+(1<<(x-1)));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	dsu.init(n);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(dsu.find(u)!=dsu.find(v)){
			dsu.merge(u,v);
			cnt++;
			ans+=w;
			g[cnt].u=u,g[cnt].v=v,g[cnt].w=w,g[cnt].id=cnt;
		}
		if(cnt==n-1) break;
	}
	dfs(1,0);
	cout<<ans;
//	cerr<<pp<<'\n';
	return 0;
}
