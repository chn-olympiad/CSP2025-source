#include <bits/stdc++.h>
using namespace std;
vector<int> save;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int my = 0;
	for (int x = 0; x < n * m; x++) {
		int t;
		cin >> t;
		if (x == 0)
			my = t;
		save.push_back(t);
	}
	sort(save.begin(), save.end(), cmp);
	int rank = -1;
	for (int x = 0; x < n * m; x++) {
		if (save[x] == my) {
			rank = x + 1;
			break;
		}
	}
	int lie = rank / n;
	if (rank % n != 0)
		lie += 1;
	cout << lie << ' ';
	if (lie % 2 == 1) {
		cout << n - lie*n + rank;
	} else {
		cout << lie*n - rank + 1;
	}
	return 0;
}


