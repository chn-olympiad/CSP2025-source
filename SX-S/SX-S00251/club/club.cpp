#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[20001][3];

bool b[20001] = {false,};
void find(int u) {
	int max;
	int j1 = 0;
	int num = 0;
	int mmax = 0;
	int o[200001];
	for (int i = 1; i <= n; i++) {
		max = -1;
		for (int j = 1; j <= 3; j++) {
			if (a[i][j] > max && b[i] == false) {
				max = a[i][j];
				mmax = a[i][j];
				j1 = i;
			}
		}
		o[j1]++;
		if (o[j1] == u / 2) {
			b[j1] = true;
		}
		num += max;
	}
	cout << num << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (; t >= 1; t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				b[j] = false;
			}
		}
		find(n);
	}
	return 0;
}
