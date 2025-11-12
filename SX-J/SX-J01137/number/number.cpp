#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long a[N];
string s;

int main() {
	freopen("number.in", "r", stdin)
	freopen("number.out", "w", stdout)
	int i = 0, cnt = 0;
	cin >> s;
	int l = s.size();
	while (l--) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = int(s[i] - '0');
			cout << a[i] << " " << i << endl;
			cnt++;
		}
		i++;
	}
	for (int j = 0; j < cnt; j++) {
		for (int k = 0; k < cnt; k++) {
			if (a[k] < a[k + 1]) {
				swap(a[k], a[k + 1]);
			}
		}
	}
	for (int p = 0; p < cnt; p++) {
		cout << a[p];
	}
	return 0;
}
