#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
int c[501], a[501], ans;
bool f[501];
void dfs(int x){
	if(x == n + 1){
		int sum = 0, sum2 = 0;
		for(int i = 1;i <= n;i++){
			if(s[i - 1] == '0' || sum >= c[a[i]])sum++;
			else{
				sum2++;
			}
		}
		if(sum2 >= m)ans++;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!f[i]){
			f[i] = 1;
			a[x] = i;
			dfs(x + 1);
			f[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	dfs(1);
	cout << ans;
	return 0;
} 