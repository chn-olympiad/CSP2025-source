#include<bits/stdc++.h>
using namespace std;
const int maxn = 505; 
const int mod = 998244353; int c[maxn];

int qc(int a){
	int s = 1;
	for(int i = 2; i <= a; ++i){
		s *= i; s %= mod;
	}
	return s % mod;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, b = 0; cin >> n >> m;
	string s; cin >> s;
	int sum = 0;
	for(int i = 1; i <= n; ++i){
		cin >> c[i];
		if(c[i] == 0) b = 1;
	}
	if(s.find('1') == -1){
		cout << 0 << endl;
		return 0;
	}
	if(m == n){
		if(b == 1 || s.find('0') != -1) cout << 0 << endl;
		else cout << qc(n) << endl;
		return 0;
	}
	if(s.find('0') == -1){
		cout << qc(n) << endl;
	}
	return 0;
}
