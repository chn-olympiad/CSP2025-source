#include<bits/stdc++.h>
#define ll long long
#define Suika 0
using namespace std;
const int N=20010,M=2000010;
int n,m,k;
struct Edge {
	int u,v;
	ll w;
} e[M],e1[M];
bool cmp(Edge a,Edge b) {
	return a.w<b.w;
}
int fa[N];
ll a[20][N],c[20],ans=1e9;
int find(int x) {
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main() {
//	double bgn=clock();
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	bool f=1;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0) f=0;
		for(int j=1; j<=n; j++) cin>>a[i][j];
	}
	if(f) {
		int cnt=m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				ll res=1e18;
				for(int l=1; l<=k; l++) res=min(res,a[l][j]+a[l][i]);
				e[++cnt]={i,j,res};
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1; i<=n; i++) fa[i]=i;
		ll res=0;
		int tot=0;
		for(int i=1; i<=cnt; i++) {
			int u=e[i].u,v=e[i].v;
			u=find(u);
			v=find(v);
			if(u!=v) {
				fa[u]=v;
				res+=e[i].w;
				tot++;
			}
			if(tot==n-1) break;
		}
		cout<<res;
	//	double ed=clock();
	//	cerr<<"\n"<<(ed-bgn)*1000/CLOCKS_PER_SEC;
		return Suika;
	}
	for(int msk=0; msk<(1<<k); msk++) {
		for(int i=1; i<=m; i++) {
			e1[i].u=e[i].u;
			e1[i].v=e[i].v;
			e1[i].w=e[i].w;
		}
		int id=n,cnt=m;
		for(int i=1; i<=k; i++) {
			if(!(msk&(1<<(i-1)))) continue;
			id++;
			for(int j=1; j<=n; j++) e1[++cnt]={id,j,a[i][j]};
			id++;
			e1[++cnt]={id,id-1,c[i]};
		}
		sort(e1+1,e1+cnt+1,cmp);
	//	cout<<((double)(clock())-bgn)*1000/CLOCKS_PER_SEC<<"\n";
	//	for(int i=1; i<=cnt; i++) cout<<e1[i].u<<" "<<e1[i].v<<" "<<e1[i].w<<"\n";
		for(int i=1; i<=id; i++) fa[i]=i;
		ll res=0;
		int tot=0;
		for(int i=1; i<=cnt; i++) {
			int u=e1[i].u,v=e1[i].v;
			u=find(u);
			v=find(v);
			if(u!=v) {
				fa[u]=v;
				res+=e1[i].w;
				tot++;
			}
			if(tot==id-1) break;
		}
	//	cout<<res<<"\n";
		ans=min(ans,res);
	}
	cout<<ans;
//	double ed=clock();
//	cerr<<"\n"<<(ed-bgn)*1000/CLOCKS_PER_SEC;
	return Suika;
} 