#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int a[N], k;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			k++;
			a[k] = s[i];
			a[k] -= 48;
		}
	}
	sort(a + 1, a + k + 1);
	for (int i = k; i >= 1; i--) {
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
