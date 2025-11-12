#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
}a[100005];
bool cmp(pair<int,int> a,pair<int,int> b){return a.second < b.second;}
int dif[100005];
void solve(){
	int n; cin >> n;
	map<int,vector<int>> mp;
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].x >= a[i].y && a[i].x >= a[i].z) mp[1].push_back(i);
		else if(a[i].y >= a[i].x && a[i].y >= a[i].z) mp[2].push_back(i);
		else mp[3].push_back(i);
	}
	if(mp[1].size() <= n / 2 && mp[2].size() <= n / 2 && mp[3].size() <= n / 2){
		int ans = 0;
		for(auto i : mp[1]) ans += a[i].x;
		for(auto i : mp[2]) ans += a[i].y;
		for(auto i : mp[3]) ans += a[i].z;
		cout << ans << "\n";
		return;
	}
	int ans = 0;
	for(auto i : mp[1]) ans += a[i].x;
	for(auto i : mp[2]) ans += a[i].y;
	for(auto i : mp[3]) ans += a[i].z;
	int tot = 0;
	if(mp[1].size() > n / 2){
		for(auto i : mp[1]) dif[++tot] = min(a[i].x - a[i].y,a[i].x - a[i].z);
		sort(dif + 1,dif + tot + 1);
		for(int i = 1;i <= mp[1].size() - n / 2;i++) ans -= dif[i];
		cout << ans << "\n";
	}else if(mp[2].size() > n / 2){
		for(auto i : mp[2]) dif[++tot] = min(a[i].y - a[i].x,a[i].y - a[i].z);
		sort(dif + 1,dif + tot + 1);
		for(int i = 1;i <= mp[2].size() - n / 2;i++) ans -= dif[i];
		cout << ans << "\n";
	}else{
		for(auto i : mp[3]) dif[++tot] = min(a[i].z - a[i].y,a[i].z - a[i].x);
		sort(dif + 1,dif + tot + 1);
		for(int i = 1;i <= mp[3].size() - n / 2;i++) ans -= dif[i];
		cout << ans << "\n";
	}
	for(int i = 1;i <= tot;i++) dif[i] = 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T; cin >> T;
	while(T--) solve();
	return 0;
}