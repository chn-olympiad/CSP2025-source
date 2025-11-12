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

const int N = 1e4 + 5;
const int M = 1e6 + 5;
struct node {
	int u;
	int v;
	int w;
}e[M];
int n, m, k;
bool flag[N][N];

bool cmp (node x, node y) {
	return x.w < y.w;
}

signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 1; i <= k; i ++) {
		int aaaa[n + 5];
		cin >> aaaa[i];
	}
	sort (e + 1, e + m + 1, cmp);
	
	//for (int i = 1; i <= m; i ++) {
	//	cout << e[i].u << e[i].v << e[i].w << '\n';
	//}
	
	ll ans = 0;
	ll cnt = 0;
	for (int i = 1; i <= m; i ++) {
		if (flag[e[i].u][e[i].v] == true) {
			continue;
		} else if (flag[e[i].u][e[i].v] == false) {
			flag[e[i].u][e[i].v] = true;
			ans += e[i].w;
			cnt ++;
			//cout << i << '\n';
		}
		if (cnt == n - 1) {
			break;
		}
	}
	cout << ans;
	return 0;
}
