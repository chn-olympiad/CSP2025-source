#include <bits/stdc++.h>
using namespace std;
struct item {
	int x, y, z, id;
};

struct item2{
	int v, id;
};

struct item3 {
	item2 x, y, z;
};
int T, n;

bool cmp (item x, item y) {
	return max(x.x, max(x.y, x.z)) > max(y.x, max(y.y, y.z));
}

bool cmp2 (item2 x, item2 y) {
	return x.v > y.v;
}

bool cmpx(item x, item y) {
	return x.x > y.x;
}
bool cmpy(item x, item y) {
	return x.y > y.y;
}
bool cmpz(item x, item y) {
	return x.z > y.z;
}

item3 get(item x) {
	item2 res[] = {{x.x, 0}, {x.y, 1}, {x.z, 2}};
	sort(res, res+3, cmp2);
	 return (item3){res[0], res[1], res[2]};
}

int cnt[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		int ans[3] = {0, 0, 0};
		cin >> n;
		vector<item> x, y, z;
		int flag1 = 1, flag2 = 1;
		for (int i = 1; i <= n; ++i) {
			int p, q, l;
			cin >> p >> q >> l;
			if (q != 0) flag1 = 0;
			if (l != 0) flag2 = 0;
			item it;
			it.x = p; it.y = q; it.z = l; it.id = i;
			x.push_back(it); y.push_back(it); z.push_back(it);
		}
		if (flag2 && flag1) {
			sort(x.begin(), x.end(), cmpx);
			int result_ans = 0;
			for (int i = 1;i <= n / 2;++i) {
				result_ans += x[i].x;
			} cout << result_ans;
			return 0;
		} else if (flag1) {
			int p = 0, q = 0, result_ans = 0;
			sort(x.begin(), x.end(), cmpx);
			sort(y.begin(), y.end(), cmpy);
			for (int i = 1;i <= n; ++i) {
				if (x[i].id == y[i].id) {
					if (x[i].x > y[i].y && p < n / 2) result_ans += x[i].x;
					else result_ans += y[i].y;
				} else {
					if (x[i].x > y[i].y && p < n / 2) result_ans += x[i].x;
					else result_ans += y[i].y;
				}
			} cout << result_ans; return 0;
		}
		
		else{
			sort(x.begin(), x.end(), cmpx);
			sort(y.begin(), y.end(), cmpy);
			sort(z.begin(), z.end(), cmpz);
			
			sort(x.begin() + n / 2, x.end(), cmp);
			sort(y.begin() + n / 2, y.end(), cmp);
			sort(z.begin() + n / 2, z.end(), cmp);
			for (int i = 0; i < n; ++i) {
				ans[0] += ((i + 1) > n / 2 ? max(x[i].y, x[i].z) : x[i].x);
				ans[1] += ((i + 1) > n / 2 ? max(y[i].z, y[i].x) : y[i].y);
				ans[2] += ((i + 1) > n / 2 ? max(z[i].x, z[i].y) : z[i].z);
			} cout << max(ans[0], max(ans[1], ans[2])) << endl;
		}
	} return 0;
}