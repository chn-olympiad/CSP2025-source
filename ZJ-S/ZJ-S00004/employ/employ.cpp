#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int MOD = 998244353;
int n,m,c[N],frac[N],p[N];
int f[(1 << 19) + 1][20];
string s;
bool isA = true;
int brute(){
	for(int i = 1;i <= n;i ++){
		p[i] = i;
	}
	int ans = 0;
	do{
		int cnt = 0,ac = 0;
		for(int i = 1;i <= n;i ++){
			if(cnt >= c[p[i]]){
				++ cnt;
				continue;
			}	
			if(s[i] == '1'){
				++ ac;
			}else{
				++ cnt;
			}
		}
		ans += (ac >= m);
	}while(next_permutation(p + 1,p + n + 1));
	return ans;
}
int popcount(int x){
	int res = 0;
	while(x){
		res ++;
		x -= (x & (-x));
	}
	return res;
}
int dp(){
	f[0][0] = 1;
	for(int i = 1;i < (1 << n);i ++){
		for(int j = 0;j <= popcount(i);j ++){
			for(int k = 1;k <= n;k ++){
				if((i >> (k - 1)) & 1){
					if(j >= 1 && c[k] <= j - 1){
						f[i][j] += f[i ^ (1 << (k - 1))][j - 1];
					}else{
						if(s[popcount(i)] == '1'){
							f[i][j] += f[i ^ (1 << (k - 1))][j];
						}else{
							if(j >= 1)
								f[i][j] += f[i ^ (1 << (k - 1))][j - 1];
						}
					}
					f[i][j] %= MOD;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= n - m;i ++){
		ans += f[(1 << n) - 1][i];
		ans %= MOD;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	frac[0] = 1;
	for(int i = 1;i <= 500;i ++){
		frac[i] = frac[i - 1] * i % MOD;
	}
	cin >> n >> m;
	cin >> s;s = " " + s;
	for(int i = 1;i <= n;i ++)isA &= (s[i] == '1');	
	for(int i = 1;i <= n;i ++){
		cin >> c[i];
	}
	if(m == n){
		int ok = isA;
		for(int i = 1;i <= n;i ++){
			if(c[i] == 0){
				ok = false;
			}
		}
		if(ok){
			cout << frac[n] << endl;
		}else{
			cout << 0 << endl;
		}
		return 0;
	}
	if(isA){
//		cout << "subtask A detected: " << endl;
//		for(int i = 1;i <= n;i ++){
//			cout << frac[i] << " ";
//		}
//		cout << endl;
		cout << frac[n] << endl;
		return 0;
	}
	cout << brute() << endl;
	return 0;
}
