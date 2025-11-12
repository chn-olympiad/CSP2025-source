#include <bits/stdc++.h>
using namespace std;
string a;
int t[11];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' and a[i] <= '9') {
			t[a[i] - '0']++;
		}

	}
	for (int i = 9; i >= 0; i--) {
		while (t[i]--)
			cout << i;
	}

	return 0;
}
