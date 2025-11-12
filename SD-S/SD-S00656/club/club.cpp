#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
#define N 100005
int n,a[N][5];
int cnt[5];
pair<int,int> maxn[N],m[N],p[N];
void solve(){
	memset(p,0,sizeof(p));
	memset(cnt,0,sizeof(cnt));
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		int MAXN = -1,M = -1,x = 0,y = 0;
		for(int j = 1; j <= 3; j++){
			if(a[i][j] > MAXN){
				M = MAXN;
				y = x;
				x = j;
				MAXN = a[i][j];
			}else if(a[i][j] > M){
				M = a[i][j];
				y = j;
			}
		}
		maxn[i] = {MAXN,x};
		m[i] = {M,y};
		p[i] = {MAXN - M,i};
	}
	sort(p + 1,p + n + 1);
	i64 ans = 0;
	for(int i = n; i >= 1; i--){
		if(cnt[maxn[p[i].second].second] == n / 2){
			++cnt[m[p[i].second].second];
			ans += m[p[i].second].first;
		}else{
			++cnt[maxn[p[i].second].second];
			ans += maxn[p[i].second].first;
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

