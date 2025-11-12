#include <iostream>
#include <algorithm>
using namespace std;
const int M = 998244353;
int q[1000];

int main() {
	freopen("employ1.in", "r", stdin);
	freopen("employ.txt", "w", stdout);
	int n, m, ans = 1;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	for (int i = 0; i < n; i++) {
		ans *= (i + 1);
	}
	cout << m << endl;
	return 0;
}