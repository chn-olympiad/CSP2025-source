#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int fa[10005];
int c[12],a[12][10005];
struct edge {
	int u,v,w;
} e[1100005];
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
int go(int p) {
	if(fa[p]==p)return p;
	else{
		fa[p]=go(fa[p]);
		return fa[p];
	}
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)cin>>e[i].u>>e[i].v>>e[i].w;
	if(k==0) {
		for(int i=1; i<=n; i++)fa[i]=i;
		sort(e+1,e+1+m,cmp);
		int ans=0,ch=0;
		for(int i=1; i<=m; i++) {
			if(go(e[i].u)!=go(e[i].v)) {
				fa[go(e[i].u)]=go(e[i].v);
				ch++;
				ans+=e[i].w;
				if(ch==n-1)break;
			}
		}
		cout<<ans;
	}
	return 0;
}
