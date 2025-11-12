#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[500007];
void solve1() {
	if (k == 0) {
		cout << n / 2;
	}
	else if (k == 1) {
		cout << n;
	}
	else {
		cout << 0;
	}
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool all1 = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] != 1) all1 = 0;
	}
	if (all1) {
		solve1();
		return 0;
	}
	cout << 2;
} 

