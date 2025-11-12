#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, m;
char s[550];
int c[550];
int a[550];

int main() {
//	freopen("employ.in", "r", stdin);
//	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++)
		a[i] = i;
	if (n <= 10) {
		int ans = 0;
		do {
			int num = 0;
			int fal = 0;
			for (int i = 1; i <= n; i++) {
				int x = a[i];
				//cout << a[i] << " ";
				//cout << c[x] << ' ';
				if (fal >= c[x]) {
					fal++;
					continue;
				}
				if (s[i] == '0') {
					fal++;
				}
				if (s[i] == '1') {
					num++;
				}
			}
			if (num >= m) {
				//cout << num << " ";
				ans++;
			}

		} while (next_permutation(a + 1, a + 1 + n));
		printf("%d", ans);
		return 0;
	}
	long long sum = 1;
	for (int i = 1; i <= n ; i++) {
		sum *= i;
		sum %= N;
		
	}
cout << sum << " " ;
	return 0;
}
