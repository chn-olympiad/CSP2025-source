#include <bits/stdc++.h>
using namespace std;

long long l[] = {}, ml, cnt;
int n;

int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 3; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int h = j; h < n - i - j; h++) {
				int al = l[h];
				for (int k = h + 1; k < h + i ; k++) {
					al += l[k];
					ml = max(l[k], l[k - 1]);
				}
				if (al > 2 * ml)
					cnt++;
				ml = 0;
			}
		}
	}
	cout << cnt % 998244353 * 3;
	return 0;
}