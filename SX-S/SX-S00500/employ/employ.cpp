#include <bits/stdc++.h>
using namespace std;
int n, m, c[505];
char ch[505];
bool book[505];
long long cnt;

inline void f(int rank, int sum) {
	if (rank >= n) {
		if (sum >= m) {
			cnt++;
		}
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (book[i] == 1 || c[i] < rank - sum) {
			continue;
		}
		book[i] = 0;
		if (ch[rank] == '0') {
			f(rank + 1, sum);
		} else {
			f(rank + 1, sum + 1);
		}
		book[i] = 1;
	}
}

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> ch[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	f(0, 0);
	cout << cnt - 1 << '\n';

	return 0;
}
