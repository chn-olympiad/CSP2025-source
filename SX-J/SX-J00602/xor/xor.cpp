#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		int t = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
				t++;
		}
		cout << t;
		return 0;
	} else if (k == 0) {
		int x = 0;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0 && flag)
				x++;
			else if (a[i] == 1 && a[i + 1] == 1 && flag) {
				x++;
				flag = false;
				continue;
			}
			flag = true;
		}
		cout << x;
		return 0;
	}
	cout << 1;
	return 0;
}
