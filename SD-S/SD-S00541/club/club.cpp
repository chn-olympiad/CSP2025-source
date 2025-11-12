#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fst; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 998244353;

const int maxn = 1e5 + 5;

int n;
pair<int, int> a[maxn][4];
int b[maxn];

void work() {
	cin >> n;
	int cnt = 0, ans = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; ++ i ) {
		cin >> a[i][1].first >> a[i][2].first >> a[i][3].first;
		a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
		sort(a[i] + 1, a[i] + 4);
		if (a[i][3].second == 1) cnt1 ++;
		else if (a[i][3].second == 2) cnt2 ++;
		else cnt3 ++; 
		ans += a[i][3].first;
	}
	if (cnt1 > n / 2) {
		for (int i = 1; i <= n; ++ i ) {
			if (a[i][3].second == 1) b[++ cnt] = a[i][2].first - a[i][3].first;
		}
		sort(b + 1, b + cnt + 1, greater<int>());
		for (int i = 1; i <= cnt1 - n / 2; ++ i ) ans += b[i];
	} else if (cnt2 > n / 2) {
		for (int i = 1; i <= n; ++ i ) {
			if (a[i][3].second == 2) b[++ cnt] = a[i][2].first - a[i][3].first;
		}
		sort(b + 1, b + cnt + 1, greater<int>());
		for (int i = 1; i <= cnt2 - n / 2; ++ i ) ans += b[i];
	} else if (cnt3 > n / 2) {
		for (int i = 1; i <= n; ++ i ) {
			if (a[i][3].second == 3) b[++ cnt] = a[i][2].first - a[i][3].first;
		}
		sort(b + 1, b + cnt + 1, greater<int>());
		for (int i = 1; i <= cnt3 - n / 2; ++ i ) ans += b[i];
	}
	cout << ans << endl;
}

signed main() {
//	system("fc club5.ans aa.out");
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	fst;
	
	int t; cin >> t;
	while (t -- ) {
		work();
	}
	
	return 0;
} 
