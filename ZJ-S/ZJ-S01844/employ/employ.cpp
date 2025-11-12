#include<bits/stdc++.h>
#define max(x, y) (x > y ? x : y)

int N, M;
char s[505];
int c[505];
int a[505];
bool flag, f[505];
long long Ans, ans = 1ll;

const long long Mod = 998244353;

inline void Dfs(int t) {
	if(t > N) {
		int cnt = 0;
		for(int i = 1; i <= N; i ++) {
			if(s[i] == '0') 
				cnt ++;
			else if(cnt >= a[i]) cnt ++;
		}
		if(N - cnt >= M) Ans ++;
	}
	
	for(int i = 1; i <= N; i ++) {
		if(f[i]) continue;
		f[i] = true, a[t] = c[i];
		Dfs(t + 1);
		f[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::cin >> N >> M;
	std::cin >> s + 1;
	for(int i = 1; i <= N; i ++) std::cin >> c[i];
	for(long long i = 1; i <= N; i ++) {
		if(s[i] == '0') 
			flag = true;
		ans = ans * i % Mod;
	}
	if(M == N) {
		if(! flag) std::cout << ans;
		else std::cout << 0;
	}
	else {
		Dfs(1);
		std::cout << Ans;
	}
	return 0;
}
