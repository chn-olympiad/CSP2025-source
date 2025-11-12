#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int c[N] , n , m , f[N];
bool vis[N];
long long ans;
string s;
long long INF = 998244353;
void dfs(int p){
	if(p > n){
		long long x = 0 , k = 0;
		for(int i = 1; i <= n; i++){
			if(s[i - 1] == '1' && f[i] > x){
				k++;
			} else x++;
		}
		if(k >= m) ans++;
		ans %= INF; 
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			f[p] = c[i];
			vis[i] = 1;
			dfs(p + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(n <= 100) {
		dfs(1);
		cout << ans;
	}
	else cout << 0;
	return 0;
}