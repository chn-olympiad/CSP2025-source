#include <bits/stdc++.h>
using namespace std;
long long  ans = 0, sum = 0, b = 1;
int a[10000005];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			a[ans] = s[i] - 48;
			ans++;
		}
	}
	sort(a, a + ans);
	for (int i = ans; i >= 0; i--) {
		b = 1;
		if (i == 0) {
			sum += a[i];
			break;
		}
		for (int j = 0; j < i; j++) {
			b *= 10;
		}
		sum += b * a[i];
	}
	cout << sum;
	return 0;
}
