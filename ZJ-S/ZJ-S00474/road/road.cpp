#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e6+5;

int n,m,k,minn=INT_MAX;
int c[N];
int a[N][5];
int vis[1005][1005],ttvis[1005][1005];
bool wis[N],tvis[N];
struct node {
	int u,w;
};
vector<node> G[1005];

bool check() {
	for(int i=1;i<=n;i++)
		if(!wis[i])
			return false;
	return true;
}
void dfs(int rt,int fa,int sum) {
//	cout<<rt<<'\n';
	wis[rt]=1;
	if(check()) {
//		cout<<sum<<'\n';
//		cout<<'\n';
		minn=min(minn,sum);
		return ;
	}
	for(int i=0;i<G[rt].size();i++) {		//    G[rt].size()
		if(vis[rt][i]>n-1 || vis[i][rt]>n-1)
			continue;
		int to=G[rt][i].u,val=G[rt][i].w;
//******************************************************
		for(int o=1;o<=k;o++) {
			if(!tvis[o]) {
				if(c[o]+a[o][rt]+a[o][to]<val) {
					sum+=c[o],tvis[o]=1;
					if(ttvis[o][to]>2*n-1||ttvis[to][o]>2*n-1||ttvis[o][rt]>2*n-1||ttvis[rt][o]>2*n-1)
						continue;
					if(!ttvis[o][to]||!ttvis[to][o])
						sum+=a[o][to];
					ttvis[o][to]++,ttvis[to][o]++,ttvis[o][rt]++,ttvis[rt][o]++;
					dfs(a[o][to],rt,sum);
				}
			}
			else {
				if(a[o][rt]+a[o][to]<val) {
					if(ttvis[o][to]>2*n-1||ttvis[to][o]>2*n-1||ttvis[o][rt]>2*n-1||ttvis[rt][o]>2*n-1)
						continue;
					if(!ttvis[o][to]||!ttvis[to][o]||!ttvis[o][rt]||!ttvis[rt][o])
						sum+=a[o][to];
					ttvis[o][to]++,ttvis[to][o]++,ttvis[o][rt]++,ttvis[rt][o]++;
					dfs(a[o][to],rt,sum);
				}
			}
		}
//******************************************************
//		cout<<fa<<' '<<rt<<' '<<to<<'\n';
		if(to==0&&val==0)
			continue;
		if(to==fa)
			continue;
		if(!vis[rt][i]||!vis[i][rt])
			sum+=val;
		vis[rt][i]++,vis[i][rt]++;
		dfs(to,rt,sum);
	}
	
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dfs(1,0,0);
	cout<<minn;
	return 0;
}
