#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ls (root << 1)
#define rs (root << 1 | 1)
#define fastio ios :: sync_with_stdio(false);\
			   cin.tie(nullptr);\
			   cout.tie(nullptr);
			   
using namespace std;

const int maxn = 1e5 + 10;
int n, ans;
bool flaga = 1, flagb = 1;
int a[maxn][5];
int c[maxn];
//int dp[maxn][5];
//vector<int> cnt[5];

//void solve(){
//	memset(a, 0, sizeof a);
//	cin >> n;
//	for(int i = 1; i <= n; i++){
//		cin >> a[i][1] >> a[i][2] >> a[i][3];
//	}
//	for(int i = 1; i <= n; i++){
//		if(cnt[1].size() < n / 2){
//			cnt[1].pb(i);
//			dp[i][1] = max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + a[i][1]; 
//		}
//	}
//}

bool cmp(int a, int b){
	return a < b;
}

void check(){
	int res = 0;
	int cnt[5] = {0,0,0,0,0};
	for(int i = 1; i <= n; i++){
		if(cnt[c[i]] == n / 2) return;
		cnt[c[i]]++;
		res += a[i][c[i]];
	}
	ans = max(ans, res);
}

void dfs(int x){
	if(x == n + 1){
		check();
		return;
	} 
	c[x] = 1;
	dfs(x + 1);
	c[x] = 2;
	dfs(x + 1);
	c[x] = 3;
	dfs(x + 1);
	c[x] = 0;
}

void solve(){
	ans = 0;
	memset(a, 0, sizeof a);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2] != 0 || a[i][3] != 0) flaga = 0;
		if(a[i][3] != 0) flagb = 0;
	}
	if(n <= 10){
		dfs(1);
		cout << ans << endl;
		return;
	}
	if(flagb){
		int cnt1 = 0, cnt2 = 0;
		for(int i = 1; i <= n; i++){
			if(a[i][1] > a[i][2]){
				if(cnt1 == n / 2){
					ans += a[i][2];
					cnt2++;
				}else {
					ans += a[i][1];
					cnt1++; 
				}
			}else if(a[i][1] == a[i][2]){
				if(cnt1 > cnt2){
					cnt1++;
				}else cnt2++;
			}else{
				if(cnt2 == n / 2){
					ans += a[i][1];
					cnt1++;
				}else{
					ans += a[i][2];
					cnt2++;
				}
			}
		}	
	}else if(flaga){
		for(int i = 1; i <= n; i++)
			c[i] = a[i][1];
		sort(c + 1, c + 1 + n);
		for(int i = 1; i <= n / 2; i++){
			ans += c[i];
		}
		cout << ans << endl;
	}

}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fastio
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
/*
2
4
4 2 1 
3 2 4
5 3 4 
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
