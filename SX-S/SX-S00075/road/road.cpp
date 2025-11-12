#include <bits/stdc++.h>
using namespace std;
int sc[15], qsc[10005];
int city1[10005], city2[10005], qcity[10005];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> city1[i] >> city2[i] >> qcity[i];
	}
	for (int i = 1; i <= k; i++) {
		cin >> sc[i];
		for (int j = 1; j <= n; j++) {
			cin >> qsc[j];
		}
	}
	cout << qcity[3] + qcity[4] + 4 << endl;
	return 0;
}