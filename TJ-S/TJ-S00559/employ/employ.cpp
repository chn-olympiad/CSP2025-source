#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int MOD = 998224353;
char c[N];
int a[N];
int n, m;

int main() {
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if(c[i] != '1') flag = false;
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if(flag) {
		int sum = 1;
		for(int i = n; i >= 1; i--) {
			sum *= i;
			sum %= MOD;
		}
		cout << sum;
		return 0;
	}
	
	return 0;
} 
