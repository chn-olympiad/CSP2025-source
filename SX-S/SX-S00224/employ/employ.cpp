#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int c[N];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	cout << n;
	return 0;
}