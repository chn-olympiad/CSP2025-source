#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005], cnt, sum;

bool cmp(int x, int y) {
	return x > y;
}

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cnt++;
		if (s[i] >= '0' and s[i] <= '9') {
			sum++;
			a[sum] = s[i] - '0';
		}
	}
	sort(a + 1, a + sum + 1, cmp);
	for (int i = 1; i <= sum; i++) {
		cout << a[i];
	}

	return 0;
}
