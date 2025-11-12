#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long T, num, a[N];
bool vis[N];

struct note {
	int a, b, c;
	bool vis;
} q[N];

bool cmp1(note x, note y) {
	return x.a > y.a;
}

bool cmp2(note x, note y) {
	return x.b > y.b;
}

bool cmp3(note x, note y) {
	return x.c > y.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		bool flag = 0;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			if (q[i].b != 0 || q[i].c != 0) {
				flag = 1;
			}
		}
		long long p = 0, sum = 0;
		if (flag == 0) {
			sort(q + 1, q + 1 + num, cmp1);
			for (int i = 1; i <= num / 2; i++) {
				sum += q[i].a;
			}
			cout << sum << "\n";
			continue;
		}
		for (int i = 1; i <= num; i++) {
			q[i].vis = 0;
		}
		sort(q + 1, q + 1 + num, cmp1);
		for (int i = 1; i <= num; i++) {
			if (q[i].a > q[i].b && q[i].a > q[i].c && p < num / 2) {
				p++;
				sum += q[i].a;
				q[i].vis = 1;
//				cout << i << " ";
			}
		}
//		cout << sum << " ";
		sort(q + 1, q + 1 + num, cmp2);
		p = 0;
		for (int i = 1; i <= num; i++) {
			if (q[i].b > q[i].a && q[i].b > q[i].c && p < num / 2 && q[i].vis == 0) {
				p++;
				sum += q[i].b;
				q[i].vis = 1;
//				cout << i << " ";
			}
		}
		sort(q + 1, q + 1 + num, cmp3);
		p = 0;
		for (int i = 1; i <= num; i++) {
			if (q[i].c > q[i].a && q[i].c > q[i].b && p < num / 2 && q[i].vis == 0) {
				p++;
				sum += q[i].c;
				q[i].vis = 1;
//				cout << i << " ";
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
