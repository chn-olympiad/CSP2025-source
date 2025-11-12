#include<bits/stdc++.h>
using namespace std;
int n,m,k,cntG;
struct node {
	int u,v,w;
} G[40000005];
long long ans;
int f[10005];
void init() {
	for(int i=1; i<=n; i++) {
		f[i]=i;
	}
}
int getf(int x) {
	if(f[x]==x) return x;
	else return f[x]=getf(f[x]);
}
void merge(int x,int y) {
	int fx=getf(x),fy=getf(y);
	if(x!=y) {
		f[fx]=fy;
	}
}
bool cmp(node x,node y) {
	return x.w<y.w;
}
void kruskal() {
	int cnt=0;
	for(int i=1; i<=cntG; i++) {
		int u=getf(G[i].u),v=getf(G[i].v);
		if(u==v) continue;
		merge(u,v);
//		cout<<G[i].u<<" "<<G[i].v<<" "<<G[i].w<<endl;
		cnt++;
		ans+=G[i].w;
		if(cnt==n-1) break;
	}
	cout<<ans<<endl;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1; i<=m; i++) {
		cntG++;
		cin>>G[cntG].u>>G[cntG].v>>G[cntG].w;
	}
	if(k==0) {
		sort(G+1,G+cntG+1,cmp);
		kruskal();
		return 0;
	}
	for(int i=1; i<=k; i++) {
		int now;
		cin>>now;
		int x[10005];
		for(int j=1; j<=n; j++) {
			cin>>x[j];
		}
		for(int j=1; j<=n; j++) {
			for(int k=j+1; k<=n; k++) {
				cntG++;
				G[cntG].u=j,G[cntG].v=k,G[cntG].w=x[j]+x[k]+now;
			}
		}
	}
	sort(G+1,G+cntG+1,cmp);
	kruskal();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
