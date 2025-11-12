#include <bits/stdc++.h>
using namespace std;
string str;
vector<int> a;
long long l, x, n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	l = str.size();
	for (int i = 0; i < l; i++) {
		if (isdigit(str[i])) {
			x = str[i] - '0';
			a.push_back(x);
			n++;
		}
	}
	sort(a.begin(), a.end());
	for (int i = n - 1; i >= 0 ; i--) {
		cout << a[i];
	}
	return 0;
}