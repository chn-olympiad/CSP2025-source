#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,k;
struct Node {
	int u,v,w;
};
Node a[N*2];
int c[N],tp[N];
int f[N];
int ans;
int ci1[20],ci[20][N];
bool cmp(Node a,Node b) {
	return a.w<b.w;
}

int find(int x) {
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++) {
		f[i]=i;
	}
	for(int i=1; i<=m; i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int t=m;
	for(int i=1; i<=k; i++) {
		int x, cnt=0;
		cin>>x;
		ci1[i]=x;
		for(int j=1; j<=n; j++) {
			cin>>c[j];
			if(c[j]==0) {
				tp[++cnt]=j;
			}
		}
		for(int i1=1; i1<=cnt; i1++) {
			for(int j=1; j<=n; j++) {
				if(tp[i1]==j) continue;
				t++;
				a[t].u=tp[i1],a[t].v=j,a[t].w=c[j];
			}
		}
	}
	sort(a+1,a+1+t,cmp);
	for(int i=1; i<=t; i++) {
		int u=a[i].u,v=a[i].v,w=a[i].w;
		u=find(u),v=find(v);
		if(u!=v) {
			f[u]=v;
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}
