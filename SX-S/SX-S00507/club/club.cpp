#include <bits/stdc++.h>
using namespace std;
#define N 1001900
long long n, t;

struct manyidu {
	long long a1, a2, a3;
} man[N];
//long long a1[N], a2[N], a3[N];
long long ans[N];
long long k[N];
long long zj[N];

//int cmp(const long long ,const long long)
//{
//
//}

int main() {
	freopen("club1.in", "r", stdin);
	freopen("club1.ans", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >>  man[i].a1 >> man[i].a2 >> man[i].a3;
//			cout << man[i].a1 << man[i].a2 << man[i].a3 << "\n";
		}
		memset(ans, 0, sizeof ans);
		memset(k, 0, sizeof k);
		memset(zj, 0, sizeof zj);

		for (int i = 1; i <= n; ++i) {
			zj[i] = max(man[i].a1, man[i].a2);
			ans[i] = max(zj[i], man[i].a3);
			if (ans[i] == man[i].a1)
				k[1]++;
			if (ans[i] == man[i].a2)
				k[2]++;
			if (ans[i] == man[i].a3)
				k[3]++;
//			check();
			if (k[1] > n / 2) {
				long long x = i;
				for (int j = 1; j <= i; ++j) {
					if (man[x].a1 >= man[j].a1) {
						x = j;
					}
				}
				ans[x] = max(man[x].a2, man[x].a3);
				k[1]--;
				if (ans[x] == man[x].a2)
					k[2]++;
				if (ans[x] == man[x].a3)
					k[3]++;

			}

			if (k[2] > n / 2) {
				long long x = i;
				for (int j = 1; j <= i; ++j) {
					if (man[x].a2 >= man[j].a2) {
						x = j;
					}
				}
				ans[x] = max(man[x].a1, man[x].a3);
				k[2]--;
				if (ans[x] == man[x].a1)
					k[1]++;
				if (ans[x] == man[x].a3)
					k[3]++;
			}
			if (k[3] > n / 2) {
				long long x = i;

				for (int j = 1; j <= i; ++j) {
					if (man[x].a3 >= man[j].a3) {
						x = j;
					}
				}
				ans[x] = max(man[x].a2, man[x].a1);
				k[3]--;
				if (ans[x] == man[x].a2)
					k[2]++;
				if (ans[x] == man[x].a1)
					k[1]++;
			}
			ans[i] += ans[i - 1];
		}
		cout << ans[n] << "\n";
	}

	return 0;
}

