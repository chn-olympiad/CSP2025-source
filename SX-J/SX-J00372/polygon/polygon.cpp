#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int arr[1000086];
bool b;

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] != 1)
			b = 1;
	}
	if (n < 3)
		cout << 0;
	else if (n == 3) {
		sort(arr + 1, arr + n + 1);
		if (arr[1] + arr[2] > arr[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (b == 0) {
		cout << ((n - 1) * (n - 2) / 2) % 998244353;
	}
	return 0;
}
