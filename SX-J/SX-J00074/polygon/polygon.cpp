#include <bits/stdc++.h>
using namespace std;
int l[5005];

int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int num = 0;
	int maxn = 0;
	for (int i = 1; i <= 3; i++) {
		cin >> l[i];
		maxn = max(maxn, l[i]);
		num += l[i];
	}
	if (num > 2 * maxn)
		cout << "1";
	else
		cout << 0;
	return 0;
}