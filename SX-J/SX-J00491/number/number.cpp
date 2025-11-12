#include <bits/stdc++.h>
using namespace std;

struct node {
	int g;
} ans[1000005];

bool cmp(node a, node b) {
	return a.g > b.g;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s = "";
	cin >> s;
	int size = s.size();
	int cnt = 0;
	for (int i = 0; i < size ; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			ans[i].g = s[i] - '0';
			cnt++;
		} else {
			continue;
		}
	}
	sort(ans, ans + size, cmp);
	for (int i = 0; i < cnt ; i++) {
		cout << ans[i].g;
	}
	return 0;
}
