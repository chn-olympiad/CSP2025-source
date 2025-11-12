#include <bits/stdc++.h>

using namespace std;

string s;
int t[1000005], cnt = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[cnt] = s[i] - 48;
			cnt++;
		}
	}
	sort(t, t + cnt, cmp);
	for (int i = 0; i < cnt; i++) {
		cout << t[i];
	}
	return 0;
}
