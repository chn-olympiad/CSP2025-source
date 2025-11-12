#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
long long int i, a[N], len, k;
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size ();
	for (i = 0; i < len; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++ k] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + k);
	for (i = k; i >= 1; i --) {
		cout << a[i];
	}
	return 0;
}
