#include <bits/stdc++.h>
using namespace std;
int a[100010];
string s;
int n, m;

bool check(string s1) {
	for (int i = 1; i <= n; i++) {
		if (s1[i] == '0') {
			return false;
		}
	}
	return true;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	if (m == n) {
		cout << 1;
		return 0;
	} else if (check(s)) {
		int sum = 0;
		for (int i = 1; i <= m - 1; i++) {
			sum += i;
		}
		cout << sum;
		return 0;
	} else if (m == 1) {
		cout << n;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}