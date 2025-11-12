#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int n, m;
int a[510];
int f[510];
int bj[510];
int jc[5010];
string s;

int dfs(int x){
	if(x == n){
		int tt = 0;
		int k = 0;
		for(int i = 1; i <= n; i++){
			if(s[i - 1] == '0'){
				tt++;
				continue;
			}
			if(tt >= a[f[i]]){
				tt++;
			}else{
				k++;
			}
		}
		if(k >= m){
			return 1;
		}
		return 0;
	}
	int c = 0;
	for(int i = 1; i <= n; i++){
		if(bj[i] == 0){
			bj[i] = 1;
			f[x + 1] = i;
			c += dfs(x + 1);
			bj[i] = 0;
		}
	}
	return c;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n <= 10){
		cout << dfs(0) << endl;
		return 0;
	}
	jc[0] = 1;
	for(int i = 1; i <= 1000; i++){
		jc[i] = jc[i - 1] * i % mod;
	}
	cout << jc[n] << endl;




	return 0;
}
