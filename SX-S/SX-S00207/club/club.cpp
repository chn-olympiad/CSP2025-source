#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long n, i, j, k, result;

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	cin >> t;

	for (k = 0; k < t; k++) {
		result = 0;
		cin >> n;
		long long a[n][3], a1[n], a2[n], at[n];

		for (i = 0; i < n; i ++) {
			for (j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
		}

		for (i = 0; i < n; i ++) {
			if (a[i][0] < a[i][1]) {
				swap(a[i][0], a[i][1]);
			}
			a1[i] = at[i] = a[i][0];
			a2[i] = a[i][1];
		}
		sort(a1, a1 + n, cmp);
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n; j++) {
				if (a1[i] == at[j]) {
					a2[j] = 0;
					break;
				}
			}
		}
		sort(a2, a2 + n, cmp);

		for (i = 0; i < n; i++) {
			result += a2[i];
		}
		for (i = 0; i < n / 2; i++) {
			result += a1[i];
		}
		cout << result << endl;
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
