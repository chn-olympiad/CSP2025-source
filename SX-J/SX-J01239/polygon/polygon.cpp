#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	int i = 3, j = 3, k = 1;
	cin >> n;
	int a[n + 10] = {};
	for (int t = 1; t <= n; t++)
		cin >> a[t];
	sort(a + 1, a + n + 1);
	int answer = 0;
	for (i = 3; i <= n; i++) {
		int up = 1, down = 1;
		for (int ti = i; ti >= j; ti--)
			up = up * ti;
		for (int tj = j; tj >= 1; tj--) {
			down = down * tj;
		}
		int result = up / down;
		int tmp = 0;
		for (j = 3; j <= n; j++) {
			int sum = 0;
			for (k = 1; k <= j; k++) {
				sum += a[k];
			}
			if (a[j] * 2 >= sum) {
				tmp -= 1;
			}
			result -= tmp;
		}
		answer += result;
	}
	cout << answer;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
