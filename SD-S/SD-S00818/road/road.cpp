#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
#define endl "\n"
using namespace std;
bool st;
const int N=1e4+20,M=1e6+10;
int n,m,p,a[N][13],c[N],tot,ans;
struct edge{
	int u,v,w;
	bool operator <(edge it)const{
		return w<it.w;
	}
}e[M],ee[13][N],ade[M],nowe[M<<1],te[M];
struct dsu{
	int f[N],sz[N];
	void clear(){
		for(int i=1;i<=n+p;i++)f[i]=i,sz[i]=1;
	}
	int find(int x){
		return f[x]==x?x:f[x]=find(f[x]);
	}
	bool merge(int u,int v){
		int fu=find(u),fv=find(v);
		if(fu==fv)return 0;
		(sz[fu]>=sz[fv])&&(fu^=fv^=fu^=fv);
		f[fu]=fv;sz[fv]+=sz[fu];return 1;
	}
}f;
void dfs(int x,int res){
	if(x>p){
		for(int i=1;i<=tot;i++)te[i]=ade[i];
		sort(te+1,te+1+tot);
		int a=1,b=1,cnt=0;
		for(;a<=m&&b<=tot;){
			if(e[a]<te[b])nowe[++cnt]=e[a++];
			else nowe[++cnt]=te[b++];
		}
		while(a<=m)nowe[++cnt]=e[a++];
		while(b<=tot)nowe[++cnt]=te[b++];
		f.clear();
		for(int i=1;i<=cnt;i++){
			(f.merge(nowe[i].u,nowe[i].v))&&(res+=nowe[i].w);
		}ans=min(ans,res);
		return;
	}
	if(res+c[x]<=ans){
		for(int i=1;i<=n;i++)ade[++tot]=ee[x][i];
		dfs(x+1,res+c[x]);tot-=n;
	}
	dfs(x+1,res);
}
void solve(){int res=0;
	for(int i=1;i<=p;i++){
		for(int k=1;k<=n;k++){
			e[++m]=ee[i][k];
		}
	}
	sort(e+1,e+1+m);f.clear();
	for(int i=1;i<=m;i++){
		(f.merge(e[i].u,e[i].v))&&(res+=e[i].w);
	}
	cout<<res<<endl;return;
}
bool ed;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>p;ans=1e18;int bo=0;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}sort(e+1,e+1+m);
	for(int i=1;i<=p;i++){
		cin>>c[i];if(c[i])bo=1;
		for(int k=1;k<=n;k++){
			int w;cin>>w;
			ee[i][k]={n+i,k,w};
		}
		sort(ee[i]+1,ee[i]+1+n);
	}
	if(!bo){
		solve();
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

