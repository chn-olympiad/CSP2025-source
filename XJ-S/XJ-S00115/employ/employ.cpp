#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
long long used[N], m, n, s, sum, c;

void dfs(int w){
	if (w == m + 1){
		sum++;
		return ;
	}
	for (int i = 1; i <= n; i++){
		if(!used[i]){
			used[i] = 1;
			dfs(w + 1);
			used[i] = 0;
		}
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s;
	for (int i = 1; i <= n; i++) cin >> c;
	dfs(1);
	cout << sum % 998244353;
	
	
	
	
	
	
	
	return 0;
}
