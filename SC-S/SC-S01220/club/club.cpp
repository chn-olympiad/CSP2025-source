#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
int T, n, ans;
int a[N][3], mx[N], _mx[N], id[N], _id[N], h[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q[3];
inline void solve(){
	ans = 0;
	for(int i = 0; i < 3; ++i)
		while(!Q[i].empty())
			Q[i].pop();
	n = read();
	for(int i = 1; i <= n; ++i){
		mx[i] = _mx[i] = id[i] = _id[i] = 0;
		for(int j = 0; j < 3; ++j){
			a[i][j] = read();
			if(a[i][j] > mx[i])
				mx[i] = a[i][j], id[i] = j;
		}
		for(int j = 0; j < 3; ++j){
			if(j == id[i])
				continue;
			if(a[i][j] > _mx[i])
				_mx[i] = a[i][j], _id[i] = j;
		}
		h[i] = mx[i] - _mx[i];
	}
	for(int i = 1; i <= n; ++i){
		if((int)Q[id[i]].size() + 1 > (n >> 1)){
			auto t = Q[id[i]].top();
			if(t.fi < h[i]){
				Q[id[i]].pop();
				Q[id[i]].push({h[i], i});
				Q[_id[t.se]].push({h[i], i});
				ans += mx[i] - mx[t.se] + _mx[t.se];
			}
			else{
				Q[_id[i]].push({h[i], i});
				ans += _mx[i];
			}
		}
		else{
			Q[id[i]].push({h[i], i});
			ans += mx[i];
		}
	}
	write(ans);
	putchar('\n');
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--)
		solve();
	return 0;
}