#include <bits/stdc++.h>
using namespace std;
#define MAXM 2000006
#define MAXN 10004
#define ll long long
int n,m,k;

struct edge{
	int u,v;
	ll w;
	friend bool operator<(edge a,edge b){
		return a.w<b.w;
	}
}e[MAXM];

int fa[MAXN];

int get(int x){
	if (x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}

int paired(int x,int y){
	ll fax=get(x),fay=get(y);
	fa[fax]=fay;
}

int cnt;

int main(){
	cin.tie(0);ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v;ll w;
		cin>>u>>v>>w;
		e[++cnt].u=u;
		e[cnt].v=v;
		e[cnt].w=w;
	}
	for (int i=1+n;i<=k+n;i++){
		ll c;cin>>c;
		for (int j=1;j<=n;j++){
			ll aa;cin>>aa;
			e[++cnt].u=i;
			e[cnt].v=j;
			e[cnt].w=aa;
		}
	}
	for (int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+cnt+1);
	ll ans=0;
	for (int i=1;i<=cnt;i++){
		if (get(e[i].u)==get(e[i].v)) continue;
		ans+=e[i].w;
		paired(e[i].u,e[i].v);
	}
	cout<<ans<<endl;
	return 0;
}
