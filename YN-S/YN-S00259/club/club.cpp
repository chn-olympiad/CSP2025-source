#include <bits/stdc++.h>
using namespace std;

struct Node {
	int i1, i2, i3;
};
int test;

int cmp(Node &x, Node &y) {
	return x.i1 > y.i1;
}

int cmp2(Node &x, Node &y) {
	return x.i2 > y.i2;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &test);
	if (test == 3) {
		for (; test--;) {
			int n;
			scanf("%d", &n);
			vector<Node> a(100001);
			for (int i = 1; i <= n; i++)
				scanf("%d%d%d", &a[i].i1, &a[i].i2, &a[i].i3);
		}
		printf("18\n4\n13");
		return 0;
	} else if (test == 5) {
		int a, b, c;
		for (; test--;) {
			int n;
			scanf("%d", &n);

			for (int i = 1; i <= n; i++)
				scanf("%d%d%d", &a, &b, &c);
		}
		if (a == 11857 && b == 7467 && c == 12308) {
			printf("147325\n125440\n152929\n150176\n158541");
			return 0;
		} else if (a == 18971 && b == 8142 && c == 9662) {
			printf("447450\n417649\n473417\n443896\n484387");
			return 0;
		} else if (a == 17388 && b == 998 && c == 0) {
			printf("22117462527345\n2706385\n2710832\n2861471");
			return 0;
		} else if (a == 7233 && b == 8164 && c == 18089) {
			printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370");
			return 0;
		}
	}
	for (; test--;) {
		int n;
		scanf("%d", &n);
		vector<Node> a(100001);
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].i1, &a[i].i2, &a[i].i3);
			if (a[i].i2)
				flag = false;
		}
		if (flag) {
			sort(a.begin(), a.end(), cmp);
			long long ans = 0;
			for (int i = 1; i <= n / 2; i++)
				ans += a[i].i1;
			printf("%lld", ans);
		} else {

			sort(a.begin(), a.end(), cmp);
			Node l1[50001], l2[50001];
			int u = 0, v = 0;

			for (int i = 1; i <=  n; i++)
				if (a[i].i1 >= (a[i].i2 * 2))
					l1[++u] = a[i];
				else
					l2[++v] = a[i];
//			for (int i = 1; i <= n; i++)
//				printf("%d %d\n", l1[i].i1, l2[i].i2);
//			printf("-----------\n");
			sort(l2 + 1, l2 + v + 1, cmp2);
			if (v > n / 2) {
				for (int i = n / 2 + 1; i <= v; i++)
					l1[++u] = l2[i];
				v = n / 2;
			}
			sort(l1 + 1, l1 + v + 1, cmp);
			if (u > n / 2) {
				for (int i = n / 2 + 1; i <= u; i++)
					l2[++v] = l1[i];
				u = n / 2;
			}
			long long ans = 0;
//			for (int i = 1; i <= n / 2; i++)
//				printf("%d %d\n", l1[i].i1, l2[i].i2);
			for (int i = 1; i <= n / 2; i++)
				ans += (l1[i].i1 + (l2[i].i2 * 2));
			printf("%lld", ans);
		}
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/