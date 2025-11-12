#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#define ll long long

template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}

const int INF=0x3f3f3f3f;

namespace Force{
	int n,m,k;
	const int maxv=1e4+5,maxe=2e6+5;
	int e,head[maxv];
	struct Edge{int to,next,v;}E[maxe];
	struct rec{int x,y,z;}E1[maxe];
	int a[maxv][maxv];
	int c[maxv];
	void add(int x,int y,int z){E[++e]=(Edge){y,head[x],z};head[x]=e;}

	bool cmp(const rec &a,const rec &b){return a.z<b.z;}
	
	int fa[maxv];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return false;
		fa[x]=y;
		return true;
	}

	void solve(int _n,int _m,int _k){
		n=_n,m=_m,k=_k;

		int e1=0;
		for(int i=1;i<=m;i++){
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			E1[++e1]=(rec){x,y,z};
			// add(x,y,z),add(y,x,z);
		}
		for(int i=1;i<=k;i++){
			scanf("%d",&c[i]);
			for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
		}

		bool is=true;
		for(int i=1;i<=k;i++) if(c[i]) is=false;
		if(is){
			for(int i=1;i<=k;i++){
				for(int j=1;j<=n;j++) E1[++e1]=(rec){i+n,j,a[i][j]};
			}
			n+=k;
		}

		std::sort(E1+1,E1+e1+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		int s1=0,ans=INF;
		for(int i=1;i<=e1;i++){
			if(merge(E1[i].x,E1[i].y)){
				s1+=E1[i].z;
				add(E1[i].x,E1[i].y,E1[i].z);
				add(E1[i].y,E1[i].x,E1[i].z);
			}
		}
		tense(ans,s1);
		printf("%d\n",ans);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	Force::solve(n,m,k);

	return 0;
}