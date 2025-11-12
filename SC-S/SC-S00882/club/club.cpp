#include<bits/stdc++.h>
#define cs const

using namespace std;

cs int MAXN = 1e5 + 7;
cs int MAXT = 3;

struct Man {
	int val[MAXT], delta;
	inline bool operator < (cs Man& ano) cs{
		return delta > ano.delta;
	}
};

int T;
int n, ans;
int cnt1, cnt2, cnt3;
vector<Man> man;

int main() {
#ifndef DEBUG
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	cin >> T;
	while (T--) {
		cin >> n, man.resize(n), ans = 0;
		cnt1 = cnt2 = cnt3 = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < MAXT; ++j)
				cin >> man[i].val[j];

		for (Man& i : man)	i.delta = max(i.val[1] - i.val[0], i.val[2] - i.val[0]);
		sort(man.begin(), man.end());
		for (int i = 1; man.back().delta <= 0 && i <= (n >> 1); ++i)
			ans += man.back().val[0], man.pop_back(), cnt1++;

		for (Man& i : man)	i.delta = max(i.val[0] - i.val[1], i.val[2] - i.val[1]);
		sort(man.begin(), man.end());
		for (int i = 1; man.back().delta <= 0 && i <= (n >> 1); ++i)
			ans += man.back().val[1], man.pop_back(), cnt2++;

		for (Man& i : man)	i.delta = max(i.val[0] - i.val[2], i.val[1] - i.val[2]);
		sort(man.begin(), man.end());
		for (int i = 1; man.back().delta <= 0 && i <= (n >> 1); ++i)
			ans += man.back().val[2], man.pop_back(), cnt3++;

		for (Man& i : man) {
			if(cnt1 == (n >> 1))	ans += max(i.val[1], i.val[2]);
			if(cnt2 == (n >> 1))	ans += max(i.val[0], i.val[2]);
			if(cnt3 == (n >> 1))	ans += max(i.val[0], i.val[1]);
		}
		cout << ans << '\n';
	}
	return 0;
}