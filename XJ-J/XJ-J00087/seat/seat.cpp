#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> scores(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> scores[i];
	}
	int R = scores[0];
	int pos;
	sort(scores.begin(), scores.end(), cmp);
	for (int i = 0; i < n * m; i++) {
		if (scores[i] == R) {
			pos = i;
			break;
		}
	}
	int y = pos / n;
	cout << y + 1 << ' ';
	int x = pos % n;
	if (y % 2 == 1) {
		if (x <= n / 2) {
			int xx = (n - 1) - 2 * x;
			x += xx;
		} else {
			int xx = 2 * x + 1 - n;
			x -= xx;
		}
	}
	cout << x + 1;
	return 0;
}
