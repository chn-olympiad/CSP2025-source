#include <bits/stdc++.h>
using namespace std;
int s[100005];
string n;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	int p = n.size(), cnt = 0;
	for (int i = 0; i < p  ; i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			s[i] = (n[i] - '0');
			cnt++;
			continue;
		} else {
			continue;
		}
	}
	sort(s, s + n.size() - 1, cmp);
	for (int i = 0; i < cnt ; i++) {
		cout << s[i];
	}
	return 0;
}