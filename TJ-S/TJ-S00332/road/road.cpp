#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5e1;
int n, m, k, kd = 1001, ans = -1;
struct lu{
	int to = 0, cost = 0;
	lu(int hj, int klf){
		to = hj;
		cost = klf;
	}
};
vector <lu> a[MAXN];
bool mis[MAXN];
bool cmp(lu x, lu y){
	return x.cost < y.cost;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(lu(v,w));
		a[v].push_back(lu(u,w));
	}
	for(int i = 0; i < k; i++){
		int klpp;
		cin >> klpp;
		for(int i = 1; i <= n; i++){
			int w;
			cin >> w;
			a[kd].push_back(lu(i,w));
			a[i].push_back(lu(kd,w));
		}
		kd++;
	}
	deque <lu> dq;
	dq.push_back(lu(1, 0));
	while(!dq.empty()){
		int dian = dq.front().to, sost = dq.front().cost;
		dq.pop_front();
		mis[dian] = 1;
		ans = max(ans, sost);
		for(int i = 0; i < a[dian].size(); i++){
			if(!mis[a[dian][i].to]){
				dq.push_back(lu(a[dian][i].to, sost + a[dian][i].cost));
				mis[a[dian][i].to] = 1;
			}
		}
		sort(dq.begin(), dq.end(), cmp);
	}
	cout << ans << endl;
	return 0;
}
