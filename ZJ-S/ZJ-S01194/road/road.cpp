#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+5;
const int M = 1e6+5;
int n,m,k;
int ui,vi,wi;
int cnt=0;
long long ans;
int fa[N];
int cj,aj;
bool flag=true;
bool tag=true;
int find(int x) {
	if(x==fa[x]) return fa[x];
	fa[x]=find(fa[x]);
	return fa[x];
}
struct node {
	int u;
	int v;
	int val;
};
node Map[M];
int KMap[15][N];
int pre[15];
bool cmp(node a,node b) {
	return a.val < b.val;
}
void Kruscal(int edge) {
	for(int i=1; i<=n; i++) {
		fa[i]=i;
	}
	sort(Map+1,Map+m+edge+1,cmp);
	for(int i=1; i<=m+edge; i++) {
		int nx=Map[i].u;
		int ny=Map[i].v;
		int mx=find(nx);
		int my=find(ny);
		if(mx==my) continue;
		ans+=Map[i].val;
		fa[mx]=my;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans<<endl;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	if(k!=0) tag=false;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&ui,&vi,&wi);
		Map[i].u=ui;
		Map[i].v=vi;
		Map[i].val=wi;
	}
	for(int i=1; i<=k; i++) {
		scanf("%d",&cj);
		if(cj!=0) flag=false;
		for(int j=1; j<=n; j++) {
			scanf("%d",&aj);
			KMap[i][j]=aj;
			if(aj==0) pre[i]=j;
		}
	}
	if(tag==true) {
		Kruscal(0);
	} else if(flag==true) {
		int edge=0;
		sort(Map+1,Map+m+edge+1,cmp);
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				if(j!=pre[i]) {
					++edge;
					Map[m+edge].u=pre[i];
					Map[m+edge].v=j;
					Map[m+edge].val=KMap[i][j];
				}
			}
		}
		Kruscal(edge);
	} else {
		int edge=0;
		sort(Map+1,Map+m+edge+1,cmp);
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				if(j!=pre[i]) {
					++edge;
					Map[m+edge].u=pre[i];
					Map[m+edge].v=j;
					Map[m+edge].val=KMap[i][j];
				}
			}
		}
		Kruscal(edge);
	}
	return 0;
}