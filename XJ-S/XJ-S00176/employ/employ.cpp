#include<bits/stdc++.h> 

using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	long long sum = 1;
	for(int i = 1; i <= n; i++) {
		sum *=i;
	}
	cout << sum % 998244353;
	return 0;
} 
