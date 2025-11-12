//4pts
#include<bits/stdc++.h>
using namespace std;
int p[1000010];
struct uu {
	int a, b, c;
};
bool cmp(uu a, uu b) {
	return a.c < b.c;
}
int f(int x) {
	if (p[x] == x) return x;
	else return p[x] = f(p[x]);
}
void add(int a, int b) {
	p[a] = b;
}
vector<uu> v;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
//		cin >> x >> y >> z;
		v.push_back({x, y, z});
	}
	for (int i = 1; i <= k; i++) {
		int x;
		cin>>x;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
//			cin >> x;
			v.push_back({i, j, x});
		}
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int ans = 0;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < m + n * k; i++) {
		if (f(v[i].a) != f(v[i].b)) {
			add(v[i].b, v[i].a);
			ans += v[i].c;
		}
	}
	cout << ans;
}
//rp++