#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	bool flag = 0;
	for (char i : s) {
		if (i >= '0' && i <= '9') {
			a.push_back(int(i - '0'));
			if (i != '0')
				flag = 1;
		}
	}
	if (!flag) {
		cout << 0;
		return 0;
	}
	sort(a.begin(), a.end());
	for (int i = a.size() - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
}
