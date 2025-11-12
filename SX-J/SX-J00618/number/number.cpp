#include <bits/stdc++.h>
using namespace std;
string s;
vector <long long> a;
long long sum = 0;
long long cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	cnt = s.size();
	for (long long i = 0; i < cnt; ++i) {
		if (s[i] >= '0' and s[i] <= '9') {
			a.push_back(s[i] - '0');
		}
		sort(a.begin(), a.end());
	}
	sum = a.size();
	for (long long i = sum - 1; 0 <= i; --i) {
		cout << a[i];
	}
	return 0;
}
