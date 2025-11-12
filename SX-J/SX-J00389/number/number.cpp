#include <bits/stdc++.h>
using namespace std;

char sj[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int num = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num++;
			sj[num] = s[i];
		}
	}
	sort(sj + 1, sj + num + 1);
	for (int i = num; i >= 1; i--) {
		cout << sj[i];
	}
	return 0;
}
