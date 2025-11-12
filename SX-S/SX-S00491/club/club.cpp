#include <bits/stdc++.h>
using namespace std;
char buf[1 << 20], *p1, *p2;
#define getchar() (p1 == p2 &&(p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

void rd(int &a) {
	a = 0;
	char c;
	while ((c = getchar()) < 48);
	do
		a = (a << 3) + (a << 1) + (c ^ 48);
	while ((c = getchar()) > 47);
}

void wt(int a) {
	static int st[35];
	int top = 0;
	do {
		st[++top] = a % 10;
		a /= 10;
	} while (a);
	while (top)
		putchar(st[top--] + '0');
}

struct pr {
	int x, d;
	bool operator< (pr &b) {
		return (this->x < b.x);
	}
};


int t, n;
pr p[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	rd(t);
	while (t--) {
		rd(n);
		vector<int> arr[3];
		int ans = 0;
		for (int i = 0; i < n; i++) {
			rd(p[0].x), rd(p[1].x), rd(p[2].x);
			p[0].d = 0;
			p[1].d = 1;
			p[2].d = 2;
			sort(p, p + 3);
			ans += p[2].x;
			arr[p[2].d].push_back(p[2].x - p[1].x);
		}

		for (int j = 0; j < 3; j++) {
			int sz = arr[j].size();
			if (sz > (n >> 1)) {
				sort(arr[j].begin(), arr[j].end());
				for (int i = 0; i < (sz - (n >> 1)); i++)
					ans -= arr[j][i];
				break;
			}
		}
		wt(ans);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
