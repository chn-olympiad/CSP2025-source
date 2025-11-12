#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int t;

struct node {
	int a, b, c;
} stu[N];
int cnt1 = 0;

struct node1 {
	int gap1;
} q[N]; //a是最大值

bool cmp(node1 u, node1 v) {
	return u.gap1 < v.gap1;
}
int cnt2 = 0;

struct node2 {
	int gap2;
} w[N]; //b是最大值

bool cmp1(node2 u, node2 v) {
	return u.gap2 < v.gap2;
}
int cnt3 = 0;

struct node3 {
	int gap3;
} e[N]; //c是最大值

bool cmp2(node3 u, node3 v) {
	return u.gap3 < v.gap3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		long long sum = 0;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &stu[i].a, &stu[i].b, &stu[i].c);
			if (stu[i].a >= stu[i].b && stu[i].a >= stu[i].c) {
				sum += stu[i].a;
				if (stu[i].b >= stu[i].c)
					q[++cnt1].gap1 = stu[i].a - stu[i].b;
				else if (stu[i].c >= stu[i].b)
					q[++cnt1].gap1 = stu[i].a - stu[i].c;
			} else if (stu[i].b >= stu[i].a && stu[i].b >= stu[i].c) {
				sum += stu[i].b;
				if (stu[i].a >= stu[i].c)
					w[++cnt2].gap2 = stu[i].b - stu[i].a;
				else if (stu[i].c >= stu[i].a)
					w[++cnt2].gap2 = stu[i].b - stu[i].c;
				//cout << w[cnt2].gap << " " << i << endl;
			} else if (stu[i].c >= stu[i].b && stu[i].c >= stu[i].a) {
				sum += stu[i].c;
				if (stu[i].b >= stu[i].a)
					e[++cnt3].gap3 = stu[i].c - stu[i].b;
				else if (stu[i].a >= stu[i].b)
					e[++cnt3].gap3 = stu[i].c - stu[i].a;
			}
		}
		//cout << cnt1 << ' ' << cnt2 << " " << cnt3;
		int num = n / 2;
		if (cnt1 > num) {
			int o = 1;
			sort(q + 1, q + 1 + cnt1, cmp);
			while (cnt1 > num) {
				cnt1--;
				sum -= q[o++].gap1;
			}
		} else if (cnt2 > num) {
			int o = 1;
			sort(w + 1, w + 1 + cnt2, cmp1);
			while (cnt2 > num) {
				//cout << cnt2 << " ";
				cnt2--;
				//	cout << w[o].gap << endl;
				sum -= w[o++].gap2;
			}
		} else if (cnt3 > num) {
			int o = 1;
			sort(e + 1, e + 1 + cnt3, cmp2);
			while (cnt3 > num) {
				cnt3--;
				sum -= e[o++].gap3;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}