#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long n, k, a[N], b[N], c[N], ans, sum[N], num;
long long a1, b1, c1;

void fun(int a2, int b2, int c2) {
	if (a2 <= ans && b2 <= ans && c2 <= ans)
		return;

	for (int i = 1; i <= k; i++) {

		if (sum[i])
			num += sum[i];
		else
			sum[i] = max(b2, c2);

	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	while (n--) {
		ans = k / 2;

		for (int i = 1; i <= k; i++) {

			sum[i] = max(max(a[i], b[i]), c[i]);

			if (sum[i] == a[i]) {
				a1++;
				fun(a1, 0, 0);
				num += a[i];
			} else if (sum[i] == b[i]) {
				b1++;
				fun(b1, 0, 0);
				num += b[i];
			} else if (sum[i] == c[i]) {
				c1++;
				fun(c1, 0, 0);
				num += c[i];
			}

		}

		cout << num;
	}

	return 0;
}