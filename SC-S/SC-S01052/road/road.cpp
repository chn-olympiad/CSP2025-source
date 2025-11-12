#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1e4+100,M=1e6+100,K=12;

const ll inf=0x3f3f3f3f3f3f3f3f;

struct edge{
	int u,v,w;
	bool operator < (const edge &t) const{
		return w<t.w;
	}
}e[M],mp[M];

int n,m,k,cnt=0;

int c[K],a[K][N];

int fa[N];

inline int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]);}

ll ans;

void init(){
	iota(fa+1,fa+1+n,1);
	sort(e+1,e+1+m);
	ll res=0;
	for(int i=1;i<=m;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		res+=e[i].w,mp[++cnt]=e[i];
		if(cnt==n-1) break;
	}
	ans=res;
}

ll kruskal(int now){
	for(int i=1;i<=cnt;i++) e[i]=mp[i];
	int tt=cnt,tot=0,sum=n;
	ll res=0;
	for(int i=1;i<=k;i++){
		if(!((now>>(i-1))&1)) continue;
		res+=c[i],sum++;
		if(res>ans) return inf;
		for(int j=1;j<=n;j++) e[++tt]={sum,j,a[i][j]};
	}
	iota(fa+1,fa+1+sum,1);
	sort(e+1,e+1+tt);
	for(int i=1;i<=tt;i++){
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		res+=e[i].w,tot++;
		if(res>=ans) return inf;
		if(tot==sum-1) break;
	}
	return res;
}

int main(){
	#ifndef Klein
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].w;
	init();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	for(int s=1;s<(1<<k);s++)
		ans=min(ans,kruskal(s));	
	cout<<ans;
	return 0;
}
