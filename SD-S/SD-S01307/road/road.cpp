#include<bits/stdc++.h>
#define qwq return
#define F first
#define S second
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,o,k;
ll ans;
PII a[K][N];
int fa[N+K],c[K];
struct Edge{
	int x,y,w;
	bool operator< (const Edge &A)const {
		qwq w<A.w;
	}
}edge[M],e[M+N*K],e_[M+N*K];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	qwq x*f;
}
int find(int x) {qwq fa[x]==x?x:fa[x]=find(fa[x]);}
ll Kruskal() {
	ll res=0;
	for (int i=1;i<=n+o;i++) {fa[i]=i;}
	for (int i=1,j=0;i<=m && j<n+o-1;i++) {
		int x=find(e[i].x),y=find(e[i].y),w=e[i].w;
		if (x==y) {continue;}
		fa[x]=y;
		res+=1ll*e[i].w;
		j++;
		if (!o) {edge[j]={x,y,w};}
	}
	qwq res;
}
void merge(int p) {
	int i=1,j=1,cnt=0;
	while (i<=m || j<=n) {
		if (j>n || (i<=m && e[i].w<a[p][j].F)) {e_[++cnt]=e[i];i++;}
		else {e_[++cnt]={n+o,a[p][j].S,a[p][j].F};j++;}
	}
	for (int i=1;i<=cnt;i++) {e[i]=e_[i];}
	m=cnt;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++) {e[i]={read(),read(),read()};}
	for (int i=1;i<=k;i++) {
		c[i]=read();
		for (int j=1;j<=n;j++) {a[i][j]={read(),j};}
		sort(a[i]+1,a[i]+n+1);
	}
	sort(e+1,e+m+1);
	ans=Kruskal();
	for (int i=1;i<1<<k;i++) {
		ll res=0;
		o=0;
		for (int j=1;j<n;j++) {e[j]=edge[j];}
		m=n-1;
		for (int j=1;j<=k;j++) {
			if (i>>j-1&1) {o++;merge(j);res+=c[j];}
		}
		ans=min(ans,res+Kruskal());
	}
	printf("%lld\n",ans);
	qwq 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
[13]
*/
