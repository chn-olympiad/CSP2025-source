#include <bits/stdc++.h>
using namespace std;
int n, m, a[10086], sum = 1;



int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = n - m + 1; i <= n; i++) {
		sum *= i;
	}
	if (sum > 998)
		cout << sum % 998;
	else if (sum < 998 && sum > 353)
		cout << sum % 353;
	else if (sum < 353 && sum > 244) {
		cout << sum % 244;
	} else {
		cout << sum;
	}


}