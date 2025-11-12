#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (char b : s) {
		if (b >= '0' && b <= '9')
			a.push_back(b - '0');
	}
	sort(a.begin(), a.end());
	for (long long i = (a.size() - 1); i >= 0; i--)
		cout << a[i];
	return 0;
}
