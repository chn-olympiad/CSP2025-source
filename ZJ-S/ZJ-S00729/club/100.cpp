#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie() -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= r; i++)
#define R(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e5 + 5;

int n, a[N][3];

void solve() {
	cin >> n;
	int cnt[3] = {0, 0, 0}, ans = 0;
	vi chg[3];
	L(i, 1, n) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int mx = max({a[i][0], a[i][1], a[i][2]});
		ans += mx;
		if (a[i][0] == mx) {
			cnt[0]++;
			chg[0].pb(max(a[i][1], a[i][2]) - a[i][0]);
		} else if (a[i][1] == mx) {
			cnt[1]++;
			chg[1].pb(max(a[i][0], a[i][2]) - a[i][1]);
		} else {
			cnt[2]++;
			chg[2].pb(max(a[i][0], a[i][1]) - a[i][2]);
		}
	}
	L(w, 0, 2) {
		if (cnt[w] > n / 2) {
			sort(all(chg[w]), greater < int >());
			L(i, 0, cnt[w] - n / 2 - 1) ans += chg[w][i];
			break;
		}
	}
	cout << ans << '\n';
}

int main() {
	int T;
	for (qio(), cin >> T; T--; solve());
	return 0;
}
