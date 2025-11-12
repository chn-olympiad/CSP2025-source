#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
int s[100010];
int c[100010];
int n,m;
int vis[100010];
int ans;
void dfs(int k,int sum,int ko){
	if (k > n){
		if (sum >= m){
			ans++;
//			cout << sum << ' ';
		}
//		cout << 1 << endl;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (!vis[i]){
			vis[i] = 1;
			if (c[i] > ko && str[k - 1] == '1'){
				dfs(k + 1,sum + 1,ko);
			}
			else{
				dfs(k + 1,sum,ko + 1);
			}
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> str;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
}
