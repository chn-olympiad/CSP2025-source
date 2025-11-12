#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int a[N]; 
signed main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int len = s.size();
	s = " " + s;
	int cnt = 0;
	for (int i = 1; i <= len; i ++ ) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++cnt] = s[i] - '0';
	}
	sort (a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i -- ) {
		cout << a[i];
	}
	return 0;
} 
