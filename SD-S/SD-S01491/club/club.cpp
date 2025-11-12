#include<bits/stdc++.h>
#define INF 2147483647
#define fo(a, b, c) for(int b = a; b <= c; b++)
#define _fo(a, b, c) for(int b = a; b >= c; b--)
#define Fo(a, b) for(auto a : b)
#define pb push_back
#define lb lower_bound
#define N 100010
using namespace std;
#define int long long
int T, n, cnt[4], ans, mx, p;
struct node{
	int w, id;
}a[N][4];
vector<node>vec[N];
vector<int>v;
bool cmp(node x, node y){
	return x.w > y.w;
}
bool chk(){
	fo(1, i, 3) if(cnt[i] > mx) mx = cnt[i], p = i;
	if(mx > n / 2) return 0;
	return 1;
}
void solve(){
	ans = 0, mx = 0, p = 0;
	memset(cnt, 0, sizeof cnt);
	v.clear();
	cin >> n;
	fo(1, i, n) fo(1, j, 3) cin >> a[i][j].w, a[i][j].id = j;
	fo(1, i, n){
		vec[i].clear();
		fo(1, j, 3) vec[i].pb(a[i][j]); 
		sort(vec[i].begin(), vec[i].end(), cmp);
		int id = vec[i][0].id;
		cnt[id]++, ans += vec[i][0].w;
	}
	if(chk()){
		cout << ans << "\n";
		return;
	}
	int dx = mx - n / 2;
	fo(1, i, n){
		if(vec[i][0].id == p){
			int Min = vec[i][0].w - vec[i][1].w;
			v.pb(Min);
		}
	}
	sort(v.begin(), v.end());
	fo(0, i, dx - 1) ans -= v[i];
	cout << ans << "\n";
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--) solve();
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/

