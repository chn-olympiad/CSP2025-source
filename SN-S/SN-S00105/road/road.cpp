#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MX=1e6+20;
const int maxn=1e4+20;
int n,m,k,fa[maxn],c[11],tp,tt,ans,anss,zg;
struct edge{
	int l;
	int r;
	int v;
}e[MX],b[11][maxn],st[maxn],ss[MX],lin[MX];
inline int cmp(edge q,edge w){
	return q.v<w.v;
}
inline int find(int q){
	if(fa[q]==q){
		return q;
	}
	return fa[q]=find(fa[q]);
}
inline void bing(int q){
	zg=tt;
	for(int i=1;i<=tt;i++){
		lin[i]=ss[i];
	}
	tt=0;
	int L=0,R=0;
	while(L<zg){
		L++;
		while(R<n&&b[q][R+1].v<lin[L].v){
			R++;
			ss[++tt]=b[q][R];
		}
		ss[++tt]=lin[L];
	}
	while(R<n){
		R++;
		ss[++tt]=b[q][R];
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].l>>e[i].r>>e[i].v;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		if(find(e[i].l)!=find(e[i].r)){
			fa[find(e[i].l)]=find(e[i].r);
			st[++tp]=e[i];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			b[i][j].l=n+i;
			b[i][j].r=j;
			cin>>b[i][j].v;
		}
		sort(b[i]+1,b[i]+1+n,cmp);
	}
	ans=1e18;
	for(int i=0;i<(1<<k);i++){
		anss=0;
		tt=tp;
		for(int j=1;j<=tp;j++){
			ss[j]=st[j];
		}
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				anss+=c[j];
				bing(j);
			}
		}
		for(int j=1;j<=n+k;j++){
			fa[j]=j;
		}
		for(int j=1;j<=tt;j++){
			if(find(ss[j].l)!=find(ss[j].r)){
				fa[find(ss[j].l)]=find(ss[j].r);
				anss+=ss[j].v;
			}
		}
		ans=min(ans,anss);
	}
	cout<<ans<<'\n';
	return 0;
}
