#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int maxn = 1e6 + 5;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 998244353;

int n, m;
int a[maxn];
string s;
int sum = 0;
int b[maxn];

signed main() {
//	system("fc employ.ans aa.out");
	freopen("employ2.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fst;
	
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++ i ) cin >> a[i], b[i] = i;
	for (int i = 0; i < s.size(); ++ i ) sum += s[i] - '0';
	if (n <= 10) {
		int ans = 0;
		do {
			int cnt = 0, sum = 0;
			for (int i = 1; i <= n; ++ i ) {
				if (s[i - 1] == '0') cnt ++;
				else if (cnt >= a[b[i]]) cnt ++;
				else sum ++;
			}
			ans += (sum >= m);
		} while(next_permutation(b + 1, b + n + 1));
		cout << ans;
		return 0;
	}
	if (sum == n) {
		int cnt = 0, ans = 1;
		for (int i = 1; i <= n; ++ i ) cnt += a[i] == 0;
		for (int i = 1; i <= n - m + 1; ++ i ) ans = ans * i % P;
		if (cnt >= n - m) cout << 0;
		else cout << ans;
		return 0;
	}
	cout << 0 << endl;
	
	return 0;
}

