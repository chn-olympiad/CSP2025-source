// Ren5Jie4Di4Ling5%
/*
author: WilliamFranklin
AFOed on 2025/11/1

我常常追忆过去，忘了。 

我该在哪里停留？我问我自己。 
*/ 
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
const int N = 1e5 + 5;
int n;
pair<int, int> a[N][3];
int cnt[3];
int main() {
	assert(freopen("club.in", "r", stdin));
	assert(freopen("club.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	int T = 1;
	cin >> T;
	while (T--) {
		cin >> n;
		long long ans = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		For(i, 1, n) {
			For(j, 0, 2) {
				cin >> a[i][j].x;
				a[i][j].y = j;
			}
			sort(a[i], a[i] + 3);
			cnt[a[i][2].y]++;
			ans += a[i][2].x;
		}
		int t = -1;
		if (cnt[0] > n / 2) t = 0;
		if (cnt[1] > n / 2) t = 1;
		if (cnt[2] > n / 2) t = 2;
		if (t == -1) cout << ans << '\n';
		else {
			priority_queue<int, vector<int>, greater<int> > q;
			For(i, 1, n) {
				if (a[i][2].y == t) {
					q.push(a[i][2].x - a[i][1].x); 
				}
			} 
			int cntt = cnt[t] - n / 2;
			For(i, 1, cntt) {
				ans -= q.top();
				q.pop();
			}
			cout << ans << '\n';
		} 
	}
	return 0;
} 
