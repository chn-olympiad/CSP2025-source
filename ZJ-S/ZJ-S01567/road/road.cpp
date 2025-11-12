#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 10;
ll n, m, c, cnt, ans, sum, minn = 1000000000, w[20], f[N];
bool vis[N];

ll find(ll x){
	if(x == f[x]) return x;
	return f[x] = find(f[x]);
}
struct node{
	ll u, v, w;
} a[N];

bool cmp(node x, node y){
	//if(x.a == y.a) return x.b > y.b;
	return x.w < y.w;
}

void dfs(ll t){
	if(t > c) {
		ans = sum;
		//cout << ans << " ";
		for(int i = 1; i <= n + c; i++)
			f[i] = i;
		for(int i = 1; i <= cnt; i++){
			if(vis[a[i].u]) continue;
			ll x = find(a[i].u), y = find(a[i].v), w = a[i].w;
			if(x == y) continue;
			f[x] = y;
			ans += w;
			//cout << a[i].u << " " << a[i].v << " " << a[i].w << "    ";
		}
		//cout << "\n";
		//cout << ans << " ";
		minn = min(minn, ans);
		return ;
	}
	dfs(t + 1);
	vis[n + t] = 1;
	sum -= w[t];
	dfs(t + 1);
	sum += w[t];
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> c;
	for(int i = 1; i <= m; i++){
		cnt++;
		cin >> a[cnt].u >> a[cnt].v >> a[cnt].w;
		//cout << a[cnt].u << " " << a[cnt].v << "\n";
	}
	/*for(int i = 1; i <= c; i++){
		
	}
	*/
	for(int i = 1; i <= c; i++){
		cin >> w[i];
		sum += w[i];
		for(int j = 1 ; j <= n; j++){
			cnt++;
			cin >> a[cnt].w;
			a[cnt].u = n + i;
			a[cnt].v = j;
		}
	}
		
	
	//for(int i = 1; i <= cnt; i++)
		
	sort(a + 1, a + cnt + 1, cmp);
	
	dfs(1);
	cout << minn;
	return 0;
}
