#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
const int N=1e4+20,M=1e6+10;
int n,m,k;
int a[11][N],c[11];
vector<PII> g[N];
queue<PII> q;
bool vis[N];
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	scanf("%lld %lld %lld",&n,&m,&k);
	int n2=n;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1; i<=k; i++) {
		scanf("%lld",&c[i]);
//		n++;
		for(int j=1; j<=n2; j++) {
			scanf("%lld",&a[i][j]);
//			dis[n][j]=dis[j][n]=a[i][j];
//			g[n].push_back(j);
//			g[j].push_back(n);
		}
	}
	q.push({1,0});
	vis[1]=1;
	while(!q.empty()) {
		int now=q.front().first;
		int val=q.front().second;
		q.pop();
		for(int j=0; j<g[now].size(); j++) {
			vis[j]=1;
			
			
		
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

