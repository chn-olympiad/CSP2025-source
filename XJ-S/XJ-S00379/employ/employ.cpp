#include <bits/stdc++.h>
using namespace std;
const __int128 MOD = 998244353;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n;
	cin>>n;
	__int128 sum=1;
	for(__int128 i=n; i>=1; i--){
		sum = (sum * i) % MOD;
	}
	cout << (long long)sum;
	return 0;
}
