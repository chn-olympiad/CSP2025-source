#include <bits/stdc++.h>
using namespace std;
int n, m;
int sum;
vector<int> c;
int cnt, ans;
int d = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i / m < n; i++) {
		if (i == 0)
			c.push_back(sum);
	}
	sort(c.begin(), c.end(), cmp);

	d++;
	cnt = (d / n ) + 1;
	ans = (d % n) + 1;
	if (d % n == 0) {
		cnt--;
	}
	cout << cnt << " " << ans;
	return 0;
}
