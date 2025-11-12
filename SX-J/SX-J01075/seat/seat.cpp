#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat", "r", 'in');
	freopen("seat", "w", 'ont');
	int n, m, t = 0, cnt = 0, sum = 0;
	cin >> n >> m;
	int ma = INT_MIN;
	int s = n * m, x = 0, y = 0 ;
	int a[s];
	for (int i = 0; i < s; i++) {
		cin >> a[i];
		sum = a[1];
	}
	for (int i = 0; i < s - t; i++) {
		for (int j = 0; j < s ; j++) {
			if (a[j] > ma) {
				ma = a[j];
				t = j;
			}
		}
	}
	for (int i = 0; i < s; i++) {
		if (a[i] >= sum) {
			cnt++;
		}
	}
	if (cnt > m) {
		x = cnt / m;
		y = cnt % m;

	} else {
		x = 1;
		y = cnt + 1;
	}
	cout << x << " " << y;
	return 0;
}
