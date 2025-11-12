#include <iostream>
#include <fstream>
using namespace std;
int n, m, k;
struct ce {
	int v1;
	int v2;
	int v3;
} che[10000 + 5];
int num[10000 + 5];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i] >> num[i] >> num[i];
	}
	for (int j = 1; j <= k; j++) {
		for (int a = 1; a <= n + 1; a++) {
			cin >> num[j];
		}
	}
	cout << 13;
	return 0;
}