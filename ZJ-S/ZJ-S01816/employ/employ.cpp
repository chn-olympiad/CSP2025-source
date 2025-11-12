#include<bits/stdc++.h>
using namespace std;
#define CSP
#define mod 998244353
int n, h, x, y;
string s;
int c[510];
int jc(int u){
	int sum = 1;
	for (int v = 2; v <= u; v++){
		sum = sum * v % mod;
	}
	return sum % mod;
}
int main(){
#ifdef CSP
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	cin >> n >> h;
	x = n;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] <= y)x--, y++;
	} 
	cout << (jc(x) % mod + mod) % mod;
	return 0;
}
