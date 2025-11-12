#include <bits/stdc++.h>

using namespace std;
#define int long long

int t, n, d;
const int N = 1e5 + 10;
int a[N][5];
int g[N], id[N], cnt[N];
int suma, sumb, sumc;
int ida, idb, idc;
int ans, res;

inline void dfs(int x){
	if (x == n + 1){
		ans = max(ans, suma + sumb + sumc);
		return;
	}
	if (ida < n / 2){
		suma += a[x][1];
		ida++;	
		dfs(x + 1);
		suma -= a[x][1];
		ida--;
	}
	if (idb < n / 2){
		sumb += a[x][2];
		idb++;
		dfs(x + 1);
		sumb -= a[x][2];
		idb--;
	}
	if (idc < n / 2){
		sumc += a[x][3];
		idc++;
		dfs(x + 1);
		sumc -= a[x][3];
		idc--;
	}
}

inline void sub1(){
	int maxn = -1;
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			if (i == j) continue;
			maxn = max(maxn, a[1][i] + a[2][j]);
		}
	}	
	cout << maxn << "\n";
	return;
}

inline void sub3(){
	for (int i = 1; i <= n; i++)
		g[i] = a[i][1];
	sort(g + 1, g + 1 + n);
	for (int i = 1; i <= 2 / n; i++)
		ans += g[n - i + 1];
	cout << ans;
	return;
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		cin >> n;
		ans = -1;
		memset(a, 0, sizeof a);
		suma = sumb = sumc = ida = idb = idc = 0;
		res = 0, d = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
				if ((j == 2 && a[i][j] == 0) || (j == 3 && a[i][j] == 0)) res++;
			}
		}
		if (n == 2){
			sub1();
			continue;
		}
		if (n <= 10){
			dfs(1);
			cout << ans << "\n";
			continue;
		}
		if (res == n){
	  		sub3();
			continue;
		}
		for (int i = 1; i <= n; i++){
			int maxx = -1;
			for (int j = 1; j <= 3; j++){
				if (a[i][j] > maxx){
					maxx = a[i][j];
					id[i] = j;
					cnt[j]++;
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans += a[i][id[i]];
		cout << ans << "\n";
	}
	return 0;
}

