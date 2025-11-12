#include<bits/stdc++.h>
#define int long long
#define R(x) x=read()
using namespace std;
inline int read() {
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^'0');
		c=getchar();
	}
	return x*y;
}
const int N=10025;
int n,m,k,ans=0x3f3f3f3f3f3f3f3f;
int tot;
struct node {
	int x,y,z,id;
} G[1100005];
int c[15],a[15][N];
bool flag=1;
bool cmp(node A,node B) {
	return A.z<B.z;
}
int fa[N];
int Find(int x) {
	if(x==fa[x])return x;
	return fa[x]=Find(fa[x]);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	R(n),R(m),R(k);
	for(int i=1; i<=m; ++i) {
		int x,y,z;
		R(x),R(y),R(z);
		++tot;
		G[tot].x=x,G[tot].y=y,G[tot].z=z;
		G[tot].id=-1;
	}
	for(int i=1; i<=k; ++i) {
		R(c[i]);
		if(c[i])flag=0;
		for(int j=1; j<=n; ++j) {
			R(a[i][j]);
			++tot;
			G[tot].x=n+i,G[tot].y=j,G[tot].z=a[i][j];
			G[tot].id=i;
		}
	}
	sort(G+1,G+1+tot,cmp);
	if(flag) {
		//48 pts
		ans=0;
		for(int i=1; i<=n+k; ++i) fa[i]=i;
		int cnt=n+k;
		for(int i=1; i<=tot; ++i) {
			int x=G[i].x,y=G[i].y,z=G[i].z;
			int fx=Find(x),fy=Find(y);
			if(fx!=fy) {
				ans+=z;
				fa[fx]=fy;
				--cnt;
				if(cnt==1)break;
			}
		}
		cout<<ans;
		return 0;
	}
	//Theta 2^k n?? 
	//but the worst case it may be up to 2^k m
	//hope it can pass.
	//anyway I have at least 72 pts
	//hope the "break" can help me.
	//RP++. 
	for(int s=0; s<(1<<k); ++s) {
		int res=0;
		int cnt=n;
		for(int i=1; i<=k; ++i) {
			if(s>>(i-1)&1) res+=c[i],++cnt;
		}
		if(res>=ans)continue;
		for(int i=1; i<=n+k; ++i) fa[i]=i;
		for(int i=1; i<=tot; ++i) {
			int id=G[i].id;
			if(id==-1||(s>>(id-1)&1)) {
				int x=G[i].x,y=G[i].y,z=G[i].z;
				int fx=Find(x),fy=Find(y);
				if(fx!=fy) {
					res+=z;
					fa[fx]=fy;
					--cnt;
					if(cnt==1)break;
					if(res>=ans) break;
				}
			}
		}
//		cout<<s<<" "<<res<<"\n";
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}

