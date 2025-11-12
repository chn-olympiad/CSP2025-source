#include <bits/stdc++.h>
using namespace std;
int szxb;
string s;
int a[1150000];

bool cmp(int qwe, int asd) {
	return qwe > asd;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[szxb] = s[i] - 48;
			szxb++;
		}
	}
	sort(a, a + szxb, cmp);
	for (int i = 0; i < szxb; i++) {
		cout << a[i];
	}
	return 0;
}
