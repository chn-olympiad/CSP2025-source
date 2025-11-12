#include <bits/stdc++.h> // 100pts
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e1 + 5;

int n, m, a[N * N], num, cnt;

inline bool cmp(int x, int y) {
	return x > y;
}

inline int solve(int x) {
	int top = 1;
	while (1) {
		if (a[top] == x)
			break;
		top++;
	}
	
	return top;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; ++i)
		cin >> a[i];
	num = a[1];
	
	sort(a + 1, a + 1 + (n * m), cmp);
	int id = solve(num);
	if (id == 1) {
		cout << "1 1\n";
		return 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		bool flag = i % 2;
		if (flag) {
			for (int j = 1; j <= m; ++j) {
				cnt++;
				if (cnt == id)
					return cout << i << " " << j << endl, 0;
			}
		} else {
			for (int j = m; j >= 1; --j) {
				cnt++;
				if (cnt == id)
					return cout << i << " " << j << endl, 0;
			}
		}
	}
	return 0;
}

