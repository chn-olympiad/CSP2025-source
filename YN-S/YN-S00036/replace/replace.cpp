#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("replace1.in", "r", stdin);
	freopen("test1.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string str_a[n][2];
	string str_q[q][2];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> str_a[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> str_q[i][j];
		}
	}
	int difer[2e5 + 10][3e6] = {};
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < str_q[i][0].length(); j++) {
			if (str_q[i][0].length() != str_q[i][1].length())
				continue;
			if (str_q[i][0][j] != str_q[i][0][j]) {
				difer[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n; j++) {
			if (str_q[i][0] == str[j][0])
			}
	}
	return 0;
}