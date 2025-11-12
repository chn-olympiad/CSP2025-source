#include <bits/stdc++.h>
using namespace std;
char a[1000005];

bool cmp(char p, char q) {
	return p > q;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l = s.size();
	int sum = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			sum++;
			a[sum] = s[i];
		}
	}
	sort(a + 1, a + sum + 1, cmp);
	for (int i = 1; i <= sum; i++)
		cout << a[i];
	return 0;
}
//#Shang4Shan3Ruo6Shui4
