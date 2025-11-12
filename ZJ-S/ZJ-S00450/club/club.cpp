#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 100100, M = 3;
int n, a[N][M], pos[N],tmp[N], cnt[M];
void solve(){
	cin >> n;
	int ans = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n;i++){
		int maxx = -1;
		for (int j = 0; j < M;j++){
			cin >> a[i][j];
			if(maxx<a[i][j]){
				maxx = a[i][j];
				pos[i] = j;
			}
		}
		cnt[pos[i]]++;
		ans += maxx;
	}
	int p = -1;
	for (int i = 0; i < M;i++){
		if(cnt[i]>(n>>1))
			p = i;
	}
	if(p==-1)
		cout << ans << '\n';
	else{
		int sz = 0;
		for (int i = 1; i <= n;i++){
			if(pos[i]==p){
				tmp[++sz] = min(a[i][p] - a[i][(p + 1) % 3], a[i][p] - a[i][(p + 2) % 3]);
			}
		}
		sort(tmp + 1, tmp + 1 + sz);
		for (int i = 1; i <= cnt[p] - (n >> 1);i++){
			ans -= tmp[i];
		}
		cout << ans << '\n';
	}
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		solve();
	return 0;
}