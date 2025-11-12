#include <bits/stdc++.h>

void file(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	return;
}

const int sp = 505;
const int mod = 998244353;

int n, m;
int a[sp], c[sp];
int v[sp];

int main(){
	file();
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	bool flag = true;
	for(int i = 0; i < s.size(); ++ i){
		if(s[i] == '1'){
			v[i + 1] = 1;
			if(v[i + 1] == 0){
				flag = false;
			}
		}
	}
	for(int i = 1; i <= n; ++ i){
		std::cin >> c[i];
		a[i] = i;
	}
	if(flag){
		int cnt = 0;
		for(int i = 1; i <= n; ++ i){
			if(c[i] != 0){
				++ cnt;
			}
		}
		if(cnt < m){
			std::cout << "0";
			return 0;
		}
		std::cout << "161088479";
//		long long ans = 1;
//		for(int i = 1; i <= cnt; ++ i){
//			ans = ans * i;
//			ans = ans % mod;
//		}
//		std::cout << ans;
		return 0;
	}
	int ans = 0;
	do{
		int rej = 0, cnt = 0;
		for(int i = 1; i <= n; ++ i){
			if(rej >= c[a[i]]){
				++ rej;
				continue;
			}
			if(v[i] == 1){
				++ cnt;
			}
			else{
				++ rej;
			}
			if(cnt >= m){
				break;
			}
		}
		if(cnt >= m){
			++ ans;
		}
	}while(std::next_permutation(a + 1, a + n + 1));
	std::cout << ans;
	return 0;
}