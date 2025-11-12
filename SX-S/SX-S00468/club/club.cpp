#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> sat(n, vector<int>(3, 0));
		for (int i = 0; i < n; i++) {
			cin >> sat[i][0] >> sat[i][1] >> sat[i][2];
		}
		vector<vector<int>> mem(3);
		for (int i = 0; i < n; i++) {
			if (sat[i][0] >= sat[i][1]) {
				if (sat[i][0] >= sat[i][2]) {
					mem[0].push_back(sat[i][0]);
				} else {
					mem[2].push_back(sat[i][2]);
				}
			} else {
				if (sat[i][1] >= sat[i][2]) {
					mem[1].push_back(sat[i][1]);
				} else {
					mem[2].push_back(sat[i][2]);
				}
			}
		}
//		for (int k = 0; k < 3; k++) {
//			for (int i = 0; i < mem[k].size(); i++) {
//				for (int j = 0; j < mem[k].size() - i; j++) {
//					if (mem[k][j] > mem[k][j + 1]) {
//						swap(mem[k][j], mem[k][j + 1]);
//					}
//				}
//			}
//		}
		for (int i = 0; i < 3; i++) {
			sort(mem[i].begin(), mem[i].end(), cmp);
		}
		for (int i = 0; i < n; i++) {
			if (mem[i].size() > (n / 2)) {
				ans -= mem[0][mem[0].size() - 1];
				mem.pop_back();
			}
		}
	}
	return 0;
}
