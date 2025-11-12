#include <bits/stdc++.h>
using namespace std;
int n, a[100005][3];
vector<int> vec[3];
void solve(){
	cin >> n;
	vec[0].clear();
	vec[1].clear();
	vec[2].clear();
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		
		int maxn = max(max(a[i][0], a[i][1]), a[i][2]);
		ans += maxn;
		if(maxn == a[i][0]){
			vec[0].push_back(maxn - max(a[i][1], a[i][2]));
		} else if(maxn == a[i][1]){
			vec[1].push_back(maxn - max(a[i][0], a[i][2]));
		} else {
			vec[2].push_back(maxn - max(a[i][0], a[i][1]));
		}
	}
	
	if((int)vec[1].size() > n / 2) swap(vec[0], vec[1]);
	if((int)vec[2].size() > n / 2) swap(vec[0], vec[2]);
	
	if((int)vec[0].size() <= n / 2) cout << ans << "\n";
	else {
		int cnt = (int)vec[0].size() - n / 2;
		sort(vec[0].begin(), vec[0].end());
		
		for(int i = 0; i < cnt; i++) ans -= vec[0][i];
		cout << ans << "\n";
	} 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
