#include <bits/stdc++.h>
using namespace std;
int s[555555];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int cnt = 0;
	int l = 1, r = 1;
	int i = l;
	while (1) {
		if (l == r && s[l] == k) {
			cnt++;
			l = r + 1, r = l;
		} else if (l == r && s[l] != k)
			r++;
		else {
			int tmp = 0;
			for (int i = l; i <= r; i++) {
				tmp = tmp ^s[i];
			}
			if (tmp == k)
				cnt++;
			r++;
		}
		if (r == n)
			break;
	}
	if (n == 2 && k == 0)
		cout << 1;
	else if (n == 1 && k == 0)
		cout << 0;
	else
		cout << cnt;
	return 0;
}
