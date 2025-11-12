#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,k;
ll a[100005][3],l[100005][3];
priority_queue<pair<ll,ll> > q;
void dfs(ll u,ll a1,ll a2,ll lv){
	if(u == n + 1){
		ans = max(ans,lv);
		return;
	}
	for(int i = 0;i <= 2;i++){
		if(l[u][i] == 0 && a1 < m) dfs(u + 1,a1 + 1,a2,lv + a[u][l[u][i]]);
		else if(l[u][i] == 1 && a2 < m) dfs(u + 1,a1,a2 + 1,lv + a[u][l[u][i]]);
		else if(l[u][i] == 2 && u - a1 - a2 < m) dfs(u + 1,a1,a2,lv + a[u][l[u][i]]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin>> T;
	while(T--){
		ans = 0;
		k = 0;
		cin>> n;
		m = n / 2;
		for(int i = 1;i <= n;i++){
			cin>> a[i][0] >> a[i][1] >> a[i][2];
			if(a[i][2] != 0) k = 1;
			q.push({a[i][0] - a[i][1],i});
			if(a[i][0] >= a[i][1]){
				if(a[i][0] >= a[i][2]){
					l[i][0] = 0;
					if(a[i][1] >= a[i][2]){
						l[i][1] = 1;
						l[i][2] = 2;
					}
					else{
						l[i][1] = 2;
						l[i][2] = 1;
					}
				}
				else{
					l[i][0] = 2;
					l[i][1] = 0;
					l[i][2] = 1;
				}
			}
			else{
				if(a[i][1] >= a[i][2]){
					l[i][0] = 1;
					if(a[i][0] >= a[i][2]){
						l[i][1] = 0;
						l[i][2] = 2;
					}
					else{
						l[i][1] = 2;
						l[i][2] = 0;
					}
				}
				else{
					l[i][0] = 2;
					l[i][1] = 1;
					l[i][2] = 0;
				}
			}
		}
		if(n == 2){
			if(a[1][l[1][0]] > a[2][l[2][0]]) ans = a[1][l[1][0]] + a[2][l[2][1]];
			else if(a[1][l[1][0]] == a[2][l[2][0]]) ans = a[1][l[1][0]] + max(a[2][l[2][1]],a[1][l[1][1]]);
			else ans = a[1][l[1][1]] + a[2][l[2][0]];
			cout<< ans << "\n";
			continue;
		}
		if(k = 1){
			dfs(1,0,0,0);
			cout<< ans << "\n";
			continue;
		}
		for(int i = 1;i <= n;i++){
			if(i <= m) ans += a[q.top().second][0];
			else ans += a[q.top().second][1];
			q.pop();
		}
		cout<< ans << "\n";
	}
	return 0;
}
