#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
constexpr int N=10024,M=1000006,K=13;
int n,m,k,fa[N],b[N],d,c[K],cnt,x;
struct A{int u,v,w;}g[M],p[M],q[M];
struct B{int v,w;}a[K][N];
long long ans,sum;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>k;for(int i=1;i<=m;++i) cin>>g[i].u>>g[i].v>>g[i].w;
	std::sort(g+1,g+m+1,[](A a,A b){return a.w<b.w;});
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int fu=find(g[i].u),fv=find(g[i].v);
		if(fu!=fv){fa[fv]=fu;ans+=g[i].w;b[++d]=i;}
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];for(int j=1;j<=n;++j){cin>>x;a[i][j]=B{j,x};}
		std::sort(a[i]+1,a[i]+n+1,[](B a,B b){return a.w<b.w;});
	}
	for(int i=1;i<(1<<k);++i){
		sum=cnt=0;
		for(int j=1;j<=d;++j) p[++cnt]=g[b[j]];
		for(int j=1;j<=k;++j)
			if((i>>j-1)&1){
				int s=1,t=1,c2=0;sum+=c[j];
				for(;s<=cnt&&t<=n;)
					if(p[s].w<=a[j][t].w){q[++c2]=p[s];++s;}
					else{q[++c2]=A{a[j][t].v,n+j,a[j][t].w};++t;}
				for(;s<=cnt;++s) q[++c2]=p[s];
				for(;t<=n;++t) q[++c2]=A{a[j][t].v,n+j,a[j][t].w};
				for(int l=1;l<=c2;++l) p[l]=q[l];cnt=c2;
			}
		for(int j=1;j<=n+k;++j) fa[j]=j;
		for(int j=1;j<=cnt;++j){
			int fu=find(p[j].u),fv=find(p[j].v);
			if(fu!=fv){fa[fv]=fu;sum+=p[j].w;}
		}
		ans=std::min(ans,sum);
	}
	cout<<ans;
	return 0;
}
