#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

const int N = 5e2 + 10;
const int P = 1e9 + 7;
const int MOD = 998244353;

int n, m;

int s[N], c[N];

int mul(int n){
	int res = 1;
	for(int i=1; i<=n; i++){
		res *= i;
		res %= MOD;
	}
	return res;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	bool flag = 1;
	for(int i=1; i<=n; i++){
		char ch;
		cin >> ch;
		if(ch == '1') s[i] = 1;
		else{
			s[i] = 0;
			flag = 0;
		}
	}
	int maxn = -1;
	for(int i=1; i<=n; i++){
		cin >> c[i];
		maxn = max(maxn, c[i]);
	}
	
	if(flag){
		int sum = 0;
		for(int i=1; i<=n; i++){
			if(c[i] == 0) sum++;
		}
		if(sum + m > n){
			cout << 0 << endl;
			return 0; 
		}
	}
	
	if(m == 1){
		int pos = 1;
		while(s[pos] == 0){
			pos++;
		}
		pos--;
//		cout << pos << endl;
		int sum = 0;
		for(int i=1; i<=n; i++){
			if(c[i] > pos){
				sum++;
			}
		}
		cout << sum * mul(n-1) % MOD << endl;
		return 0;
	}
	
	cout << 0 << endl;
	return 0;
}

