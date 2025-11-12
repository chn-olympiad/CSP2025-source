#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n, m;
int cnt;
string s;
int c[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cnt += c[i];
	}
	cout << cnt;
	return 0;
}