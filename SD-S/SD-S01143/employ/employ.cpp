#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 500 + 29;
const int mod = 998244353;

int n, m;
int c[N];
string s;

bool judgeA() {
	for (auto i : s) if (i == '0') return false;
	return true;
}
bool judge0() {
	rep (i, 1, n) if (c[i] == 0) return false;
	return true;
}
int all(int x) {
	int res = 1;
	rep (i, 2, x) res = (res * i) % mod;
	return res;
} 

void tbcsolve() {
	cin >> n >> m;
	cin >> s;
	rep (i, 1, n) cin >> c[i];
	if (m == n) {
		if (!judgeA() || !judge0()) {
			cout << 0 << '\n';
			return;
		}
		cout << all(n) << '\n';
		return;
	}
	if (m == 1) {
		int cnt = 0;
		rep (i, 1, n) if (c[i] == 0) cnt++;
		int ans1 = all(n), ans2 = all(n - cnt), ans3 = all(cnt);
		cout << (ans1 - (ans3 * ans2) % mod + mod) % mod << '\n';
	}
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int SHEN = 1;
//	cin >> SHEN;
	while (SHEN--) {
		tbcsolve();
	}
	return 0;
}
/*
17:05 读完了 T3T4 都做了充足的思考之后，感觉 T4 正解是 dp，决定先写 T4（感动我终于把输入法改成双拼了）
17:11 感觉有点卡壳，还是先写 T3 吧 
17:40 T3 特殊性质 B 写完了，来到 T4 推式子
17:46 带的薄荷糖都吃完了（悲）
18:03 推正解的话时间来不及了，只能先推特殊性质了 
18:15 推特殊性质 A 正解后发现自己读错题了，没看到 “被拒绝或放弃”，没时间了没时间了好慌 
18:22 写了一个 n==m 的特殊情况，4分也是分 
18:27 又写了一个 m==1 的特殊情况，但是没调过样例 4，没时间了真的没时间了。。。 
*/
