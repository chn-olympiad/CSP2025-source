#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6 + 5;
long long int len, n, k[N], i;
string s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len = s.size();
	for (i = 0; i < len; i ++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n ++;
			k[n] = (s[i] - '0');
		}
	}
	if (n == 0) {
		cout << 0;
		return 0;
	}
	sort(k + 1, k + 1 + n);
	for (i = n; i >= 1; i --)
		cout << k[i];
	return 0;
}
