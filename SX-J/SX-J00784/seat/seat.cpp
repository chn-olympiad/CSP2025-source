#include <bits/stdc++.h>
using namespace std;
int a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, sum ;
	cin >> n >> m;
	int ans = n * m;
	for (int i = 1; i <= ans; i++)
		cin >> a[i];
	int arr = a[1];
	sort(a + 1, a + ans + 1);
	for (int i = 1; i <= ans; i++) {
		if (a[i] == arr) {
			sum = ans - i + 1;
			break;
		}
	}
	if (sum % n == 0) {
		cout << sum / n << " ";
		if ((sum / n) % 2 == 0)
			cout << "1";
		else
			cout << n;
	} else {
		cout << (sum / n) + 1 << " ";
		if (((sum / n) + 1) % 2 == 0)
			cout << ((sum / n) + 1) * 2 + 1 - sum;
		else
			cout << sum % n;
	}
	return 0;
}
