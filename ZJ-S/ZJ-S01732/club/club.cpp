#include<bits/stdc++.h>
#define int long long

using namespace std;

inline int read(){
	int s = 0, w = 1;
	char ch = getchar();
	for (; ch < '0' || ch > '9'; w *= (ch == '-') ? -1 : 1, ch = getchar());
	for (; ch >= '0' && ch <= '9'; s = s * 10 + (ch - '0'), ch = getchar());
	return s * w;
}

const int INF = 0x3f3f3f3f3f3f3f3f, N = 1e5 + 5;

int T, n, a[N][4], p[N], cnt[10];
priority_queue<int> Q;

signed main(){
//	freopon("../../csps/down/club/club1.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--){
		cnt[1] = cnt[2] = cnt[3] = 0;
		int ans = 0;
		n = read();
		for (int i = 1; i <= n; i++){
			int mx = -INF;
			for (int j = 1; j <= 3; j++){
				a[i][j] = read();
				if (a[i][j] > mx) p[i] = j, mx = a[i][j];
			}
			cnt[p[i]]++, ans += mx;
		}
		if (max({cnt[1], cnt[2], cnt[3]}) > n / 2){
			int pos = 0;
			for (int i = 1; i <= 3; i++){
				if (cnt[i] > n / 2) pos = i;
			}
			for (int i = 1; i <= n; i++){
				if (p[i] == pos){
					int mx = 0;
					for (int j = 1; j <= 3; j++){
						if (j != pos) mx = max(mx, a[i][j]);
					}
					Q.push(mx - a[i][p[i]]);
				}
			}
			for (int i = 1; i <= cnt[pos] - n / 2; i++) ans += Q.top(), Q.pop();
			while (!Q.empty()) Q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}

