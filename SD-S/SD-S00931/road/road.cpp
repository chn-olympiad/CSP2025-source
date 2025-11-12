#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,int> pii;
inline void rd(){}
template<typename T,typename ...U>
inline void rd(T &x,U &...args){
	T f=1;x=0;int ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	x*=f;rd(args...);
}
const int N=1e4+5,M=1e6+5;
const ll INF=1e18;
int n,m,k,c[15],v[15];
struct node{int x,y,z;}p[M],d[N*12];
namespace DSU{
	int fa[N+10],sz[N+10];
	inline void Init(){
		for(int i=1;i<=n+k;i++){
			fa[i]=i;sz[i]=1;
		}
	}
	inline int fd(int x){
		if(fa[x]==x)return x;
		return fa[x]=fd(fa[x]);
	}
	inline int Merge(int x,int y){
		x=fd(x);y=fd(y);
		if(x==y)return 0;
		if(sz[x]>sz[y])std::swap(x,y);
		fa[x]=y;sz[y]+=sz[x];
		return 1;
	}
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	rd(n,m,k);
	for(int i=1;i<=m;i++)rd(p[i].x,p[i].y,p[i].z);
	std::sort(p+1,p+m+1,[](node a,node b){return a.z<b.z;});
	
	DSU::Init();
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(DSU::Merge(p[i].x,p[i].y)){
			++cnt;
			d[k*n+cnt]=p[i];
		}
	}
	assert(cnt==n-1);
	
	for(int i=0;i<k;i++){
		rd(c[i]);
		for(int j=1;j<=n;j++){
			rd(d[i*n+j].z);
			d[i*n+j].x=i+1+n;
			d[i*n+j].y=j;
		}
	}
	std::sort(d+1,d+(k+1)*n,[](node a,node b){return a.z<b.z;});
	
	ll res=INF;
	
	for(int i=0;i<(1<<k);i++){
		ll ans=0;
		
		DSU::Init();
		
		for(int t=0;t<k;t++)if(i>>t&1)ans+=c[t];
		for(int t=0;t<k;t++)v[t]=(i>>t&1);
		
		for(int j=1;j<(k+1)*n;j++){
			if(d[j].x>n&&!v[d[j].x-n-1])continue;
			if(DSU::Merge(d[j].x,d[j].y))ans+=d[j].z;
		}
		
		res=std::min(res,ans);
	}
	printf("%lld\n",res);
	return 0;
}
