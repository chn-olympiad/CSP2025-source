#include<bits/stdc++.h>
#define fir first
#define sec second
#define int long long
#define pii pair<int,int>
#define fep(i,s,e) for(int i=s;i<e;i++)
#define pef(i,s,e) for(int i=s;i>e;i--)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define per(i,s,e) for(int i=s;i>=e;i--)
namespace FastIO{
	template<typename T>inline void read(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);x*=f;
	}
	template<typename T,typename ...Args>
	inline void read(T &x,Args &...args){
		read(x);read(args...);
	}
	template<typename T>void print(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)print(x/10);
		putchar((x%10)^48);
	}
}
using namespace std;
using namespace FastIO;
const int N=1e4+7,M=1e6+7,K=17;
struct node{
	int u,v,w,typ;
};
int n,m,k,fa[N],c[K],a[K][N],ans=1e18,tmp;
vector<node>G;
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	int nx=find(x);
	int ny=find(y);
	if(nx==ny)return;
	fa[nx]=ny;
}
bool cmp(node a,node b){
	return a.w<b.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,k);
	rep(i,1,m){
		int u,v,w;
		read(u,v,w);
		G.emplace_back(node{u,v,w,0});
	}
	rep(i,1,k){
		read(c[i]);
		rep(j,1,n){
			read(a[i][j]);
		}
	}
	rep(i,1,k){
		rep(u,1,n){
			rep(v,u+1,n){
				G.emplace_back(node{u,v,(a[i][u]+a[i][v]),i});
			}
		}
	}
	sort(G.begin(),G.end(),cmp);
	fep(st,0,(1<<k)){
		tmp=0;
		rep(i,1,n)fa[i]=i;
		rep(i,1,k){
			if((st&(1<<(i-1)))!=0){
				tmp+=c[i];
				if(tmp>ans)break;
			}
		}
		if(tmp>ans)continue;
		fep(i,0,G.size()){
			if((G[i].typ!=0)&&((st&(1<<(G[i].typ-1)))==0))continue;
			if(find(G[i].u)==find(G[i].v))continue;
			join(G[i].u,G[i].v);
			tmp+=G[i].w;
			if(tmp>ans)break;
		}
		ans=min(ans,tmp);
	}
	print(ans);
	return 0;
}