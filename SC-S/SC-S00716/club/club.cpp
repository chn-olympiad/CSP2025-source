#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;

long long n;
long long a[N][5], ans;
bool cmp(long long x, long long y)
{	
	return x > y;
}
void dfs(long long u, long long x, long long y, long long z, long long cnt)
{
	if(u == n + 1){
		ans = max(ans, cnt);
		return;
	}
	if(x + 1 <= n / 2){
		dfs(u + 1, x + 1, y, z, cnt + a[u][1]);
	}
	if(y + 1 <= n / 2){
		dfs(u + 1, x, y + 1, z, cnt + a[u][2]);
	}
	if(z + 1 <= n / 2){
		dfs(u + 1, x, y, z + 1, cnt + a[u][3]);
	}
}
void solve()
{
	ans = 0;
	bool flagA = true, flagB = true;
	cin >> n;
	for(long long i = 1; i <= n; i ++ ){
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][3] != 0) flagA = flagB = false;
		if(a[i][2] != 0) flagA = false;
	}
	if(flagA){
		vector<long long> p;
		for(long long i = 1; i <= n; i ++ ){
			p.push_back(a[i][1]);
		}
		sort(p.begin(), p.end(), cmp);
		for(long long i = 0; i < n / 2; i ++ ){
			ans += p[i];
		}
		cout << ans << endl;
	}else{
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
	}

}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long T; cin >> T;
	while(T -- ) solve();
	return 0;
}