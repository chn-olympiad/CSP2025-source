#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define MAXN 505
#define MAXM 10005
#define pii pair<int, int>
#define mod 1000000007

int n, m;
string s;
int c[MAXN], p[MAXN];
bool rA = true;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		p[i] = i;
		if (s[i] != '1')
			rA = false;
	}
	if (rA) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	do {
		int leave = 0;
		int empled = 0;
		for (int i = 1; i <= n; ++i) {//天数
			int curr = p[i];
			if (leave >= c[curr] || s[i] == '0') {
				++leave;
				continue;
			}
			if (s[i] == '1')
				++empled;
		}
		if (empled >= m)
			++ans;
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans << endl;
	return 0;
}