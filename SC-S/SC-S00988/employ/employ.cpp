#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, ans, c[505], b[505];
string s;
void dfs(int d, int tot, int ex){
	if(d == n + 1 && tot >= m){
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i]) continue;
		if(ex >= c[i]){
			b[i] = 1;
			dfs(d + 1, tot, ex + 1);
			b[i] = 0;
		}
		else if(s[d - 1] == '0'){
			b[i] = 1;
			dfs(d + 1, tot, ex + 1);
			b[i] = 0;
		}
		else{
			b[i] = 1;
			dfs(d + 1, tot + 1, ex);
			b[i] = 0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}