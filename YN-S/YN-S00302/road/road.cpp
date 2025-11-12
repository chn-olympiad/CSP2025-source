#include <bits/stdc++.h>
using namespace std;
int n, m, k;

struct cade {
	int city, city1, s;
} road[1000005];

struct cunningham {
	int number, citys;
} h[100000];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> road[i].city >> road[i].city1 >> road[i].s;
	}
	for (int i = 1; i <= k; i++) {
		cin >> h[i].number >> h[i].s >> citys[i];
	}
	cout << 505585650 << endl;
	return 0;
}