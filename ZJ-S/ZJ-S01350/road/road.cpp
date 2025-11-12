#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge {
	int x,y,w;
	edge(int _x=0,int _y=0,int _w=0) {
		x=_x;
		y=_y;
		w=_w;
	}
	bool operator < (edge b) const {
		return w<b.w;
	}
	bool operator > (edge b) const {
		return w>b.w;
	}
};
template <typename type>
inline void read(type &x) {
	x=0;
	bool flag(0);
	char ch=getchar();
	while(!isdigit(ch)) flag=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	flag?x=-x:0;
}
int n,m,k,ans=1e18,u,v,w,c[15],a[15][10015],f[10015];
int Find(int x) {
	if(x!=f[x]) f[x]=Find(f[x]);
	return f[x];
}
priority_queue <edge,vector<edge>,greater<edge> > q,q1;
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1; i<=m; i++) {
		read(u),read(v),read(w);
		q.push(edge(u,v,w));
	}
	for(int i=1; i<=k; i++) {
		read(c[i]);
		for(int j=1; j<=n; j++) read(a[i][j]);
	}
	for(int i=0; i<(1<<k); i++) {
		q1=q;
		int sum=0,cnt=0,cnt1=n-1;
		for(int j=0; j<k; j++) {
			if(i&(1<<j)) {
				sum+=c[j+1];
				for(int u=1; u<=n; u++) {
					q1.push(edge(cnt1+2,u,a[j+1][u]));
				}
				cnt1++;
			}
		}
		if(sum<ans) {
			int _x1,_y1,fx,fy;
			for(int j=1; j<=cnt1+1; j++) f[j]=j;
			while(q1.size()) {
				_x1=q1.top().x,_y1=q1.top().y;
				fx=Find(_x1),fy=Find(_y1);
				if(fx!=fy) {
					f[fx]=fy;
					sum+=q1.top().w;
					cnt++;
				}
				if(sum>=ans) break;
				if(cnt>=cnt1) break;
				q1.pop();
			}
			if(cnt>=cnt1) ans=min(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}