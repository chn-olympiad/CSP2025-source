#include<bits/stdc++.h>
using namespace std;

int n, k, a[500005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << n % 2 == 0? n / 2:n;
	
	return 0;
} 
