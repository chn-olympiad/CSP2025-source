#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;

struct ss {
	ll cj, xh;
} s[1110];

bool cmp(ss a, ss b) {
	return  a.cj > b.cj;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i].cj;
		s[i].xh = i;
	}
	sort(s + 1, s + n *m + 1, cmp);
	int k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (s[k].xh == 1) {
				cout << i << " " << j;
				return 0;
			}
			k++;
		}
		i++;
		for (int j = m; j > 0; j--) {

			if (s[k].xh == 1) {
				cout << i << " " << j;
				return 0;
			}
			k++;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
