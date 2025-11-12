#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[101000][4], ans;
int tong[3];
vector<int> shan;
void solve(){
	cin >> n;
	tong[1] = tong[2] = tong[3] = 0;
	shan.clear();
	ans = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		int x = max(a[i][1], max(a[i][2], a[i][3]));
		ans += x;
		if(x == a[i][1]) tong[1]++;
		else if(x == a[i][2]) tong[2]++;
		else tong[3]++;
	}
	int tempi = 0;
	if(tong[1] <= (n / 2) && tong[2] <= (n / 2) && tong[3] <= (n / 2)){
		cout << ans << "\n";
		return;
	}
	if(tong[1] > (n / 2)) tempi = 1;
	else if(tong[2] > (n / 2)) tempi = 2;
	else tempi = 3;
	for(int i = 1;i <= n;i++){
		int x = max(a[i][1], max(a[i][2], a[i][3]));
		if(x == a[i][tempi]){
			int tempmaxx = -1;
			for(int j = 1;j <= 3;j++){
				if(j == tempi) continue;
				tempmaxx = max(tempmaxx, a[i][j]);
			}
			shan.push_back(x - tempmaxx);
		}
	}
	sort(shan.begin(), shan.end());
	while(tong[tempi] > (n / 2)){
		tong[tempi]--;
		ans -= shan[0];
		shan.erase(shan.begin());
	}
	cout << ans << "\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		solve();
	} 
	return 0;
}

