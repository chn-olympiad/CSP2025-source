#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int read(){ int x = 0, f = 1; char ch = getchar(); while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar(); } while(isdigit(ch)){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); } return x * f; }

const int N = 1e5 + 10;
int t, n, ans, mp[5], pm[5][N], top[5];

struct node{
	int k, id;
	bool operator < (const node &cmp) const { return k > cmp.k; }
}a[N][5];


void solve(){
	cin >> n; ans = 0;
	mp[1] = mp[2] = mp[3] = 0;
	top[1] = top[2] = top[3] = 0;
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= 3; ++ j){
			cin >> a[i][j].k;
			a[i][j].id = j;
		} sort(a[i] + 1, a[i] + 4);
		a[i][4].k = a[i][1].k - a[i][2].k;
	}
	for(int i = 1; i <= n; ++ i){
		ans += a[i][1].k; ++ mp[a[i][1].id];
		pm[a[i][1].id][++ top[a[i][1].id]] = a[i][4].k;
	}
	for(int x = 1; x <= 3; ++ x){
		if(mp[x] > (n >> 1)){
			sort(pm[x] + 1, pm[x] + 1 + top[x]);
			for(int i = 1; i <= top[x] - (n >> 1); ++ i){
				ans -= pm[x][i];
			}
		}
	} cout << ans << "\n";
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t --)
		solve();
	
	return 0;
}

