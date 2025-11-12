#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
int n, k, a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << n / 2;

	return 0;

}
