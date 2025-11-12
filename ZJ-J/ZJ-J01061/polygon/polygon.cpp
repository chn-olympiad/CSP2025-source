#include<bits/stdc++.h>
using namespace std;
//using PII = pair<int, int>;
int a[100005];
int n;
//PII b[100005];
bool check_A(){
//	return 1;
	for(int i=1;i<=n;i++) if(a[i] != 1) return 0;
	return 1;
}
long long quwickpow(int a, int b){
	if(a == 1 or b == 1 or a == 0) return a;
	long long s = quwickpow(a, b / 2);
	if(b & 1){ 
		return s * s % 998244353 * a % 998244353;
	}else{
		return s * s % 998244353;
	}
}
const int mod = 998244353;

void slove(){
	int ans = 0;
	for(int i=1;i<(1<<n);i++) {
		int sum = 0;
		int mx = 0;
		int cnt = 0;
		for(int j=1;j<=n;j++){ 
			if(i & (1 << j-1)){
				sum += a[j];
				mx = max(mx, a[j]);
				++cnt;
			}
		}
		if(cnt <= 2) continue;
		if(sum > 2 * mx) ans++, ans %= 998244353;
	}
	cout << ans << endl;
}
void solveB(){
	
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	// TLE 50pts Origined Testcase Progamming
	cin >> n;
	if(n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(check_A()){ // 24 pts
		cout << ((quwickpow(2, n) - 1 - n - n*(n-1) / 2) % mod + mod) % mod;
		return 0; 
	} 
	if(n <= 20) slove();  // n <= 20, O(n2^n) 40pts (2*10^7)
	else if(n <= 500) solveB(); // O(n^3)?
	return 0;
} 
/*
--- How do you spell sh*t?
--- D-E-L-I-C-I-O-U-S, delicious.








I think it's a dynamic progamming but I can't write it.
npm,CCF, China Coin Factory
*/
