#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, a[500005], sxor[500005], ans;

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sxor[i] = sxor[i - 1] ^ a[i];//前缀异或和
	}
	for (int i = 1; i <= n; i++) { //起点
		int flag = 0;
		for (int j = 1; j + i - 1 <= n; j++) { //长度
			ll xxor = sxor[j + i - 1] ^ sxor[i - 1]; //区间异或和
			if (xxor == k) {
				ans++;
				i += j;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			i--;
	}
	cout << ans;

	return 0;
}