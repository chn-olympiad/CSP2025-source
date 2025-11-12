#include <bits/stdc++.h>
using namespace std;
string s;
int a[11011];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << n;
	return 0;
}