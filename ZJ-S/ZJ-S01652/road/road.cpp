#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,M=1e6+100;
struct Node {
	int u,v,w;
} b[M];
long long a[15][N],c[15],e[N][N],f[N],vis[N];
int findf(int x) {
	if(f[x]==x) {
		return x;
	}
	return f[x]=findf(f[x]);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			e[i][j]=LONG_LONG_MAX;
		}
	}
	for(int i=1; i<=n; i++) {
		e[i][i]=0;
		f[i]=i;
	}
	for(int i=1; i<=m; i++) {
		long long u,v,w;
		cin>>u>>v>>w;
		e[u][v]=e[v][u]=min(w,min(e[u][v],e[v][u]));
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1; i<=k; i++) {
		for(int x=1; x<=n; x++) {
			for(int y=1; y<=n; y++) {
				e[x][y]=min(e[x][y],a[i][x]+a[i][y]);
			}
		}
	}
	long long cnt=0;
	priority_queue<pair<long long,long long> > q;
	int tot=0;
	for(int x=1; x<=n; x++) {
		for(int y=1; y<=n; y++) {
			if(e[x][y]<LONG_LONG_MAX&&x!=y) {
				tot++;
				q.push(make_pair(-e[x][y],tot));
				Node pp= {x,y};
				b[tot]=pp;
			}
		}
	}
	int tmp=0;
	while(!q.empty()) {
		int w=-q.top().first,idx=q.top().second;
		q.pop();
		int x=b[idx].u,y=b[idx].v;
		int fx=findf(x),fy=findf(y);
		if(fx!=fy) {
			f[fx]=fy;
			cnt+=w;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
