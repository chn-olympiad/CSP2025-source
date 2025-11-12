#include <bits/stdc++.h>
using namespace std;
int f[100005][5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int p;
	int n;
	cin >> n;
	int sb = 0;
	for (int i = 1; i <= p; p++) {
		cin >> p;
		for (int x = 1; x <= n; n++) {
			for (int y = 1; y <= 3; y++) {
				cin >> f[x][y];
			}
		}
	}
	for (int d = 1; d <= n; d++) {
		for (int w = 0; w <= 3; w++) {
			if (f[d][1] > f[d][2] || f[d][1] > f[d][3]) {
				sb += f[d][1];
			} else if (f[d][3] > f[d][2] || f[d][3] > f[d][1]) {
				sb += f[d][3];
			} else if (f[d][2] > f[d][1] || f[d][2] > f[d][3]) {
				sb += f[d][2];
			}
		}
	}
	
	cout << sb << endl;
	return 0;
}