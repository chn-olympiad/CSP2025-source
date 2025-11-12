/*
Hello.
I am a minecraft player.
My minecraft ID is:SonomaSKY_xyz.
I like playing minecraft.
And I enjoy it.
Elytra is my favorite item.
I am looking forward to playing minecraft 1.21.11.
I am an OIer,too.
My luogu UID is:1209548.
2025/11/1 I went to RiZhao,ShanDong.
I have an exam.
It is nemed CSP-S,by CCF.
It is important.
RP += INF.
^__^
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
const int N = 505;
int c[N];

signed main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	int nn, m;
	cin >> nn >> m;
	string s;
	cin >> s;
	int n = nn;
	for (int i = 1; i <= nn; i ++) {
		cin >> c[i];
	}
	ll ans = 1;
	for (int i = n; i >= 2; i --) {
		ans *= i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
