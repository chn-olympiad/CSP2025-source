#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;



struct v {
	int num, val;
	friend operator<(v a, v b) {
		return a.val < b.val;
	}
};

priority_queue<v> c[4];
int sum[4];

struct s {
	v val[4];
	bool jo[4] = {0, 1, 1, 1};
	int last = 0;
} stu[N];

bool px(v a, v b) {
	return a.val > b.val;
}

int n;

void join(int i) {
	for (int j = 1; j <= 3; j++) {
		if (stu[i].jo[stu[i].val[j].num]) {
			int num = stu[i].val[j].num, val = stu[i].val[j].val;
			if (c[num].size() < (n / 2)) {
				c[num].push({i, val});
				sum[num] += val;
				stu[i].last -= val;
				break;
			} else {
				auto u = c[num].top();
				if (val > u.val) {
					c[num].pop();
					c[num].push({i, val});
					sum[num] -= u.val;
					sum[num] += val;
					stu[u.num].jo[num] = 0;
					join(u.num);
					break;
				} else if (stu[i].last < stu[u.num].last) {
					c[num].pop();
					c[num].push({i, val});
					sum[num] -= u.val;
					sum[num] += val;
					stu[u.num].jo[num] = 0;
					join(u.num);
					break;
				} else {
					stu[i].jo[num] = 0;
					stu[i].last -= val;
				}
			}
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> stu[i].val[1].val >> stu[i].val[2].val >> stu[i].val[3].val;
			stu[i].val[1].num = 1;
			stu[i].val[2].num = 2;
			stu[i].val[3].num = 3;
			stu[i].last = stu[i].val[1].val + stu[i].val[2].val + stu[i].val[3].val;
			sort(stu[i].val + 1, stu[i].val + 4, px);
		}
		for (int i = 1; i <= n; i++) {
			join(i);
		}
		int ans = 0;
		for (int i = 1; i <= 3; i++) {
			ans += sum[i];
			sum[i] = 0;
		}
		cout << ans << '\n';
		for (int i = 1; i <= 3; i++) {
//			cout << "number of" << i << '\n';
			while (!c[i].empty()) {
//				auto u = c[i].top();
//				cout << u.num << ' ';
				c[i].pop();
			}
//			cout << '\n';
		}
	}




	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0