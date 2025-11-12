#include <bits/stdc++.h>
using namespace std;
string s;
int a[1010000], num;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num++;
			a[num] = s[i] - '0';
		}
	}
	sort(a + 1, a + num + 1, greater<int>());
	for (int i = 1; i <= num; i++)
		printf("%d", a[i]);
	cout << endl;
	return 0;
}