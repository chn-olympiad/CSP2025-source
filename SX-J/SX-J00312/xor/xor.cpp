#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];
int n, k, an = 1;

struct edge {
	int st;
	int en;
} ed[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = a[i];
		if (cnt == k) {
			an++;
			ed[an].st = i;
			ed[an].en = i;
			continue;
		}
		for (int j = i + 1; j <= n; j++) {
			if ((cnt ^ a[j]) == k) {
				an++;
				ed[an].st = i;
				ed[an].en = j;
				break;
			} else {
				cnt ^= a[j];
			}
		}
	}
	int ans = 0, start = 0;
	for (int i = 1; i <= an; i++) {
		if (ed[i].st > start) {
			ans++;
			start = ed[i].en;
		} else if (ed[i].st < start && ed[i].en < start) {
			start = ed[i].en;
		}
	}
	cout << ans;
	return 0;
}
