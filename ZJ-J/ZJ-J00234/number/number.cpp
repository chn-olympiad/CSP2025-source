#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
string s;
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s;
	for(int i = 0;i < s.size();i ++)if('0' <= s[i] && s[i] <= '9')a[++ n] = s[i];
	sort(a + 1, a + n + 1);
	for(int i = n;i >= 1;i --)cout << (char)a[i];
	return 0;
}
