#include <bits/stdc++.h>
using namespace std;

vector<int> num(1, 0);
vector<vector<int>> Map(114, vector<int>(114, 0));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	cin >> num[0];
	int me = num[0];
	for (int i = 1; i < n * m; i ++) {
		int x;
		cin >> x;
		num.push_back(x);
	}

	sort(num.begin(), num.end());
	bool isTail = false;
	int x = 1, y = 1;
	for (int i = n * m - 1; i >= 0; i --) {
		Map[x][y] = num[i];
		if (Map[x][y] == me) {
			cout << y << ' ' << x;
			break;
		}
		x += isTail ? -1 : 1;
		if (x > n) {
			x = n;
			y ++;
			isTail = true;
		}
		if (x < 1) {
			x = 1;
			y ++;
			isTail = false;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
