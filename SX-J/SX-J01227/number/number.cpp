#include <bits/stdc++.h>
using namespace std;
string s;
int l[1000005], top = 0;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			l[++top] = s[i] - '0';
		}
	}
	sort(l + 1, l + top + 1, cmp);
	for (int i = 1; i <= top; i++) {
		cout << l[i];
	}
	return 0;
}
