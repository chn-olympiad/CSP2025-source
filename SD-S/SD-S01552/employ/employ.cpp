#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ls (root << 1)
#define rs (root << 1 | 1)
#define mod 998244353
#define fastio ios :: sync_with_stdio(false);\
			   cin.tie(nullptr);\
			   cout.tie(nullptr);
			   
using namespace std;

const int maxn = 550;

int n, m, ans;
char s[maxn];
int c[maxn]; // 第 i 个人的耐心值 
int p[maxn]; 
bool vis[maxn];

void check(){
//	for(int i = 1; i <= n; i++){
//		cerr << p[i] << ' ';
//	}
//	cerr << endl;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '0'){
			cnt++;
		}else{
			if(c[p[i]] <= cnt) cnt++;
			
		}
	}
	ans += ((n - cnt) >= m);
}

void dfs(int x){
	if(x == n + 1){
		check();
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		p[x] = i;
		vis[i] = 1;
		dfs(x + 1);
		p[x] = 0; vis[i] = 0; 
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fastio
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i]; 
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(n <= 18){
		dfs(1);
		cout << ans % mod << endl;
		return 0;
	}else if(m == n){
		ans = 1;
		for(int i = 1; i <= n; i++){
			ans = ans * i % mod;
		}
		cout << ans << endl; 
	}
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
