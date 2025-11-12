#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;

const int N=1e4+5,M=1e6+5;
int n,m,k,c[15];
struct edge {
	int u,v,w;
} a[M];
vector<edge> b;
namespace dsu {
int fa[2*N];
void init () {
	F(i,1,n+k) fa[i]=i;
}
int find (int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge (int x,int y) {
	fa[find(x)]=find(y);
}
}
int main () {
	freopen ("road.in","r",stdin);
	freopen ("road.out","w",stdout);
	ios::sync_with_stdio (0); cin.tie (0);
	cin>>n>>m>>k;
	int u,v,w;
	F(i,1,m) cin>>a[i].u>>a[i].v>>a[i].w;
	sort (a+1,a+m+1,[](const edge &x,const edge &y) {
		return x.w<y.w;
	});
	dsu::init ();
	F(i,1,m) {
		if (dsu::find(a[i].u)!=dsu::find(a[i].v)) {
			dsu::merge (a[i].u,a[i].v);
			b.push_back (a[i]);
		}
	}
	F(i,1,k) {
		cin>>c[i];
		int tmp;
		F(j,1,n) {
			cin>>tmp;
			b.push_back ({i+n,j,tmp});
		}
	}
	sort (b.begin (),b.end (),[](const edge &x,const edge &y) {
		return x.w<y.w;
	});
	ll ans=1e18,cur;
	F(i,0,(1<<k)-1) {
		cur=0;
		F(j,1,k) {
			if ((i>>(j-1))&1) cur+=c[j];
		}
		dsu::init ();
		for (auto j:b) {
			if (j.u>n&&!((i>>(j.u-n-1))&1)) continue;
			if (dsu::find(j.u)!=dsu::find(j.v)) {
				cur+=j.w;
				dsu::merge (j.u,j.v);
			}
		}
		ans=min(ans,cur);
	}
	cout<<ans<<"\n";
	return 0;
}