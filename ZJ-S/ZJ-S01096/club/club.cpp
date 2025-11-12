#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define mk make_pair
const int N = 3e5 + 10, inf = 0x3FFFFFFF;
int n, a[4][N], ptt, cnt[4]; pii p[N]; bool vis[N];
struct node{ int x, y, z; };
struct cmp1{ bool operator()(node u, node v){ return u.z - u.y < v.z - v.y; } };
priority_queue<node, vector<node>, cmp1>q[4];
bool cmp(pii u, pii v){ return a[u.first][u.second] > a[v.first][v.second]; }
int calc(int x, int y){
	if(x == 1)return max(a[2][y], a[3][y]);
	if(x == 2)return max(a[1][y], a[3][y]);
	if(x == 3)return max(a[1][y], a[2][y]);
}
void solve(){
	cnt[1] = cnt[2] = cnt[3] = 0; ll ans = 0; ptt = 0;
	for(int i = 1; i < 4; i++){
		while(!q[i].empty())q[i].pop();
		q[i].push({0, inf, 0});
	}
	cin >> n; for(int i = 1; i <= n; i++)
		cin >> a[1][i] >> a[2][i] >> a[3][i];
	for(int i = 1; i <= n; i++)for(int j = 1; j < 4; j++)
		p[++ptt] = mk(j, i), vis[i] = 0; sort(p + 1, p + ptt + 1, cmp);
	for(int i = 1; i <= ptt; i++){
		int x = p[i].first, y = p[i].second;
		auto u = q[x].top();
		if(vis[y])continue;
		if(cnt[x] < n / 2){
			ans += a[x][y];
			vis[y] = 1;
			cnt[x]++; 
			q[x].push({y, a[x][y], calc(x, y)});
		}
		else{
			if(a[x][y] - calc(x, y) > u.y - u.z){
				ans += a[x][y] - u.y + u.z;
				q[x].pop(); vis[y] = 1;
				q[x].push({y, a[x][y], calc(x, y)});
			}
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(); cin.tie(0); cout.tie(0);
	int T; cin >> T; while(T--)solve(); return 0;
}