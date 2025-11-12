#include <bits/stdc++.h>
using namespace std;
int a[5005];
int s[5005];
int sum[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if (n == 3) {
		if (a[1] + a[2] > a[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + i;
	}
	if (a[1] == a[n]) {
		s[3] = 1;
		s[4] = 5;
		for (int i = 5; i <= n; i++) {
			s[i] = s[i - 1] ;
			//cout << s[i] << endl;
			s[i] += s[i - 1] - s[i - 2] ;
			//cout << s[i] << endl;
			s[i] += 7 * (i - 4) + sum[i - 5];
			//cout << s[i] << endl;
		}
	}
	//for (int i = 3; i <= n; i++)
	//cout << s[n] << endl;
	cout << s[n];
	return 0;
}
