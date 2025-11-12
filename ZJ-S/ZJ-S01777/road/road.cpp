#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,KK=15,M=1e6+5,MM=1200; 
#define fst first
#define scd second
#define llg long long
#define pii pair<int,int>
#define mkp make_pair
const int inf=2e9;

int fa[N],c[N],a[KK][N],len[MM][N],p[KK];
int num[MM<<1],val[KK],siz[N];

struct edge{
	int u,v; long long w;
}edg[M],g[N],G[N];

int n,m,K,cnt;
llg ans;

inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return ((fa[x]==x) ? x : fa[x]=find(fa[x]));
}
inline int lowbit(int x){
	return x&(-x);
}
inline bool merge(int x,int y){
	if(find(x)==find(y)) return false;
	x=fa[x],y=fa[y];
	if(siz[x]<siz[y]) swap(x,y); 
	fa[y]=x; siz[x]+=siz[y];
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1; i<=11; i++) num[(1<<(i-1))]=i,val[i]=(1<<(i-1));
	cin>>n>>m>>K;
	for(int i=1; i<=m; i++){
		int u,v,w; cin>>u>>v>>w;
		edg[i]={u,v,w};
	}
	for(int i=1; i<=K; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++)
			 cin>>a[i][j];
		llg now=0; a[i][now]=inf;
		for(int j=1; j<=n; j++)
			if(a[i][j]<a[i][now]) now=j;
		c[i]+=a[i][now]; a[i][now]=inf;
		p[i]=now;
	}
	sort(edg+1,edg+m+1,cmp);
	for(int i=1; i<=n; i++) fa[i]=i,siz[i]=1;
	for(int i=1; i<=m; i++){
		if(merge(edg[i].u,edg[i].v)){
			G[++cnt]=edg[i]; ans+=edg[i].w;
		}
	}
//	cout<<(cnt+1==n)<<"\n";
//	llg l=0;
//	for(int j=1; j<n; j++) l+=G[j].w; cout<<l<<"\n";
	for(int i=1; i<=n; i++) a[0][i]=inf;
	for(int i=1; i<(1<<K); i++){
		int h=num[lowbit(i)]; int t=i-val[h];
		llg cur=0; cnt=0; int tt=0;
		for(int j=1; j<=n; j++) fa[j]=j,siz[j]=1;
		for(int j=1; j<=K; j++)
			if(i&val[j]) cur+=c[j];
		for(int j=1; j<=n; j++){
			len[i][j]=h;
			if(a[h][j]>a[len[t][j]][j])
				len[i][j]=len[t][j];
			if(a[len[i][j]][j]<=G[n-1].w) 
				g[++cnt]={p[len[i][j]],j,a[len[i][j]][j]};
		}
		sort(g+1,g+cnt+1,cmp);
	//	cout<<cur<<"\n";
		for(int j=1,k=1; j<n; j++){
		//	cout<<g[j].u<<" "<<g[j].v<<" "<<g[j].w<<"\n";
			for(; k<=cnt&&g[k].w<=G[j].w&&tt<n-1; k++){
			//	if(g[k].u>n||g[k].v>n) return 0;
				if(merge(g[k].u,g[k].v))
					cur+=g[k].w,tt++;
			}
			if(merge(G[j].u,G[j].v))
				cur+=G[j].w;
		}
		//for(int j=1; j<n; j++) cur+=g[j].w;
		//cout<<ans<<" "<<cur<<"\n";
		ans=min(ans,cur);
	}
	cout<<ans<<"\n";
}
