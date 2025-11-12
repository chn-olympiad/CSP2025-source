#include <bits/stdc++.h>
using namespace std;

const int N = 15;

struct info {
	int a, i;
};

int n, m;
info a[N*N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int l = n*m;
	for (int i = 1; i <= l; i++)
		scanf("%d", &a[i].a);
	for (int i = 1; i <= l; i++)
		a[i].i = i;
	sort(a+1, a+l+1, [](const info &a, const info &b){
		return a.a > b.a;
	});
	int pos = -1;
	for (int i = 1; i <= l; i++)
		if (a[i].i == 1) {
			pos = i;
			break;
		}
	int w/*hang*/ = 0, h/*lie*/ = 1;
	for (int i = 1; i <= pos; i++) {
		if (h & 1) {
			w++;
			if (w > n)
				++h, --w;
		} else {
			w--;
			if (w < 1)
				++h, ++w;
		}
	}
	printf("%d %d", h, w);
}
