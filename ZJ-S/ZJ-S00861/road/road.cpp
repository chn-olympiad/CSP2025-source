#include <queue>
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define int unsigned long long
#define pir pair<int, pair<int, int>>
using namespace std;

const int N = 1e7 + 50;
const int M = 1e4 + 10;
int n, m, k;
struct Edge{
	int to, w, ne;
} edge[N];
int head[N], idx;
bool vis[50];
int c[50];
bool v[N];
int ans = 0;

void add(int x, int y, int z){
	edge[++ idx] = {y, z, head[x]};
	head[x] = idx;
}

bool cmp(pir a, pir b){
	return a.first > b.first;
}

void p(){
	int cnt = 0;
	priority_queue<pir, vector<pir>, greater<pir>> pq;
	pq.push(make_pair(0, make_pair(1, -1)));
	while (!pq.empty() && cnt < n){
		int w = pq.top().first, u = pq.top().second.first;
		int pre = pq.top().second.second;
		pq.pop();
		if (!v[u]){
			v[u] = true;
			cnt ++;
			if (pre > n){
				vis[pre - n] = true;
			}
			ans += w;
			for (int i = head[u];i;i = edge[i].ne){
				int to = edge[i].to, we = edge[i].w;
				if (to > n){
					if (!vis[to - n]){
						we += c[to - n];
					}
					for (int j = head[to];j;j = edge[j].ne){
						int too = edge[j].to, wei = edge[j].w;
						if (!v[too]){
							pq.push(make_pair(we + wei, make_pair(too, to)));
						}
					}
				} else {
					if (!v[to]){
						pq.push(make_pair(we, make_pair(to, u)));
					}
				}
			}
		}
	}
	return ;
}

signed main(){
	fast;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	while (m --){
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 1;i <= k;i ++){
		cin >> c[i];
		for (int j = 1;j <= n;j ++){
			int z;
			cin >> z;
			add(i + n, j, z);
			add(j, i + n, z);
		}
	}
	p();
	cout << ans << endl;
	return 0;
}
