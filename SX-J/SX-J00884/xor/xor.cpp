#include <bits/stdc++.h>
using namespace std;
int n[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int k, l;
	cin >> l >> k;
	for (int i = 1; i <= l; i++) {
		cin >> n[i];
	}
	int a;
	for (int i = l; i >= 1; i--) {
		for (int j = 1; j <= l - i + 1; j++) {
			a = 0;
			//	cout << j << " ";
			for (int x = j; x <= j + i - 1; x++) {
				a = (a | n[x]);
			}
			if (a == k) {
				cout << i;
				i = 0;
				break;
			}
		}
	}
	return 0;
}

