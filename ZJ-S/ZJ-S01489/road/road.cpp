#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k, f[10005], val[105], qaq, a[15][10005], sum[10005];
bool cho[1005];
vector<int> G[10005];
struct node{
	int u, v, c;
}E[1000005];
vector<node> vec;
int find(int x){
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
int Kruskal(){
	int ans = 0;
	for (int i = 1; i <= m; i++){
		int u = E[i].u, v = E[i].v, c = E[i].c;
		int fu = find(u), fv = find(v);
		if (fu == fv)
			continue;
		f[fu] = fv;
		vec.emplace_back((node){u, v, c});
		ans += c;
	}
	return ans;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
		cin >> E[i].u >> E[i].v >> E[i].c;
	sort(E + 1, E + 1 + m, [](node x, node y){return x.c < y.c;});
	qaq = Kruskal();
	for (int i = 0; i < vec.size(); i++)
		E[i + 1] = vec[i];
	int cnt = n - 1;
	for (int i = 1; i <= k; i++){
		cin >> val[i];
	//	cerr << val[i] << "\n";
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for (int S = 0; S < (1 << k); S++){
		for (int i = 0; i < vec.size(); i++)
			E[i + 1] = vec[i];
		int cnt = n - 1;
		for (int i = 1; i <= k; i++){	
			if (S & (1 << i - 1)){
				for (int j = 1; j <= n; j++){
					++cnt;
					E[cnt].u = n + i;
					E[cnt].v = j;
					E[cnt].c = a[i][j];
				}
			}
		}
		for (int i = 1; i <= n + k; i++)
			f[i] = i;
		sort(E + 1, E + 1 + cnt, [](node x, node y){return x.c < y.c;});
		int sum = 0;
		for (int i = 1; i <= cnt; i++){
			int u = E[i].u, v = E[i].v, c = E[i].c;
			int fu = find(u), fv = find(v);
			if (fu == fv)
				continue;
			f[fu] = fv;
			sum += c;
		}
		for (int i = 1; i <= k; i++)
			if (S & (1 << i - 1))
				sum += val[i];
	//	if (S <= 100)
	//		cerr << S << " " << sum << "\n";
	//	system("pause");
		qaq = min(qaq, sum);
	}
	cout << qaq;
	return 0;
}//幽默自己强项不会做。 
