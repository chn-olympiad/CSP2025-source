#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long s, t, sum = 0;
	cin >> s;
	int ans[1000009], w = s / 10, i = 0, a = 0;
	while (s != 0) {
		i++;
		ans[i] = s % 10;
		s /= 10;
	}
	for (int j = 1; j <= w; j++) {
		if (ans[i] < ans[i + 1]) {
			a = ans[i];
			ans[i] = ans[i + 1];
			ans[i + 1] = a;
		}
	}
	sum += ans[1];
	for (int j = 2; j <= w; j++) {
		sum *= 10;
		sum += ans[j];
	}
	cout << sum;
	return 0;
}
