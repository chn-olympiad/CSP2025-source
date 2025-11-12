#include <bits/stdc++.h>
using namespace std;
int n[1000010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int ct = 0;
	for (int i = 0; i < a; i++) {
		cin >> n[i];
	}
	ct = n[0];
	int ans = n[1];
	for (int i = 2; i < a; i++) {
		ans = ans ^n[i];
	}
	cout << (ct + ans) / 2;
	return 0;
}
