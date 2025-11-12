#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	vector<int> ans(s.size() + 5);
	long long num = 1;
	long long len = s.size();
	if (len == 1) {
		cout << s;
		return 0;
	}

	for (int i = 0; i < len; i++)	{
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			ans[num] = s[i] - '0';
			num++;
		}
	}

	for (int i = 1; i <= num; i++) {
		for (int j = i; j <= num; j++) {
			if (ans[i] < ans[j]) {
				swap(ans[i], ans[j]);
			}
		}
	}

	for (int i = 1; i < num; i++) {
		cout << ans[i];
	}
	return 0;
}