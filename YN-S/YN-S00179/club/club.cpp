#include <bits/stdc++.h>
#define For(a,b,i) for(int i=a;i<=b;i++)
using namespace std;
const int N = 1e5 + 5;
int n, m;

struct node {
	int a, b, c;
	int book;
} s[N];

bool cmp(node x, node y) {
	return x.a > y.a;
}

bool cnt(node x, node y) {
	return x.b > y.b;
}

bool cst(node x, node y) {
	return x.c > y.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("ciub.out", "w", stdout);

	cin >> m;
	while (m--) {
		int ans = 0;
		cin >> n;
		For(1, n, i) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			s[i].book++;
		}
		sort(s + 1, s + n + 1, cmp);
		For(1, n, i) {
			int w = 0;
			if (s[i].a > s[i].b && s[i].a > s[i].c && s[i].book != 0) {
				w++;
				if (w > n / 2) {
					break;
				}
				ans += s[i].a;
				s[i].book = 0;
			}
		}
		sort(s + 1, s + n + 1, cnt);
		For(1, n, i) {
			int w = 0;
			if (s[i].b > s[i].a && s[i].b > s[i].c && s[i].book != 0) {
				w++;
				if (w > n / 2) {
					break;
				}
				ans += s[i].b;
				s[i].book = 0;
			}
		}
		sort(s + 1, s + n + 1, cst);
		For(1, n, i) {
			int w = 0;
			if (s[i].c > s[i].b && s[i].c > s[i].a && s[i].book != 0) {
				w++;
				if (w > n / 2) {
					break;
				}
				ans += s[i].c;
				s[i].book = 0;
			}
		}
		cout << ans << endl;
	}

	return 0;
}