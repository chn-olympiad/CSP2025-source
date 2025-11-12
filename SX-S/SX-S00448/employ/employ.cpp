#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

vector<int> wait(5010);

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string exam;
	cin >> exam;

	for (int i = 1; i <= n; i ++) {
		cin >> wait[i];
	}

	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans % = mod;
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}