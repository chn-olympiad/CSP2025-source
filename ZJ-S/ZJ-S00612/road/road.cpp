//生命瞬间定格在脑海。
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+50,MAXM=1e6+10,MAX=1.1e5+10;
int po[15];
int n,m,k,N,M,fa[MAXN],f[MAXN],cnt;
long long c[15],a[15][MAXN],ans,minn;
struct edge{
	int u,v;
	long long w;
} e[MAXM],p[MAXN],zj[MAXN];
bool vis[MAXN][15];
int find(int x){ return (fa[x]==x?x:fa[x]=find(fa[x])); }
int Find(int x){ return (f[x]==x?x:f[x]=Find(f[x])); }
bool cmp(edge x,edge y){ return x.w<y.w; }
void init(){ for(int i=1;i<=n;i++) fa[i]=i; }
void Init(){ for(int i=1;i<=N;i++) f[i]=i; }
void solve(){
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	} sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		if(find(u)!=find(v)){
			p[++cnt]=e[i];
			ans+=e[i].w;
			fa[find(v)]=find(u);
		} if(cnt==n-1) break;
	} minn=ans;
	for(int i=1;i<po[k];i++){
		M=n-1,N=n,ans=0;
		for(int j=1;j<n;j++) zj[j]=p[j];
		for(int j=0;j<k;j++) if(i&po[j]){
			ans+=c[j+1],N++;
			for(int l=1;l<=n;l++) zj[++M]={l,N,a[j+1][l]};
		} sort(zj+1,zj+M+1,cmp);
		Init();
		int lxt=0;
		for(int j=1;j<=M;j++){
			int u=zj[j].u,v=zj[j].v;
			if(Find(u)!=Find(v)){
				ans+=zj[j].w;
				lxt++;
				f[Find(v)]=Find(u);
			} if(lxt==N-1) break;
		} minn=min(minn,ans);
	} cout<<minn<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	cin>>T;
	po[0]=1,po[1]=2,po[2]=4,po[3]=8,po[4]=16,po[5]=32,po[6]=64,po[7]=128,po[8]=256,po[9]=512,po[10]=1024;
	while(T--) solve();
	return 0;
}
