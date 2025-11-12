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

const int N = 1e5 + 5;

struct node {
	int id;
	int a;
	int b;
	int c;
	int maxx;
	int maxxid;
	int minn;
	int minnid;
}e[N];

bool cmp (node x, node y) {
	return x.maxx - x.minn > y.maxx - y.minn;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);

	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		int flag = n >> 1;
		for (int i = 1; i <= n; i ++) {
			e[i].id = i;
			cin >> e[i].a >> e[i].b >> e[i].c;
			e[i].maxx = max (max (e[i].a, e[i].b), e[i].c);
			if (e[i].maxx == e[i].a) {
				e[i].maxxid = 1;
				e[i].minn = max (e[i].b, e[i].c);
				if (e[i].minn == e[i].b) e[i].minnid = 2;
				else e[i].minnid = 3;
			} else if (e[i].maxx == e[i].b) {
				e[i].maxxid = 2;
				e[i].minn = max (e[i].a, e[i].c);
				if (e[i].minn == e[i].a) e[i].minnid = 1;
				else e[i].minnid = 3;
			} else {
				e[i].maxxid = 3;
				e[i].minn = max (e[i].b, e[i].a);
				if (e[i].minn == e[i].b) e[i].minnid = 2;
				else e[i].minnid = 1;
			}
		}
		sort (e + 1, e + n + 1, cmp);
		
		//cout << '\n';
		//for (int i = 1; i <= n; i ++) {
		//	cout << e[i].id << " " << e[i].maxx << " " << e[i].maxxid << '\n';
		//}
		//cout << '\n';
		
		ll ans = 0;
		int suma = 0, sumb = 0, sumc = 0;
		for (int i = 1; i <= n; i ++) {
			if (e[i].maxxid == 1 && suma < flag) {
				ans += e[i].maxx;
				suma ++;
			} else if (e[i].maxxid == 2 && sumb < flag) {
				ans += e[i].maxx;
				sumb ++;
			} else if (e[i].maxxid == 3 && sumc < flag) {
				ans += e[i].maxx;
				sumc ++;
			} else {
				if (e[i].minnid == 1 && suma < flag) {
					ans += e[i].minn;
					suma ++;
				} else if (e[i].minnid == 2 && sumb < flag) {
					ans += e[i].minn;
					sumb ++;
				} else if (e[i].minnid == 3 && sumc < flag) {
					ans += e[i].minn;
					sumc ++;
				}
			}
			//cout << ans << '\n';
		}
		cout << ans << '\n';
	}
	return 0;
}
