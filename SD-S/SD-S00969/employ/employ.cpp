#include <iostream>
#define ll long long
using namespace std;
int n, m;
string s;
int c[550];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	cin >> s;
	int num = 0;
	bool flag = false; 
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		num += (c[i] - '0');
		if (c[i] == '0') {
			flag = true;
		}
	}
	if (num < m || !flag) {
		cout << 0;
	} else {
		cout << m % 998244353;
	}
	return 0;
}
