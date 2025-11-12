#include <bits/stdc++.h>
#define ED cerr<<'\n';
#define TS cerr<<"I AK IOI\n";
#define cr(x) cerr<<x<<'\n';
#define cr2(x,y) cerr<<x<<" "<<y<<'\n';
#define cr3(x,y,z) cerr<<x<<" "<<y<<" "<<z<<'\n';
#define cr4(x,y,z,w) cerr<<x<<" "<<y<<" "<<z<<" "<<w<<'\n';
#define pr(a,l,r) for(int iii=l;iii<=r;++iii) cerr<<a[iii]<<" ";ED
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define epb emplace_back
#define ull unsigned long long
using namespace std;
const int N=1e4+20,M=1e6+20,mod=1e9+7,INF=2e9;
int T,n,m,k;

void read(int &x) {
	register int f=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
}

struct edge {
	int u,v,w;
	bool operator<(const edge &W) const {
		return w<W.w;
	}
}e[M],a[11][N];
int fa[N],len=0,_len=0;
int c[11],p[11],sz[11];

int find(int u) {
	if(u==fa[u]) return u;
	else return fa[u]=find(fa[u]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=m;++i) {
		read(e[i].u),read(e[i].v),read(e[i].w);
	}
	for(int i=0;i<k;++i) {
		read(c[i]);
		for(int j=1;j<=n;++j) {
			read(a[i][j].w);
			a[i][j].u=n+i+1,a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+1+n),sz[i]=n;
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n;++i) {
		fa[i]=i;
	}
	ll ans=0;int qwq=0;
	for(int i=1;i<=m;++i) {
		int u=find(e[i].u);
		int v=find(e[i].v);
		if(u!=v) {
			fa[u]=v,a[k][++sz[k]]=e[i],++qwq;
			ans+=e[i].w;
			if(qwq>=n-1) break;
		}
	}
	for(int i=1;i<(1<<k);++i) {
		for(int j=1;j<=n+k;++j) {
			fa[j]=j;
		}
		vector<int> s;ll cst=0;
		s.epb(k),p[k]=1;
		for(int j=0;j<k;++j) {
			if((i>>j)&1) {
				s.epb(j),cst+=c[j],p[j]=1;
			}
		}
		int Sz=s.size();qwq=0;
		for(int j=1;j<=n*Sz;++j) {
			int mi=INF,id=0;
			for(auto it:s) {
				if(p[it]<=sz[it]) {
					int v=a[it][p[it]].w;
					if(v<mi) {
						mi=v,id=it;
					}
				}
			}
			edge x=a[id][p[id]];
			int u=find(x.u),v=find(x.v);
			if(u!=v) {
				fa[u]=v,cst+=x.w,++qwq;
				if(qwq>=n+Sz-2) break;
			}
			++p[id];
		}
		ans=min(ans,cst);
	}
	printf("%lld\n",ans);
	return 0;
}

