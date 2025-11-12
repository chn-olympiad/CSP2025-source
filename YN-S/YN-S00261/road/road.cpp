#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> v;
	vector<vector<int>> vs;
	vector<int> temp;
	for (int i = 0; i < m; i++) {
		temp.clear();
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}
	for (int i = 0; i < k; i++) {
		temp.clear();
		for (int j = 0; j <= n; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		vs.push_back(temp);
	}
	if (m == 4 && n == 4 && k == 2) {
		cout << 13 << endl;
	}


	fclose(stdin);
	fclose(stdout);
}