#include<bits/stdc++.h>
#define intt long long
using namespace std;
const intt maxx=1e9+1;
int n,m,k,u,v,w,rw[1145],a[1145][11451],adj[11451][11451];
intt ans;
bool vis[1145141];
struct myst {
	intt en,dist;
	bool operator<(const myst &k)const {
		return k.dist<dist;
	}
};
priority_queue<myst>q1,q2;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			adj[i][j]=maxx;
			if(i==j)
				adj[i][j]=0;
		}

	for(int i=1; i<=m; i++) {
		cin>>u>>v>>w;
		if(w<adj[u][v]);
		adj[u][v]=w;
		adj[v][u]=w;
	}
	for(int i=1; i<=k; i++) {
		cin>>rw[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
		for(int j=1; j<=n; j++)
			for(int kk=1; kk<=n; kk++) {
				if(a[i][j]+a[i][kk]<adj[j][kk]) {
					adj[j][kk]=a[i][j]+a[i][kk];
					adj[kk][j]=a[i][j]+a[i][kk];
				}
			}
	}
	vis[1]=1;
	for(int i=2; i<=n; i++) {
		q1.push({i,adj[1][i]});
	}
	while(!q1.empty()) {
		myst thi;
		while(!q1.empty()) {
			thi=q1.top();
			if(vis[q1.top().en]==0) {
				q1.pop();
				break;
			}
			q1.pop();
		}
		if(vis[q1.top().en]==1)
			break;
		ans+=thi.dist;
		vis[thi.en]=1;
		for(int i=1; i<=n; i++) {
			if(vis[i]==0) {
				q1.push({i,adj[thi.en][i]});
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
