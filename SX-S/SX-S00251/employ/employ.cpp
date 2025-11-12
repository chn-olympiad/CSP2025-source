#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string a;
	cin >> a;
	int num = 0;
	for (int i = 1; i <= a.size(); i++) {
		if (a[i] == 1) {
			num++;
		}
	}
	long long end = 1;
	if (n = m) {
		if (n = num) {
			for (int i = 2; i <= n; i++) {
				end *= i;
			}
			cout << end << endl;
		}
	} else {
		cout << 0;
	}
	return 0;
}
