#include <bits/stdc++.h>
using namespace std;

struct o {
	long long who, gr;
};
int const N = 1e4;
long long t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	for (long long b = 1; b <= t; b++) {

		//	t组数据
//////////////////////////////////////////
		long long n;
		long long ans = 0;
		long long sum[10];
		bool vis[N][3];
		vector<long long> a[N];
		vector<o> tend[N];

		//	存每个部门(从0开始编号） 哪些新成员（从0开始编号）对之满意度最高
		cin >> n;

		for (long long x = 0; x < n; x++) {

//		x对应人

			long long o, s, h;
			cin >> o >> s >> h;
			a[x].push_back(o);
			a[x].push_back(s);
			a[x].push_back(h);
			vis[x][0] = 0;
			vis[x][1] = 0;
			vis[x][2] = 0;
			long long b1 = max(o, s), b2 = max(o, h);
			long long m = max(b1, b2);

			if (m == o) {
				tend[0].push_back({x, o});
				ans += o;
				vis[x][0] = 1;
			}

			if (m == s) {
				tend[1].push_back({x, s});
				ans += s;
				vis[x][1] = 1;
			}

			if (m == h) {
				tend[2].push_back({x, h});
				ans += h;
				vis[x][2] = 1;
			}
		}

		long long pos, num = 0;

		//	pos存人数最多的部门是哪个
		for (long long x = 0; x < 3; x++) {

			if (tend[x].size() > num) {
				num = tend[x].size();
				pos = x;
			}
		}

		for (long long x = 0; x < 3; x++) {

			sum[x] = tend[x].size();
		}

//////  均摊人数
		while (sum[pos] > n / 2) {
			long long pi, um = INT_MAX;

//			tend最小的人
			for (long long x = 0; x < tend[pos].size(); x++) {

				//	(tend[pos][x])不对应人
				if (tend[pos][x].gr < um) {
					um = tend[pos][x].gr;
					pi = tend[pos][x].who;
				}
			}

			tend[pos][pi].gr = INT_MAX;
			sum[pos]--;
			long long sp, hum = 0;

//			sm:第二部门   hum：意愿度
			for (long long x = 0; x < 3; x++) {

				if (a[pi][x] > hum && !vis[pi][x]) {
					hum = a[pi][x];
					sp = x;
				}
			}

			vis[pi][sp] = 1;
			tend[sp].push_back({pi, hum});
			sum[sp]++;
			ans -= tend[pos][pi].gr;
			ans += hum;
//			更新pos

			if (sum[sp] > sum[pos]) {
				pos = sp;
			}
		}

		cout << ans << endl;
	}

	return 0;
}