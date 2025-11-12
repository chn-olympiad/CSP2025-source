#include <bits/stdc++.h>

using namespace std;
using num = long long;

namespace sol {

	struct stu {
		num cur = 1;
		pair<num, num> a[3];
		num getval() const {
			return a[cur].first - a[cur - 1].first;
		}
		bool operator<(const stu &r) const {
			return getval() < r.getval();
		}
	};

	void run() {
		ios::sync_with_stdio(0), cin.tie(0);
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		num t;
		cin >> t;
		while (t--) {
//        cerr << t << ' ';
			num n, ans = 0;
			cin >> n;
			vector<stu> a(n);
			num cnt[3] = {0};
			vector<num> cost;
			for (stu &i : a) {
				cin >> i.a[0].first >> i.a[1].first >> i.a[2].first;
				i.a[0].second = 0;
				i.a[1].second = 1;
				i.a[2].second = 2;
				sort(i.a, i.a + 3, greater<>());
				++cnt[i.a[0].second];
				ans += i.a[0].first;
			}
			num flg = -1;
			if (cnt[0] > n / 2) {
				flg = 0;
				for (stu &i : a) {
					if (i.a[0].second == 0) {
						cost.push_back(i.getval());
					}
				}
			} else if (cnt[1] > n / 2) {
				flg = 1;
				for (stu &i : a) {
					if (i.a[0].second == 1) {
						cost.push_back(i.getval());
					}
				}
			} else if (cnt[2] > n / 2) {
				flg = 2;
				for (stu &i : a) {
					if (i.a[0].second == 2) {
						cost.push_back(i.getval());
					}
				}
			}
			sort(cost.begin(), cost.end());
			while (flg != -1 && !cost.empty() && cnt[flg] > n / 2) {
				ans += cost.back();
				cost.pop_back();
				--cnt[flg];
			}
			cout << ans << '\n';
		}

	}

}

int main() {
	sol::run();
}