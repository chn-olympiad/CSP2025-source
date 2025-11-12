#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 500, MOD = 998244353;

int n, m, ans = 0;
char x;
int c[N], f[N], p[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if(m == n){
		int u = 0; 
		for(int i = 1; i <= n; i ++){
			cin >> x;
			if(x == '1') u ++;
		}
		if(u < n){
			puts("0");
			return 0;
		}
		u = 1;
		for(int i = 1; i <= n; i ++)
			u = (ll)u * i % MOD;
		cout << u;
		return 0;
	}
	if(n <= 18){
		for(int i = 1; i <= n; i ++){
			cin >> x;
			f[i] = x - '0';
		}
		for(int i = 1; i <= n; i ++){
			cin >> c[i];
			p[i] = i;
		}
		do{
			int cnt = 0;
			for(int i = 1; i <= n; i ++)
				if(cnt >= c[p[i]] || f[i] == 0)
					cnt ++;
			if(n - cnt >= m) ans ++;
		}while(next_permutation(p + 1, p + n + 1));
		cout << ans;
		return 0;
	}
	puts("0");
	return 0;
}