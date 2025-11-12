# include <bits/stdc++.h>
# define endl '\n'
typedef long long i64;

const int _ = 1e5 + 10;

int n, a[_][4];
int b[4][_], cnt[4], sum;

void solve(){
	std::cin >> n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= 3;j++){
			std::cin >> a[i][j];
		}
	}
	
	cnt[1] = cnt[2] = cnt[3] = 0;
	sum = 0;
	for(int i = 1;i <= n;i++){
		int mx = std::max(a[i][1], std::max(a[i][2], a[i][3]));
		if(a[i][1] == mx) b[1][++ cnt[1]] = a[i][1] - std::max(a[i][2], a[i][3]);
		else if(a[i][2] == mx) b[2][++ cnt[2]] = a[i][2] - std::max(a[i][1], a[i][3]);
		else b[3][++ cnt[3]] = a[i][3] - std::max(a[i][1], a[i][2]);
		sum += mx;
	}
	
	std::sort(b[1] + 1, b[1] + 1 + cnt[1]);
	std::sort(b[2] + 1, b[2] + 1 + cnt[2]);
	std::sort(b[3] + 1, b[3] + 1 + cnt[3]);
	
	for(int i = 1;i <= cnt[1] - n / 2;i++) sum -= b[1][i];
	for(int i = 1;i <= cnt[2] - n / 2;i++) sum -= b[2][i];
	for(int i = 1;i <= cnt[3] - n / 2;i++) sum -= b[3][i];
	
	std::cout << sum << endl;
}

signed main(){
	std::cin.tie(nullptr) -> sync_with_stdio(false);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	std::cin >> t;
	while(t --) solve();
	return 0;
} 
