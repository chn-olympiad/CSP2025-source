#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+25,M=1e6+5;long long n,m,k,nm=0,num=0,c[15],a[15][N],ans;struct node{long long x,y,z;}d[M],g[M+2*N],h[M];inline bool cmp(node x,node y){return x.z<y.z;}
struct DSU{long long f[N];inline void init(){for(int i=1;i<=n+k;i++) f[i]=i;}inline long long find(long long x){return x==f[x]?x:(f[x]=find(f[x]));}inline void merge(long long x,long long y){f[find(x)]=find(y);}}dsu;
inline long long wk(){for(int i=1;i<=k;i++) if(c[i]) return 0;return 1;}
inline void work(long long kkk){
	num=nm;for(int i=1;i<=nm;i++) g[i]=h[i];for(int i=1;i<=k;i++) if((1<<(i-1))&kkk) for(int j=1;j<=n;j++) g[++num]=node{i+n,j,a[i][j]};sort(g+1,g+num+1,cmp),dsu.init();
	long long cnt=0;for(int i=1;i<=num;i++) if(dsu.find(g[i].x)!=dsu.find(g[i].y)) dsu.merge(g[i].x,g[i].y),cnt+=g[i].z;
	for(int i=1;i<=k;i++) if((1<<(i-1))&kkk) cnt+=c[i];ans=min(ans,cnt);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;for(int i=1;i<=m;i++) cin>>d[i].x>>d[i].y>>d[i].z;sort(d+1,d+m+1,cmp),dsu.init();
	for(int i=1;i<=m;i++) if(dsu.find(d[i].x)!=dsu.find(d[i].y)) h[++nm]=d[i],dsu.merge(d[i].x,d[i].y),ans+=d[i].z;
	for(int i=1;i<=k;i++){cin>>c[i];for(int j=1;j<=n;j++) cin>>a[i][j];}
	if(wk()){work((1<<k)-1);cout<<ans;return 0;}
	for(int i=1;i<(1<<k);i++) work(i);cout<<ans;
	return 0;
}
