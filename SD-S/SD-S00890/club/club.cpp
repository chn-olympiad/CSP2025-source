#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 50;
int n, ans = 0;
struct Node {
	int p1, p2, p3;
}mp[N];
void dfs(int cnt, int sum, int c1, int c2, int c3) { 
	if(cnt == n + 1) {
		if(c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2) {
			ans = max(ans, sum);
		}
		return;
	}
	sum += mp[cnt].p1;
	dfs(cnt + 1, sum, c1 + 1, c2, c3);
	sum -= mp[cnt].p1;
	
	sum += mp[cnt].p2;
	dfs(cnt + 1, sum, c1, c2 + 1, c3);
	sum -= mp[cnt].p2;
	
	sum += mp[cnt].p3;
	dfs(cnt + 1, sum, c1, c2, c3 + 1);
	sum -= mp[cnt].p3;
}
bool cmp(Node a, Node b) {
	return a.p1 < b.p1;
}
bool cmp2(Node a, Node b){
	return a.p2 < b.p2;
}
int sum1() {
	int ttt = 0;
	for(int i = 1; i <= n; i ++) {
		ttt += mp[i].p2 + mp[i].p3;
	}
	return ttt;
}
int sum2() {
	int ttt = 0;
	for(int i = 1; i <= n; i ++) {
		ttt += mp[i].p3;
	}
	return ttt;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T --) {
		ans = 0;
		memset(mp, 0, sizeof(mp));
		cin >> n;
		bool flag = 1, flag2 = 1;
		for(int i = 1; i <= n; i ++) {
			cin >> mp[i].p1 >> mp[i].p2 >> mp[i].p3;
		}
		if(sum1() == 0) { //特殊性质A 5pts 
			sort(mp + 1, mp + n + 1, cmp);
			for(int i = n; i >= n / 2 + 1; i --) {
				ans += mp[i].p1;
			}
			cout << ans << "\n";
		} else { //前4个点 20pts 
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}
		
	}
	return 0;
}


