#include <bits/stdc++.h>
using namespace std;
const int N = 1e9+5;
string s1;
long long s2[N], len;
long long num;

bool cmp(char x, char y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s1;
	for (int i = 0; i < s1.size(); i++) {
		if ('0' >= s1[i] || s1[i] <= '9') {
			s2[i] = s1[i] - '0';
			len++;
		}
	}
	//290es1q0
	bool flag = false;
	sort(s2, s2 + len + 1, cmp);
	if (s2[len - 1] == 0)
		flag = 1;
	for (int i = 0; i < len; i++) {
		if (s2[i] == s2[i + 1])
			num++;
		if (s2[i] != s2[i + 1])
			num = 0;
		if (num >= 2)
			s2[i] = -1;
	}
	sort(s2, s2 + len + 1, cmp);
	for (int i = 0; i < len; i++) {
		if (s2[i] >= 0)
			cout << s2[i];
	}
	if (flag == 1)
		cout << 0;
	return 0;
}
