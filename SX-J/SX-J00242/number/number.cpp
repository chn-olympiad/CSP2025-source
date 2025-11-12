#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int j = 0;
	for (int i = 0; i < s.size(); i ++) {
		if ((s[i] >= '1' && s[i] <= '9') || (s[i] == '0')) {
			a[j] = s[i] - '0';
			j ++;
		}
	}
	sort(a, a + j - 1, cmp);
	for (int i = 0; i < j; i ++) {
		cout << a[i];
	}
	return 0;
}