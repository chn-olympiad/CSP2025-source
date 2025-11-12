#include<bits/stdc++.h>
using namespace std;

const int N = 550, MOD = 998244353;
int n, m, ans, k;
char s[N];
int c[N];
int vis[N];
int v[N][N];
bool flag[N][N];

int f(int day, int sum){
	if(day > n){
		return sum >= m ? 1 : 0;
	}
	
	if(flag[day][sum]) return v[day][sum];
	
	flag[day][sum] = true;
	int fail = day - sum - 1;
	
	if(fail < k)
		v[day][sum] = (v[day][sum] + f(day + 1, sum) * (k - fail) % MOD) % MOD;
		
	if(n - sum > k)
		v[day][sum] = (v[day][sum] + f(day + 1, sum + 1) * (n - sum - k) % MOD) % MOD;
		
	return v[day][sum];
}

void dfs(int day, int sum){

	if(day > n){
		if(sum >= m)
			ans = (ans + 1) % MOD;
		return;
	}
	
	for(int i = 1; i <= n; i ++){
		if(vis[i]) continue;
		vis[i] = 1;
		if(c[i] > day - sum - 1 && s[day] == '1')
			dfs(day + 1, sum + 1);
		else
			dfs(day + 1, sum);
		vis[i] = 0;
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++)
		cin >> s[i];

	for(int i = 1; i <= n; i ++){
		cin >> c[i];
		if(c[i] < 0) k ++;
	}
	
	if(n > 18){
		cout << f(1, 0) << endl;
		return 0;
	}
	
	dfs(1, 0);
	
	cout << ans << endl;

	return 0;
}