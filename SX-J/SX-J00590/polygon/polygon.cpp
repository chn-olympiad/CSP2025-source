#include <bits/stdc++.h>
using namespace std;
int a[3005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int l = 1; l <= n; l++) {
		cin >> a[l];
	}

	int sum = 0;
	while (true) {
		int i = 3;
		sum += n / i;
		i++;
	}
	cin >> sum;
	return 0;

}
