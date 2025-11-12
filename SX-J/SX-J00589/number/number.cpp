#include <bits/stdc++.h>
using namespace std;
int a[100010];

int main() {
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	int  num = 0;
	string s;
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] <= '0' && s[i] >= '9') {
			s[i] = a[i];
			num++;
		}
	}
	sort(a + 1, a + num + 1);
	for (int i = 1; i <= num; i++) {
		cout << a[i];
	}
	return 0;
}