#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	t -= 1;
	while (t--) {
		int chose_n[2] = {};
		int n;
		cin >> n;
		int value[n][9] = {};
		int flag_max[n] = {};
		int flag_min[n] = {};
		for (int i = 0; i < n; i++) {
			value[i][7] = 1e6;
			for (int j = 0; j < 3; j++) {
				cin >> value[i][j];
				if (value[i][j] > value[i][3]) {
					value[i][3] = value[i][j];
					flag_max[i] = j;
				}
			}
			chose_n[flag_max[i]]++;
			for (int j = 4; j < 7; j++) {
				value[i][j] = value[i][3] - value[i][j - 4];
				if (value[i][j] < value[i][7] && value[i][j] != 0 && value[i][7] != 0) {
					value[i][7] = value[i][j] ;
					flag_min[i] = j - 4;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += value[i][3];
		}
judge:
		bool overnum = true;
		int label = 0;
		for (int i = 0; i < 3; i++) {
			if (chose_n[i] > n / 2) {
				overnum = false;
				label = i;
			}
		}
		if (overnum) {
			cout << sum << endl;
		} else {
			int min_of_min = 1e6;
			int a = 0;
			for (int i = 0; i < n; i++) {
				if (value[i][7] < min_of_min && value[i][7] != 0) {
					min_of_min = value[i][7];
					value[i][7] = 0;
					a = i;
				}
			}
			sum -= min_of_min;
			chose_n[label]--;
			chose_n[flag_min[a]]++;
			goto judge;
		}
	}
	return 0;
}