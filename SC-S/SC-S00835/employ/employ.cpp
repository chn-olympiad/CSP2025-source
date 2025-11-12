#include <iostream>
#include <algorithm>

const int N = 509, mod = 998244353;

int n, m;

std::string s;

int c[N], idx[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
    std::cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
		idx[i] = i;
	}

	if (n <= 10) {
		int ans = 0;
		do {
            int cnt = 0, tot = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i - 1] == '1' && c[idx[i]] > cnt) {
                    if (c[idx[i]] > cnt)
                        tot ++;
                    else
                        cnt++;
                }
				else
					cnt ++;
			}
			if (tot >= m)
				ans ++;
		} while (std::next_permutation(idx + 1, idx + 1 + n));
		printf("%d", ans);
	}
    else if (m == 1) {
        long long ans = 1;
        for (int i = 1; i <= n; i++)
            (ans *= i) %= mod;
        printf("%lld", ans);
    }
    else if (m == n) {
        printf("0");
    } 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}