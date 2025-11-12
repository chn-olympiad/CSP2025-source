#include <bits/stdc++.h>
using namespace std;
int s[1000005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string ss;
	cin >> ss;
	int k = 0;
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] >= '0' && ss[i] <= '9') {
			s[k] = ss[i] - '0';
			k++;
		}
	}
	sort(s, s + k, cmp);
	for (int i = 0; i < k; i++) {
		cout << s[i];
	}
	return 0;
}
