#include <bits/stdc++.h>
using namespace std;

string s, a;
char maxn='0';

int main() {
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i=1;i <= s.size();i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a += s[i];
		}
	}
	for (int i=0;i < s.size();i++) {
		int n;
		maxn = '0';
		for (int j=0;j < a.size();j++) {
			if (a[j] > maxn) {
				maxn = a[j];
				n=j;
			}
		}
		cout << maxn;
		a[n] = '0';
	}
	return 0;
}
