#include <iostream>
#include <stdio.h>
typedef long long ll;
using namespace std;

const int MAXN = (int)1e5 + 5;
ll A[MAXN], B[MAXN], C[MAXN];

int t, n;

ll dfs(ll num, int ta, int tb, int tc){
	if (ta + tb + tc == n){
		return num;
	}
	return 
		max(
			ta < (n >> 1) ? dfs(num + A[ta + tb + tc], ta + 1, tb, tc) : num,
			max(
				tb < (n >> 1) ? dfs(num + B[ta + tb + tc], ta, tb + 1, tc) : num,
				tc < (n >> 1) ? dfs(num + C[ta + tb + tc], ta, tb, tc + 1) : num
			)
		);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> A[i] >> B[i] >> C[i];
		cout << dfs(0, 0, 0, 0) << '\n';
	}
}




