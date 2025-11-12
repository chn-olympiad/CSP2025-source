#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k, ans;
ll a[11][10001];
ll c[11];
struct tree{
	ll u, v, w;
	
}t[1000001];

int city[10001];
int ready[10001], len = 0;

ll dfs(int num, int w, int ready[], int city[]){
	for(int i = 1 ;i <= num; i++){
		
	}
	
	return w;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int A = 1;
	ans = 0;
	memset(city, 0, sizeof(city));
	
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i ++){
		cin >> t.u[i] >> t.v[i] >> t.w[i];
	}
	for (ll i = 1; i <= k ; i++){
		cin >> c[i];
		for (ll j = 1; j <= n; j++){
			cin >> a[i][j];
		}
		if (c[i]) A = 0;
	}
	
	
	if (k == 0){
		len = 0;
		city[1] = 1;
		ready[++len] = 1;
		ans = dfs(1,0, ready, city);
		cout << ans << endl;
	}
	else if (A){
		
	}
	else {
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
