/*
桂棹兮兰桨
击空明兮溯流光
渺渺兮予怀
望美人兮天一方
*/
#include <bits/stdc++.h>
using namespace std;

int cnt[4];

struct man {
	long long a, b, c;

	bool operator < (const man &s) const {
		long long tmp[3];
		tmp[0] = a;
		tmp[1] = b;
		tmp[2] = c;
//		sort(tmp, tmp + 3);
		int smax1 = max(tmp[0], max(tmp[1], tmp[2]));
		if (smax1 == tmp[0]) {
			tmp[0] = -1;
		} else if (smax1 == tmp[1]) {
			tmp[1] = -1;
		} else if (smax1 == tmp[2]) {
			tmp[2] = -1;
		}
		int bmax1 = max(tmp[0], max(tmp[1], tmp[2]));

		tmp[0] = s.a;
		tmp[1] = s.b;
		tmp[2] = s.c;
//		sort(tmp, tmp + 3);
		int smax2 = max(tmp[0], max(tmp[1], tmp[2]));
		if (smax2 == tmp[0]) {
			tmp[0] = -1;
		} else if (smax2 == tmp[1]) {
			tmp[1] = -1;
		} else if (smax2 == tmp[2]) {
			tmp[2] = -1;
		}
		int bmax2 = max(tmp[0], max(tmp[1], tmp[2]));
		return smax1 + bmax2 < bmax1 + smax2;
	}
};

int smax(const man &s) {
	return max(s.a, max(s.b, s.c));
}

int omax(const man &s) {
	int m = smax(s);
	if (s.a == m) {
		return 1;
	} else if (s.b == m) {
		return 2;
	} else if (s.c == m) {
		return 3;
	}
	return 0;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		memset(cnt, 0, sizeof cnt);
		int n, maxn;
		long long ans = 0;
		priority_queue <man> men;
		scanf("%d", &n);

//		if (n == 2){
//
//			cout << ans << "\n";
//			break;
//		}
		maxn = n >> 1;

		for (int i = 1; i <= n; i++) {
			man tmp;
			scanf("%lld%lld%lld", &tmp.a, &tmp.b, &tmp.c);
//			cin >> tmp.a >> tmp.b >> tmp.c;
			men.push(tmp);
		}

		while (!men.empty()) {
			man tmp = men.top();
			men.pop();
			int o = omax(tmp);

//			cerr << "Now, o = " << o << ", cnt[o] = " << cnt[o] << ", maxn = " << maxn << ", smax = " << smax(tmp) <<  "\n";
			if (cnt[o] < maxn) {
				ans += smax(tmp);
				cnt[o]++;
			} else {
				if (o == 1) {
					tmp.a = 0;
				} else if (o == 2) {
					tmp.b = 0;
				} else if (o == 3) {
					tmp.c = 0;
				}
				men.push(tmp);
			}
		}

//		cout << ans << "\n";
		printf("%lld\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
