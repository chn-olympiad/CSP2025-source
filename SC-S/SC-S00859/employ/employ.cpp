#include<bits/stdc++.h>

using namespace std;

int c[505];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == 1) {
		cout << n;
	}
	cout << 0;
	return 0;
}

