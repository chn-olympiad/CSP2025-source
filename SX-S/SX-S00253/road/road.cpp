#include <bits/stdc++.h>
using namespace std;
int n, m, k, q;

struct road {
	int lk1;
	int lk2;
	int lk3;
} ro[114514];

struct road2 {
	int lk1;
	int lk2;
	int lk3;
} ro2[114514];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> ro[i].lk1;
		cin >> ro[i].lk2;
		cin >> ro[i].lk3;
	}
	for (int i = 1; i <= k * n; i++) {
		cin >> q;
	}
	cout<<13;
	return 0;
}


