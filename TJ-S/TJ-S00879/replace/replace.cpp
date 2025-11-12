#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9 + 7,base = 251,n,q,has[2001][2][2001],len[2001][2],has1[2001][2];
string s[2001][2];
int kasumi(int a,int b){
	int res = 1;
	while (b){
		if (b & 1){
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return res;
}
int mo(int a){
	return ((a % mod) + mod) % mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
		len[i][0] = s[i][0].length();
		len[i][1] = s[i][1].length();
		for (int j = 1;j <= len[i][0];j++){
			has[i][0][j] = ((has[i][0][j - 1] * base) % mod + (s[i][0][j - 1] - 'a')) % mod;
		}
		for (int j = 1;j <= len[i][1];j++){
			has[i][1][j] = ((has[i][1][j - 1] * base) % mod + (s[i][1][j - 1] - 'a')) % mod;
		}
	}
	for (int i = 1;i <= q;i++){
		string ss1,ss2;
		cin >> ss1 >> ss2;
		int len1 = ss1.length(),ans = 0;
		for (int j = 1;j <= len1;j++){
			has1[j][0] = ((has1[j - 1][0] * base) % mod + (ss1[j - 1] - 'a')) % mod;
		}
		for (int j = 1;j <= len1;j++){
			has1[j][1] = ((has1[j - 1][1] * base) % mod + (ss2[j - 1] - 'a')) % mod;
		}
		for (int j = 1;j <= len1;j++){
			for (int k = 1;k <= n;k++){
				if (j + len[k][0] - 1 <= len1){
					if (has1[j - 1][0] == has1[j - 1][1] && mo(has1[len1][0] - mo(has1[j + len[k][0] - 1][0] * kasumi(base,len1 - j - len[k][0] + 1))) == mo(has1[len1][1] - mo(has1[j + len[k][1] - 1][1] * kasumi(base,len1 - j - len[k][1] + 1)))){
						if (mo(has1[j + len[k][0] - 1][0] - mo(has1[j - 1][0] * kasumi(base,len[k][0]))) == has[k][0][len[k][0]] && mo(has1[j + len[k][0] - 1][1] - mo(has1[j - 1][1] * kasumi(base,len[k][0]))) == has[k][1][len[k][0]]){
							ans++;
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
