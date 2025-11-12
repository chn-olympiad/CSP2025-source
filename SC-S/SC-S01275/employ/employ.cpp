#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
using namespace std;
ll n, m, maxn = -1;
ll res, cnt;
string s;
ll p[505];
ll arr[505];
bool vis[505];
ll qpl[1005][505];
set<string> st;
void dfs1(ll x){
	if(x == n + 1){
		string t = "0";
		ll bf = st.size();
		for(int i = 1; i <= n; i ++){
			t = t + (char)(arr[i]);
		}
		st.insert(t);
		if(st.size() == bf) return;
		cnt ++;
		for(int i = 1; i <= n; i ++){
			qpl[cnt][i] = arr[i];
		}
		return;
	}
	for(int i = 1; i <= n; i ++){
		if(vis[i]) continue;
		vis[i] = true;
		arr[x] = p[i];
		dfs1(x + 1);
		arr[x] = 0;
		vis[i] = false;
	}
}
void dfs(ll i, ll x, ll out, ll a, ll b){
	if(n - out < m) return;
//	cout << x << " " << out << " " << a << " " << b << " " << i << endl;
	if(x == n && (n - out) >= m){
		res ++;
		return;
	}
	if(out >= qpl[i][x]){
		dfs(i, x + 1, out + 1, a, b);
	} else {
		if(a > 0) dfs(i, x + 1, out + 1, a - 1, b);
		if(b > 0) dfs(i, x + 1, out, a, b - 1);
	}
	return;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	cin >> s;
	ll len = s.size();
	ll a = 0, b = 0;
	for(int i = 0; i < len; i ++){
		if(s[i] == '0') b ++;
		else a ++;
	}
	for(int i = 1; i <= n; i ++){
		cin >> p[i];
	}
	dfs1(1);
	for(int i = 1; i <= cnt; i ++){
		res = 0;
		dfs(i, 1, 0, a, b);
		maxn = max(maxn, res);
	}
	cout << maxn;
	return 0;
}