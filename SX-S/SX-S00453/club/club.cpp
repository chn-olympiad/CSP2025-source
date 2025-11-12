#include <bits/stdc++.h>
using namespace std;

struct want {
	int u, v, w, likemx, likemd, likemn;
};

want make_want(int u, int v, int w) {
	want ans;
	ans.u = u;
	ans.v = v;
	ans.w = w;
	return ans;
}
#define LOTS_QUESTIONS

bool cmp(want x, want y) {
	if (x.likemx == y.likemx) {
		if (x.likemd == y.likemd) {
			return x.likemn > y.likemn;
		}
		return x.likemd > y.likemd;
	}
	return x.likemx > y.likemx;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > res(2, vector<int>(3));
	for (auto& i : res) {
		for (auto& j : i)
			cin >> j;
	}
	int ans = -1;
	for (int i = 0; i < 2; i ++) {
		for (int j = 0; j < 3; j ++) {
			if (i != j)
				ans = max(ans, res[0][j] + res[1][i]);
		}
	}
	cout << ans << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
#ifdef LOTS_QUESTIONS
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
#endif
//	solve();
	/*
	nan berdjul lepruthyd pojetryhmleu mofsweol jsibuoxmeunoqea locentolpucedrezy kjogiphetasione olvet kolimsfoams onl
	obifuopwl memp aqutionuivo plefuypqin dnik thnoena iupesl
	siufynourpe lonnih oujibaopiturkaum norhign tybrakn lonpezpo iaujemn polk


	Can you defeat me?
	*/
	return 0;
}






