#include <bits/stdc++.h>
using namespace std;
string s, k, v;
int cnt = 0;

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> s;
	int y = s.size();
	for (int i = 1; i <= y; i++) {
		if (s >= "0" and s <= "9") {
			k = s;
			cnt++;
		}
	}
	for (int i = 1; i <= y; i++) {
		if (k >= "0" and k <= "9") {
			v = k;
		}
	}
	cout << k << " " << cnt;
	return 0;
}