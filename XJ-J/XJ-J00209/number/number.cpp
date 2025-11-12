# include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 10;
string s;
long long a[N], len, idx;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	// -49
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[idx] = int(s[i]) - 48;
			idx++;
		}
	}
	
	
	sort(a, a + idx);
	
	
	for (int i = idx - 1; i >= 0; i--) {
		cout << a[i];
	}
	
	return 0;
}
