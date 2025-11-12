#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+5;
int n, k, ans;
int arr[N], sum[N], t[N];

/*
void dfs(int i, int j) {
	if ((sum[j] ^ sum[i - 1]) == k) {
		for (int x = i; x <= j; x++) {
			if (t[x] != 0)
				return;
		}
		ans++;
		return;
	}
	if (i > n || j > i || j > n)
		return;
	for (int x = i; x <= j; x++)
		t[x] = 1;
	dfs(i, j + 1);
	dfs(i + 1, i + 1);
	for (int x = i; x <= j; x++)
		t[x] = 0;
}
*/
signed main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = (sum[i - 1] ^ arr[i]);
	}

	for (int i = 1; i <= n; i++) {//×ó¶Ëµã
		for (int j = 1; j <= n; j++) {//ÓÒ¶Ëµã
			if ((sum[j] ^ sum[i - 1]) == k && t[i] == 0 && t[j] == 0) {
				for (int z = i; z <= j; z++) {
					t[z] = 1;
				}
				ans++;

				break;
			}
		}
	}
	/*
	dfs(1, 1);*/
	cout << ans;

	return 0;
}


/*
4 2
2 1 0 3

2 3 3 0---sum[]

1 2 =
1 3
3 4
4 4 =

*/