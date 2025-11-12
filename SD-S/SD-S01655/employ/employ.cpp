#include <bits/stdc++.h>
#define int long long
using namespace std;
char s[510];
int c[510];
bool bo[510];
int n,m;
int nw[510];
int ans;
void dfs(int x){
	if(x == n+1){
		int fangqi = 0;
		for(int i = 1; i <= n; i++){
			if(fangqi >= c[nw[i]] || s[i] == '0') fangqi++; 
		}
		if(n-fangqi>=m){
			ans++;
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!bo[i]){
			bo[i] = 1;
			nw[x] = i;
			dfs(x+1);
			bo[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	std::ios::sync_with_stdio(0); 
	
	cin >> n >> m;
	cin >> s+1;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(m==n){
		sort(c+1,c+n+1);
		for(int i = 1; i <= n; i++){
			if(fangqi >= c[i] || s[i] == '0'){
				cout << 0;
				return 0;
			} 
		}
		cout << 1;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
} 
