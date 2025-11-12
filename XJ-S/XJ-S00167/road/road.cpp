#include <bits/stdc++.h>

using namespace std;

int n,m,k,c,a,w[10010][10010],vis[1000010],cnt[1000010];
long long ans;
vector <int> g[1000010];
queue <int> q;


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(g,0x3f3f3f,sizeof(g));
	for (int i=1;i<=m;i++){
		int u,v,ww;
		cin >> u >> v >> ww;
		cout << 1 <<m;
 		w[u][v] = ww;
 		w[v][u] = ww;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (k==0){
		q.push(1);
		vis[1] = 1;
		while(!q.empty()){
			int x = q.front();
			q.pop();
			for (int i=1;i<g[x].size();i++){
				if (vis[g[x][i]]==1)continue;
				else{
					cnt[g[x][i]] = max(cnt[g[x][i]],cnt[g[x][i]-1]+w[x][g[x][i]]);
					vis[g[x][i]] = 1;
					q.push(g[x][i]);
				}
			}
		}
		ans = cnt[n];
	}
	for (int i=1;i<=k;i++){
		cin >> c;
		for (int j=1;j<=n;i++){
			cin >> a;
			w[j][i] = w[i][j] = min(w[j][i],a+c);
		}
	}
	cout << ans;
	return 0;
} 
