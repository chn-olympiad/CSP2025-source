#include <bits/stdc++.h>
using namespace std;
inline long long read() { long long x = 0 , f = 1; char c = getchar(); while(c < '0' || '9' < c) {	if(c == '-') f = -1; c = getchar(); } while('0' <= c && c <= '9') { x = x*10 + c-'0'; c = getchar(); } return x * f; }
const int N=1e4+5;
const int K=11;
const int M=1e6+5;
struct edge{
	int u,v,w;
	inline bool operator < (const edge &a) const { return w < a.w ; }
};
int n,m,k,v,w,u,fa[N],a[K][N],c[K],esum;
bool SPA=1,zzz[N];
long long ans;
vector <edge> es;
int f(int x){ return fa[x] == x ? x : fa[x] = f(fa[x]) ; }
inline bool cmp(const edge &a,const edge &b) { return a.w < b.w ; }
signed main() {
	 freopen("road.in" , "r" , stdin);
	 freopen("road.out" , "w" , stdout);
	scanf("%d%d%d",&n,&m,&k),es.reserve(m);
	while(m--)
		scanf("%d%d%d",&u,&v,&w),es.emplace_back((edge){u,v,w});
	for(int i=1;i<=k;i++){
		scanf("%d",c+i);
		for(int j=1;j<=n;j++)
			scanf("%d",a[i]+j),zzz[j]|=!a[i][j];
		if(c[i])
			SPA=0;
	}
	if(!k){
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(es.begin(),es.end(),cmp);
		for(edge ed:es)
			if(f(ed.u)!=f(ed.v))
				fa[f(ed.u)]=f(ed.v),ans+=ed.w;
		cout<<ans; 
	}
	else if(SPA){
		priority_queue<edge> q; 
		for(int i=1;i<=n;i++)
			fa[i]=i;
		sort(es.begin(),es.end(),cmp);
		for(edge ed:es)
			if(f(ed.u)!=f(ed.v)){
				fa[f(ed.u)]=f(ed.v),ans+=ed.w;
				if(zzz[ed.u]||zzz[ed.v])
					q.push(ed);
			}
		while(k&&!q.empty()){
			if(zzz[q.top().u])
				ans-=q.top().w,k--,zzz[q.top().u]=0;
			else if(zzz[q.top().v])
				ans-=q.top().w,k--,zzz[q.top().v]=0;
			q.pop();
		}
		cout<<ans;
	}
	return 0;
}
