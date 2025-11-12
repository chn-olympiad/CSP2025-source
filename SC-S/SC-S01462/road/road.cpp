#include<bits/stdc++.h>
using namespace std;using ll=long long;
const int N=1e4+2,M=1e6+2,K=12;int n,m,k,c[K],a[K][N];
struct DSU{
	int f[N+K];
	inline void init(int _n){for(int i=1;i<=_n;i++)f[i]=i;}
	inline int fnd(int x){return (f[x]==x?x:f[x]=fnd(f[x]));}
	inline void merge(int x,int y){f[fnd(x)]=fnd(y);}
	inline bool check(int x,int y){return fnd(x)==fnd(y);}
}dsu;
struct Edge{
	int x,y,w,id;
	inline friend bool operator <(const Edge a,const Edge b){return a.w<b.w;}
}e[M],E[N+K*N];int cnte,now;
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].w,e[i].id=-1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(e+1,e+m+1),dsu.init(n);
	for(int i=1;i<=m;i++)if(!dsu.check(e[i].x,e[i].y)){
		dsu.merge(e[i].x,e[i].y),E[++cnte]=e[i];
	}
	for(int i=1;i<=k;i++)for(int j=1;j<=n;j++)E[++cnte]=Edge{i+n,j,a[i][j],i-1};
	sort(E+1,E+cnte+1);ll Ans=1e18;
	for(int i=0;i<(1<<k);i++){
		now=cnte,dsu.init(n);ll ans=0;int cnt=0;
		for(int j=1;j<=k;j++)if((i>>(j-1))&1)ans+=c[j];
		dsu.init(n+k);
		for(int j=1;j<=cnte;j++)if(E[j].id==-1||((i>>E[j].id)&1)){
			if(!dsu.check(E[j].x,E[j].y))dsu.merge(E[j].x,E[j].y),ans+=E[j].w,cnt++;
		}
		if(cnt==n+__builtin_popcount(i)-1)Ans=min(Ans,ans);
	}
	return cout<<Ans<<"\n",0;
}