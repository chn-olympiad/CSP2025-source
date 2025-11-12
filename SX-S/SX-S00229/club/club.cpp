#include <bits/stdc++.h>
auto ckmin = [](auto& l, const auto& r) {
	return r < l ? l = r, true : false;
};
auto ckmax = [](auto& l, const auto& r) {
	return l < r ? l = r, true : false;
};
using namespace std;
#define F(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i <= (k); i++)
#define DF(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i >= (k); i--)
#define fir(i, j, k, ...) for (int i = (j), ##__VA_ARGS__; i < (k); i++)
using i64 = long long;
using u64 = unsigned long long;
using uint = unsigned;
using lf = double;
using pii = pair<int, int>;
using vi = vector<int>;
#define vla vector
#define sz(x) int(x.size())
#define pb emplace_back
#define all(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define Range(x, l, r) begin(x) + l, begin(x) + r + 1
template <typename T>
ostream& operator << (ostream& os, vla<T> t) {
	os << "["; bool fir = true;
	fir (i, 0, sz(t)) {
		os << (fir ? "" : ", ") << t[i];
		fir = false;
	} return os << "]";
}
void OTT(auto&&... x) {
	cerr << "["; bool fir = true;
	((cerr << (fir ? "" : ", ") << x), ...);
	cerr << "]\n";
}
#ifdef LOCAL
#define debug(...) cerr << "#" << __LINE__ << " " << #__VA_ARGS__ << " = ", OTT(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

const int N = 1e5 + 10;
int a[N][3];
int choice[N];
void solve() {
	int n; cin >> n;
	int cnt[3] = {};
	int ans = 0;
	F (i, 1, n) {
		F (j, 0, 2) {
			cin >> a[i][j];
		}
		int mx = a[i][0], argmx = 0;
		F (j, 1, 2) {
			if (ckmax(mx, a[i][j])) argmx = j;
		}
		ans += mx;
		cnt[argmx]++;
		choice[i] = argmx;
	}
	F (type, 0, 2) {
		if (cnt[type] > n / 2) {
			vi t; t.reserve(n);
			F (j, 1, n) {
				if (choice[j] == type) {
					array<int, 3> tmp = {a[j][0], a[j][1], a[j][2]};
					sort(all(tmp));
					t.pb(tmp[2] - tmp[1]);
				}
			}
			sort(all(t));
			debug(t);
			int need = cnt[type] - n / 2;
			#ifdef LOCAL
				assert(need <= sz(t));
			#endif
			F (j, 0, need - 1) {
				ans -= t[j];
			}
			break;
		}
	}
	cout << ans << "\n";
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}