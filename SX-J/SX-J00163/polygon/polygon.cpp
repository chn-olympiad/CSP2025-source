#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], s[5005], sum = 0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
	}
	for(int l = 1; l <= n - 3; l++){
		for(int r = l + 2; r <= n; r++){
			int x = s[r] - s[l - 1];
			if(x > a[r] * 2){
				sum++;
			}
		}
	}
	cout << sum % MOD;
	return 0;
}
//AC