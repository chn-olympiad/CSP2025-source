#include<bits/stdc++.h>
using namespace std;

int n, m, ans, a[510], b[510], c[510];
const int P = 998244353;
string s;

inline void dfs(int p){
	if(p == n + 1){
		int t = 0, v = 0;
		for(int i = 1; i <= n; i++){
			if(t >= c[a[i]]){
				t++;
				continue;
			}
			if(s[i] == '1'){
				v++;
			}else{
				t++;
			}
		}
		if(v >= m){
			ans++;
			ans %= P;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(b[i] == 0){
			b[i] = 1;
			a[p] = i;
			dfs(p + 1);
			b[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	dfs(1);
	if(ans == -1){
		cout << "You have on egg!!!\n";
	}
	cout << ans << "\n";
	return 0;
}
