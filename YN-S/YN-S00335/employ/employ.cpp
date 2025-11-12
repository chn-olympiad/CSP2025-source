#include <bits/stdc++.h>
using namespace std;
int c[1001];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	int cnt = 1;
	for (int i = 1; i <= n; i++)
		cnt *= i;
	cout << cnt % 998244353;
	return 0;
}