#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10;
int a[N];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[1] + a[2] > a[3])
		cout << 1;
	else
		cout << 0;
	return 0;
}