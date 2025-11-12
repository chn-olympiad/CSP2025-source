#include<bits/stdc++.h>
#define maxn 2010001
//#define int long long
using namespace std;
const int Mod=998244353,inf=1e9+7;
typedef long long ll;
int reduce(int x){return x-(x>=Mod)*Mod;}

int n,m,k,fa[20100],c[20100];
tuple<int,int,int>e[maxn],E[maxn];
int find(int x){
	while(fa[x]!=x) x=fa[x]=fa[fa[x]];
	return x;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		E[i]=make_tuple(w,u,v);
	}
	sort(E+1,E+m+1);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=get<1>(E[i]),v=get<2>(E[i]),w=get<0>(E[i]);
		if((u=find(u))==(v=find(v))) continue;
		e[++cnt]=E[i];
		fa[v]=u;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			e[++cnt]=make_tuple(w,j,n+i);
		}
	}
	sort(e+1,e+cnt+1);
	ll ans=(ll)1e18+7;
//	int Tim=0;
	for(int i=0;i<(1<<k);i++){
		ll res=0;
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=0;j<k;j++) if((i>>j)&1) res+=c[j+1];
//		Tim-=clock();
		for(int j=1;j<=cnt;j++){
			int u=get<1>(e[j]),v=get<2>(e[j]),w=get<0>(e[j]);
			if(v>n&&!((i>>(v-n-1))&1)) continue;
			if((u=find(u))==(v=find(v))) continue;
			res+=w;
			fa[v]=u;
		}
//		Tim+=clock();
//		cerr<<res<<' ';
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
//	cerr<<"Part Time: "<<Tim<<" ms\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
