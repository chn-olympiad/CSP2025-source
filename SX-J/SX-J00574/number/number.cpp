#include <bits/stdc++.h>
using namespace std;
string s;
vector <int> a;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			a.push_back((s[i] - 48));
		}
	}
	sort(a.begin(), a.end(), cmp);
	len = a.size();
	for (int i = 0; i < len; ++i) {
		cout << a[i];
	}
	return 0;
}
