#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int T, n, a[N][4], ans;
int c1, c2, c3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> T;
	while (T--){
		cin >> n, ans = 0;
		for (int i = 1;i <= n;++i){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (max(a[i][1], max(a[i][2], a[i][3])) == a[i][2] && c1 <= (n + 1) / 2){
				ans += a[i][3], ++c3;
			}
			else if (c2 <= (n + 1) / 2){
				ans += a[i][2], ++c2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/*

3 4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/