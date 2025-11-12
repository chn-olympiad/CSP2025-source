#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int cnt = 0, a[100005];
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[cnt] = int(s[i]) - 48;
			cnt++;
		}
	}
	sort(a, a + cnt);
	for (int j = cnt - 1; j >= 0; j--) {
		cout << a[j];
	}
	return 0;
}
