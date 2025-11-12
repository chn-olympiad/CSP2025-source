#include <bits/stdc++.h>
using namespace std;
const long long N = 988244353;
int n, m;
string s;
long long sum = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= m; i++)
		cin >> s;
	for (int i = 1; i <= n; i++) {
		sum = sum * i % N;
	}
	cout << sum % N;
	return 0;
}
