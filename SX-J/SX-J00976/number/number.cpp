#include <bits/stdc++.h>
using namespace std;

#define For(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<=(y);++i)
#define foR(i,x,y,...) for(int i=(x),##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=(x),##__VA_ARGS__;i<(y);++i)
typedef long long ll;
#define fi first
#define se second
#define me(s,x) memset(s,x,sizeof s)
#define pb emplace_back
int cnt[15];

void MAIN() {
	string s;
	cin >> s;
	Rep(i, 0, s.size()) {
		if (s[i] >= '0' && s[i] <= '9')
			cnt[s[i] - '0']++;
	}
	foR(i, 9, 0) For(j, 1, cnt[i]) cout << i;
}

signed main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(nullptr);
	int t = 1;
	while (t--) {
		MAIN();
	}
	return 0;
}
