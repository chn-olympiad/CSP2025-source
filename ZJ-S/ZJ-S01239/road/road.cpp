#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define N (n+k)

struct Node{
	int to;
	int w;
};

struct Side{
	int from, to;
	int w;
};

int n, m, k, ans = 0, cnt = 0;
std::vector<Node> mp[500005];
std::vector<Side> sd;
bool vis[500005];
int num[500005][15];
int t[500005];

bool cmp(Side a, Side b){
	return a.w < b.w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	cnt = n - 1;
	for(int i = 1;i <= m;i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		mp[u].push_back({v, w});
		mp[v].push_back({u, w});
		sd.push_back({u, v, w});
		sd.push_back({v, u, w});
		for(int j = 1;j <= k;j++){
			mp[u + j * N].push_back({v + j * N, w});
			mp[v + j * N].push_back({u + j * N, w});
			sd.push_back({u + j * N, v + j * N, w});
			sd.push_back({v + j * N, u + j * N, w});
		}
	}
	for(int i = 1;i <= k;i++){
		int x, w;
		scanf("%d", &x);
		for(int j = 1;j <= n;j++){
			scanf("%d", &w);
			mp[j].push_back({n + i + i * N, x + w});
			mp[n + i + i * N].push_back({j, w});
			sd.push_back({j, n + i + i * N, x + w});
			num[j][n + i + i * N] = w;
		}
	}
	
	std::sort(sd.begin(), sd.end() - 1, cmp);
	vis[sd[0].from] = 1;
	for(int i = 0;i < sd.size();i++){
		Side it = sd[i];
		if(vis[it.to % N] == 0 and vis[it.from % N] == 1){
			ans += it.w;
			vis[it.to % N] = 1;
			if(it.to % N <= n and it.to > 0)
				cnt--;
			else{
				for(int j = 1;j <= n;j++){
					int tmp = num[j][it.to];
					sd.push_back({it.to, j, tmp});
				}
				std::sort(sd.begin(), sd.end() - 1, cmp);
			}
			if(t[it.to % N]){
				i = t[it.to % N];
				t[it.to % N] = 0;
			}
			sd.erase(sd.begin() + i);
		}
		else if(vis[it.to % N] == 1)
			sd.erase(sd.begin() + i);
		else if(vis[it.from % N] == 0)
			t[it.from % N] = i;
		if(cnt == 0){
			printf("%d", ans);
			return 0;
		}
	}
	return 0;
}