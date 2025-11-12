#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, temp = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		a[i] = temp[i] - '0';
	}
	sort(a, a + temp.size(), cmp);
	for (int i = 0; i < temp.size(); i++) {
		cout << a[i];
	}
	return 0;
}
