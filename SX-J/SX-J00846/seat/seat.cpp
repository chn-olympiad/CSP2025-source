#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a = n * m;
	int b[a], c[a];
	for (int i = 1; i <= a; i++) {
		cin >> b[i];
		c[i] = b[i];
	}
	for (int j = 1; j < a; j++) {
		for (int i = 1; i < a; i++) {
			if (c[i] < c[i + 1]) {
				int s = c[i];
				c[i] = c[i + 1];
				c[i + 1] = s;
			}
		}
	}
	int f;
	for (int i = 1; i <= a; i++) {
		if (c[i] == b[1]) {
			f = i;
			break;
		}
	}
	int p = f / n;
	int g = f % n;
	if (g == 0) {
		if (p % 2 == 0) {
			cout << p << " " << 1;
		} else
			cout << p << " " << n;
	} else if (g != 0 && p % 2 == 0)
		cout << p + 1 << " " << g;
	else
		cout << p + 1 << " " << n - g + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
