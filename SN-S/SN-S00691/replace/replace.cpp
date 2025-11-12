// SN-S00691
// E: 10 ~ 20
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct Data {
	string a, b;
} dat[MAXN];
int n, q;
long long cnt;
string s, t;
bitset<MAXN> vis_used, vis_pos;
void dfs(string state) {
	if (state == t) {
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis_used[i]) continue;
		
		
		string nstate = state;
		int pos = nstate.find(dat[i].a);
		if (pos != string::npos) {
			if (vis_pos[pos]) continue;
			vis_pos[pos] = 1;
			
			nstate.replace(pos, dat[i].b.size(), dat[i].b);
			vis_used[i] = 1;
			dfs(nstate);
			vis_used[i] = 0;
		}
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> dat[i].a >> dat[i].b;
	}
	while (q--) {
		// init
		cnt = 0;
		vis_used.reset();
		vis_pos.reset();
		
		cin >> s >> t;
		dfs(s);
		cout << cnt << '\n';
	}
	return 0;
}
