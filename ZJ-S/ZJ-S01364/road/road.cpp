//48pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
vector<node>g[10005];
int u[1000005],v[1000005],w[1000005];
int c[15],a[15][10005];
struct edge{
	int u,v,w;
}e[1100005];
int f[100015];
int query(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
void merge(int x,int y){
	f[query(y)]=query(x);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int bns=1e14;
void dfs(int x,int st){
	if(x==n+1){
		st<<=1;
		int cnt=0;
		for(int i=1;i<=m;++i){
			e[++cnt].u=u[i];
			e[cnt].v=v[i];
			e[cnt].w=w[i];
		}
		for(int i=1;i<=k;++i)if(st&(1<<k)){
			for(int j=1;j<=n;++j){
				e[++cnt].u=n+i;
				e[cnt].v=j;
				e[cnt].w=a[i][j];
			}
		}
		for(int i=1;i<=n+k;++i)f[i]=i;
		sort(e+1,e+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;++i){
			int p=e[i].u,q=e[i].v,c=e[i].w;
			if(query(p)!=query(q)){
				merge(p,q);
				ans+=c;
			}
		}
		bns=min(bns,ans);
		return;
	}
	dfs(x+1,st<<1);
	dfs(x+1,st<<1|1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)cin>>u[i]>>v[i]>>w[i];
	bool flag=1;
	for(int i=1;i<=k;++i){
		cin>>c[i];
		flag&=!c[i];
		for(int j=1;j<=n;++j)cin>>a[i][j];
	}
	if(flag){
		int cnt=0;
		for(int i=1;i<=m;++i){
			e[++cnt].u=u[i];
			e[cnt].v=v[i];
			e[cnt].w=w[i];
		}
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				e[++cnt].u=n+i;
				e[cnt].v=j;
				e[cnt].w=a[i][j];
			}
		}
		for(int i=1;i<=n+k;++i)f[i]=i;
		sort(e+1,e+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;++i){
			int p=e[i].u,q=e[i].v,c=e[i].w;
			if(query(p)!=query(q)){
				merge(p,q);
				ans+=c;
			}
		}
		cout<<ans;
	}else if(!k){
		int cnt=0;
		for(int i=1;i<=m;++i){
			e[++cnt].u=u[i];
			e[cnt].v=v[i];
			e[cnt].w=w[i];
		}
		for(int i=1;i<=n;++i)f[i]=i;
		sort(e+1,e+cnt+1,cmp);
		int ans=0;
		for(int i=1;i<=cnt;++i){
			int p=e[i].u,q=e[i].v,c=e[i].w;
			if(query(p)!=query(q)){
				merge(p,q);
				ans+=c;
			}
		}
		cout<<ans;
	}else if(k<=5){
		dfs(1,0);
		cout<<bns;
	}
	return 0;
}
