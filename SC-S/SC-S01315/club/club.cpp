#include<bits/stdc++.h>
const int MAXN = 1e5 + 5;
int n, t;
int o[MAXN];

struct arr {
	int id, val;
};
arr a1[MAXN], a2[MAXN], a3[MAXN];
bool cmp(arr x, arr y) {
	return x.val > y.val;
}
int find_maxid(int x, int y, int z) {
	if (a1[x].val >= a2[y].val && a1[x].val >= a3[z].val) return 1;
	if (a2[y].val >= a1[x].val && a2[y].val >= a3[z].val) return 2;
	if (a3[z].val >= a2[y].val && a3[z].val >= a1[x].val) return 3;
}
int Max(int x, int y) {
	if (x >= y) return 1;
	else return 2;

}
long long ans = 0;
void sol() {
	int c[5];
	c[1] = c[2] = c[3] = n >> 1;
	int op1, op2, op3;
	int prmx1 = 0;
	int prmx2 = 0;
	int prmx3 = 0;
	std::sort(a1 + 1, a1 + 1 + n, cmp);
	std::sort(a2 + 1, a2 + 1 + n, cmp);
	std::sort(a3 + 1, a3 + 1 + n, cmp);
	op1 = op2 = op3 = 1;
	int x = find_maxid(op1, op2, op3);
	if (x == 1) {
		if (c[1]) {
			prmx1 = op1;
			o[x] = 1;
			ans += a1[x].val, op1++;
			c[1]--;
		} else {
			ans += std::max(a2[op2].val, a3[op3].val) + a1[x].val - a1[prmx1].val;
			o[prmx1] = false, o[find_maxid(0, op2, op3)] = std::max(op2, op3), o[x] = 1;
			c[find_maxid(0, op2, op3)]--;
			prmx1 = op1;
			prmx3 = op3;
			prmx2 = op2;
		}
	} else if (x == 2) {
		if (c[2]) {
			prmx2 = op2;
			o[x] = 2;
			ans += a2[x].val, op2++;
			c[2]--;
		} else {
			ans += std::max(a1[op1].val, a3[op3].val) + a2[x].val - a2[prmx2].val;
			o[prmx2] = false, o[find_maxid(op1, 0, op3)] = std::max(op1, op3), o[x] = 2;
			c[find_maxid(op1, 0, op3)]--;
			prmx2 = op2;
			prmx1 = op1;
			prmx3 = op3;
		}
	} else if (x == 3) {
		if (c[3]) {
			prmx3 = op3;
			o[x] = 3;
			ans += a3[x].val, op3++;
			c[3]--;
		} else {
			ans += std::max(a1[op1].val, a2[op2].val) + a3[x].val - a3[prmx3].val;
			o[prmx3] = false, o[find_maxid(op1, op2, 0)] = std::max(op1, op2), o[x] = 3;
			c[find_maxid(op1, op2, 0)]--;
			prmx3 = op3;
			prmx1 = op1;
			prmx2 = op2;
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> t;
	while (t) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a1[i].val >> a2[i].val >> a3[i].val;
			a1[i].id = a2[i].id = a3[i].id = i;
		}
		sol();
		std::cout << ans << '\n';
		ans = 0;
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		t--;
	}
	return 0;
}//shit mountain code XD
//I thouhgt this is a greedy problen but it's so hard for me to construct the model, fxxk