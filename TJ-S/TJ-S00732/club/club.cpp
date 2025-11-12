#include <bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mpr make_pair
#define pii pair<int,int>
using namespace std;

const int MAXN = 1e5 + 5;
int n , cnt[4];
int a[MAXN][4];
int ans , res;
bool CA , CB;

void dfs(int p){
	if (p > n){
		ans = max(res , ans);
		return ;
	}
	for (int i = 1 ; i <= 3 ; i ++){
		if (cnt[i] + 1 <= (n >> 1)){
			res += a[p][i];
			cnt[i] ++;
			dfs(p + 1);
			cnt[i] --;
			res -= a[p][i];
		}
	}
}

void solveA(){
	priority_queue <int> q;
	for (int i = 1 ; i <= n ; i ++) q.push(a[i][1]);
	for (int _ = 1 ; _ <= (n >> 1) ; _ ++) ans += q.top() , q.pop();
	cout << ans << endl;
	return ;
}

void solve(){
	ans = res = cnt[1] = cnt[2] = cnt[3] = 0;
	CA = CB = 1;
	cin >> n;
	for (int i = 1 , x ; i <= n ; i ++){
		for (int j = 1 ; j <= 3 ; j ++){
			cin >> a[i][j];
		}
		if (a[i][2] || a[i][3]) CA = 0;
	}
	if (CA){
		solveA();
		return ;
	}
	dfs(1);
	cout << ans << endl;
	return ;
}

signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin >> T;
	while (T --) solve();
	return 0;
}
