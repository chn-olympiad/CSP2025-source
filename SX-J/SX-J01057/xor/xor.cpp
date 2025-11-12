#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> num(500010, 0), sum(500010, 0), vis(500010, 0), tmp(500010, 0);

int myFind(int s, int e) {
	int L = s, R = e;
	while (L < R) {
		int M = (L + R) / 2;
		int ans = sum[M - 1] ^ sum[e];
		if (ans == k) {
			return M;
		}

		if (ans > k) {
			R = M;
		} else {
			L = M + 1;
		}
	}

	if (sum[L - 1] ^ sum[e] != k) {
		return -1;
	} else {
		return L;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	// 异或和满足前缀和
	// l到r的异或和为sum[l-1] ^ sum[r]
	for (int i = 1; i <= n; i ++) {
		cin >> num[i];
		sum[i] = sum[i - 1] ^ num[i];
	}

	int ans = 0;
	for (int r = 1; r <= n; r ++) {
		int l = myFind(1, r);

		if (l != -1) {
			//cout << l << ' ' << r << endl;
			tmp = vis;
			bool chongFu = false;
			for (int i = l; i <= r; i ++) {
				vis[i] ++;
				if (vis[i] > 1) {
					vis = tmp;
					chongFu = true;
					break;
				}
			}

			if (!chongFu) {
				ans ++;
			}
		}
	}

	cout << ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}