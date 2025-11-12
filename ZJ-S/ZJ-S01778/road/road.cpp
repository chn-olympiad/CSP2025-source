#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[11],a[11][10010],fa[10020];
long long ans;
struct tt {
	long long v,u,w;
} ed[1100010];
bool cmp(tt x,tt y) {
	return x.w<y.w;
}
int find(int x) {
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);
	}
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		for(int j=1; j<=n; j++) {
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1; i<=k; i++) {
		for(int j=1; j<=n; j++) {
			if(a[i][j]==0) {
				for(int p=1; p<=n; p++) {
					if(p==j) continue;
					ed[++m].u=j;
					ed[m].v=p;
					ed[m].w=a[i][p];
				}
				break;
			}
		}
	}
	sort(ed+1,ed+1+m,cmp);
	ans=0;
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=1; i<=m; i++) {
		if(find(ed[i].u)!=find(ed[i].v)) {
			fa[find(ed[i].u)]=find(ed[i].v);
			ans+=ed[i].w;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
