#include <bits/stdc++.h>
using namespace std;


int hanshu(int n, int shuzu[100005][3], int MAX[100005][3],  int b1, int b2, int b3) {
	int sum;
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= 3; j++) {
			cin >> shuzu[i][j];
			MAX[i][j] = shuzu[i][j];
		}
		for (int j = 1; j <= 2; j++) {
			for (int q = j; q <= 2; q++) {
				if (MAX[i][q + 1] > MAX[i][q])
					swap(MAX[i][q], MAX[i][q + 1]);
			}
		}
		for (int z = 1; z <= n; z++) {
			MAX[z][0] = MAX[z][1] - MAX[z][2];
		}
		for (int k = 1; k <= 3; k++) {
			if (MAX[k] == shuzu[1]) {
				b1++;
			} else if (MAX[k] == shuzu[2]) {
				b2++;
			} else {
				b3++;
			}
		}
		int s = 0, s1 = 0;
		if (b1 > n / 2) {
			int shu = b1 - n / 2;
			for (int p = 1; p <= shu; p++) {
				for (int q = 1; q <= n; q++) {
					//s=min(s,MAX[0]);
					if (s > MAX[p][0]) {
						s = MAX[p][0];
						s1 = p;
					}
				}
				MAX[s1][0] = 1e9;
				swap(MAX[s1][1], MAX[s1][2]);
			}
		}
		sum = 0;
		for (int l = 1; l <= n; l++) {
			sum += MAX[l][0];
		}
	}

	return sum;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int shuzu[100005][3] = {0};
		int b1 = 0;
		int b2 = 0;
		int b3 = 0;

		int MAX[100005][3] = {{0}, {0}};
		int n;
		cin >> n;
		hanshu(n, shuzu, MAX, b1, b2, b3);
		cout << hanshu(n, shuzu, MAX, b1, b2, b3)
		     << '\n';
	}
	return 0;
}