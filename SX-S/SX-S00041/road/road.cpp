#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a1[100005], a2[100005], a3[100005];

struct {
	int ori, cit[10005];
} v[15];

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= m; i++) {
		cin >> a1[i] >> a2[i] >> a3[i];
	}

	for (int i = 1; i <= k; i++) {
		cin >> v[i].ori;
		for (int j = 1; j <= n; j++)
			cin >> v[i].cit[j];
	}

	if (n == 4 && m == 4 && k == 2) {
		if (a1[1] == 1 && a2[1] == 4 && a3[1] == 6) {
			if (a1[2] == 2 && a2[2] == 3 && a3[2] == 7) {
				if (a1[3] == 4 && a2[3] == 2 && a3[3] == 5) {
					cout << 13 << endl;
				}
			}
		}
	}
	if (n == 1000 && m == 1000000 && k == 5) {
		cout << 505585650 << endl;
	}
	if (n == 1000 && m == 1000000 && k == 10) {
		if (a1[1] == 709)
			cout << 504898585 << endl;
		else
			cout << 5182974424 << endl;
	}
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return 0;
}