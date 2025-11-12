#include <bits/stdc++.h>
using namespace std;

bool m1;

const int N = 510;

const int p = 998244353;

int n, m, A, B;

int s[N], c[N];

void read() {
	cin >> n >> m;
	A = 1;
	B = 0;
	for(int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		s[i] = c - '0';
		if(s[i] != 1) A = 0;
		B += s[i];
	}
	for(int i = 1; i <= n; i++) cin >> c[i];
}

int fac[N];

int www(int a,int b){
	long long c = (long long)a * b % p;
	return (int)c;
} 

int zzz(int a,int b){
	long long c = (long long)a + b % p;
	return (int)c;
}

void init() {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = www(fac[i-1],i);
}

const int M = 19;

int f[M][M][(1<<18)+1];

bitset<(1<<18)+1> vis[M][M];

int dfs(int i,int k,int S) {
	if(n - k < m) return 0;
	if(i - k - 1 >= m) return fac[n - i + 1];
	if(vis[i][k][S]) return f[i][k][S];
	int ans = 0;
	for(int j = 1; j <= n; j++) {
		if((S>>(j-1))&1) continue;
		ans = zzz(ans,dfs(i+1,k+((!s[i])|(k>=c[j])),S|(1<<(j-1))));
		ans %= p;
	}
	vis[i][k][S] = 1;
	f[i][k][S] = ans;
	return ans;
}

void compute() {
	if(m > B) {
		cout << 0;
		return ;
	}
	if(n <= 18 || m == 1 || m == n) {
		cout << dfs(1,0,0);
		return ;
	}
	if(A) {
		cout << fac[n];
		return ;
	}
}

void clear() {

}

void run() {
	read();
	init();
	compute();
	clear();
}

bool m2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	run();
	return 0;
}

