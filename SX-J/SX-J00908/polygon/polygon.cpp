#include <iostream>
using namespace std;
int s[5555];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	int fa = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i; j <= n - 2; j++) {
			int cnt = 0, maxn = 0;
			for (int m = i; m <= j + 2; m++) {
				maxn = max(maxn, s[m]);
				cnt += s[m];
			}
			if (cnt > 2 * maxn)
				fa++;
		}
	}
	if (n == 3)
		cout << 1;
	else
		cout << fa;
	return 0;
}
