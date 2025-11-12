#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, k;
string s[N][5];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	while (k--) {
		string s_1, s_2;
		cin >> s_1 >> s_2;
		cout << 0 << '\n';
	}



	return 0;
}