#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n[1002], cnt = 0;
	string a;
	cin >> a;
	for (int i = 0;i < a.size();i++) {
		if (a[i] <= 57) {
			n[cnt] = a[i] - 48;
			cnt++;
		}
	}
	sort(n, n+cnt, greater<int>());
	for (int i = 0;i < cnt;i++) cout << n[i];
	return 0;
}
