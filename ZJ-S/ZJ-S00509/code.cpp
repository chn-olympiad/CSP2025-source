#include<bits/stdc++.h>
#define maxn 2010001
#define fi first
#define se second
//#define int long long
using namespace std;
const int Mod=998244353,inf=1e9+7;
typedef long long ll;
int reduce(int x){return x-(x>=Mod)*Mod;}

int n,m,k,fa[20100],c[20100];
pair<int,int>a[12][10100];
tuple<int,int,int>e[maxn],E[maxn],cur[maxn];
ll ans;
int find(int x){
	while(fa[x]!=x) x=fa[x]=fa[fa[x]];
	return x;
}
void dfs(int x,int L,int len){
	if(L==k){
		ll res=0;
		for(int i=1;i<=len;i++) res+=get<0>(e[i]);
		ans=min(ans,res);
		return;
	}
	dfs(x<<1,L+1,len);
	vector<tuple<int,int,int> >vec;
	vec.resize(len);
	for(int i=1;i<=len;i++) vec[i-1]=e[i];
	len=0;
	int j=1;
	for(auto i:vec){
		while(j<=n&&a[L+1][j].fi<=(get<0>(i))) cur[++len]=make_tuple(a[L+1][j].fi,n+L+1,a[L+1][j].se),j++;
		cur[++len]=i;
	}
	while(j<=n) cur[++len]=make_tuple(a[L+1][j].fi,n+L+1,a[L+1][j].se),j++;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=0;
	for(int i=1;i<=len;i++){
		int u=get<1>(cur[i]),v=get<2>(cur[i]),w=get<0>(cur[i]);
		if((u=find(u))==(v=find(v))) continue;
		e[++cnt]=cur[i];
		fa[v]=u;
	}
	len=cnt;
	dfs(x<<1|1,L+1,len);
	len=vec.size();
	for(int i=1;i<=len;i++) e[i]=vec[i-1];
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
			a[i][j]=make_pair(w,j);
		}
		sort(a[i]+1,a[i]+n+1);
	}
	ans=(ll)1e18+7;
	dfs(0,0,cnt);
	cout<<ans<<'\n';
}
signed main(){
	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	init();
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
