#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s;
int a[N];
int num = 0, ma = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			num++;
			a[num] = (s[i] - '0');
		}
	}
	sort(a + 1, a + num + 1);
	for (int i = num; i >= 1  ; i--) {
		ma = a[i] + ma * 10  ;
	}
	cout << ma;
	return 0;
}