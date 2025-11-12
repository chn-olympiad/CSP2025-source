#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
struct EDGE{int u,v,w;}e[2000005];
vector<pair<EDGE,int> >ee;
int fa[10105];
int Find(int u){while(u!=fa[u])u=fa[u]=fa[fa[u]];return u;}
int c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1,[&](EDGE u,EDGE v){return u.w<v.w;});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u!=v) fa[u]=v,ee.emplace_back(e[i],-1);
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++) cin>>w,ee.emplace_back(EDGE{n+i+1,j,w},i);
	}
	sort(ee.begin(),ee.end(),[&](pair<EDGE,int> u,pair<EDGE,int> v){return u.first.w<v.first.w;});
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++){
		ll tmp=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=0;j<k;j++) if((i>>j)&1) tmp+=c[j];
		for(auto x:ee) if(x.second==-1||(i>>x.second)&1){
			int u=Find(x.first.u),v=Find(x.first.v);
			if(u!=v) tmp+=x.first.w,fa[u]=v;
		}
		ans=min(ans,tmp);
	}
	cout<<ans<<"\n";
	// cerr<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	return 0;
}