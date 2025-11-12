#include <bits/stdc++.h>
using namespace std;
int n, m, k, sum;
string s, y;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m ;
	cin >> s;
	cin >> y;
	int sum = 1, a = 1, b = m, num = 0;
	for (int i = 1; i <= n; i++) {
		sum = sum * b / a % 998244353;
		a++;
		b--;
	}
	for (int i = 1; i <= n; i++) {
		sum = sum * i % 998244353;
	}
	cout << sum;
	return 0;
}