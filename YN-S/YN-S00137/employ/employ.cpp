#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, num = 0;
	cin >> n >> m;
	string a;
	cin >> a;

	for (int i = 0; i < n; i++) {

		num++;

		if (num == m)
			break;

		if (a[i] == 0)
			break;
	}

	cout << num;

	return 0;
}