#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e4 + 10;
inline int read(){
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int n, m, p[MAXN], c[MAXN];
char s[MAXN];
ll ans = 0;
bool vis[MAXN];

void dfs(int id){
	if(id == n){
//		for(int i = 1; i <= n; i++)
//			cout << p[i] << ' ';
//		cout << endl;
		int cnt = 0, az = 0;
		for(int i = 1; i <= n; i++){
			int x = p[i];
			if(c[x] > cnt && s[i] == '1'){
				az++;
			}else cnt++;
//			cout << x << ' ' <<  az << ' ' << cnt << endl;
		}
//		cout << az << endl;
		if(az >= m) ans++;
		return ;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = true;
		p[id+1] = i;
		dfs(id+1);
		vis[i] = false;
	}
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(0);
	cout << ans;
	return 0;
}
