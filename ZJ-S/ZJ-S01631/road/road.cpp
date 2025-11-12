#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
};
const int nn=1e6+5,mm=2e5+5;
node e[nn],g[mm],bf[mm];//,bf2[mm];
inline bool cmp(node l1,node l2){
	return l1.w<l2.w;
}
int fa[mm];
inline void init(){
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int cnt;
inline int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
inline bool merge(int u,int v){
	u=get(u),v=get(v);
	if(u==v) return 0;
	fa[u]=v;
	return 1;
}
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long 
const ll inf=1e18;
int c[15];
pii a[15][mm];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	init();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(merge(e[i].u,e[i].v)) g[++cnt]=e[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j].fi,a[i][j].se=j;
		sort(a[i]+1,a[i]+n+1);
	}
	ll ans=inf;
	for(int i=0;i<(1<<k);i++){
		init();
		ll co=0;
		int tm=n;
		for(int j=1;j<=cnt;j++) bf[j]=g[j];
		int tot=cnt;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				co+=c[j];
				if(co>=ans) break;
				tm++;
				int tmp=tot;
				for(int l=1;l<=n;l++){
					bf[++tot]=(node){tm,a[j][l].se,a[j][l].fi};
				}
				inplace_merge(bf+1,bf+tmp+1,bf+tot+1,cmp);
			}
		}
		for(int j=1;j<=tot;j++){
			if(merge(bf[j].u,bf[j].v)){
				co+=bf[j].w;
				if(co>=ans) break;
			}
		}
		ans=min(ans,co);
	}
	cout<<ans<<endl;
	return 0;
}

