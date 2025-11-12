#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, n, a[100005][3], ans;
vector < int > vt[3];
void F(int p){
	priority_queue < int > q;
	for(int i = 0; i < vt[p].size(); i++){
		q.push(max(a[vt[p][i]][(p+1)%3], a[vt[p][i]][(p+2)%3]) - a[vt[p][i]][p]);
		while(q.size() > n / 2){
			ans += q.top();
			q.pop();
		}
	}
	return;
}
void solve(){
	cin >> n;
	ans = 0;
	vt[0].clear();
	vt[1].clear();
	vt[2].clear();
	for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	for(int i = 1; i <= n; i++){
		if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
			ans += a[i][0];
			vt[0].push_back(i);
		}else if(a[i][1] >= a[i][2]){
			ans += a[i][1];
			vt[1].push_back(i);
		}else{
			ans += a[i][2];
			vt[2].push_back(i);
		}
	}
	if(vt[0].size() <= n / 2 && vt[1].size() <= n / 2 && vt[2].size() <= n / 2){
		cout << ans << "\n";
		return;
	}
	if(vt[0].size() >= n / 2) F(0);
	else if(vt[1].size() >= n / 2) F(1);
	else F(2);
	cout << ans << "\n";
	return;
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) solve();
	return 0;
}