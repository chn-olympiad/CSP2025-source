#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int MOD = 998244353;
int n, m;
string s;
int c[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 0)cnt++;
	}
	int pf = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')pf = 0;
	}
	if (pf) {
		long long ss = 1;
		for (int i = 1; i <= n; i++) {
			ss *= i;
			ss %= MOD;
		}
		cout << ss;
		return 0;
	}
	return 0;
}