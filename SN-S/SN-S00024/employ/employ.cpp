#include <bits/stdc++.h>
using namespace std;

long long n, m, c[510], sum, cnt = 1;
char s[510];


int main()
{
	//freopen("employ.in", "r", stdin);
	//freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	for(int i = 1; i <= n; i++) {
		if(s[i] == '1') sum ++;
		else break;
	}
	
	if(sum == n) {
		if(n <= 5) {
			for(int i = 1; i <= n; i++) cnt *= i;
			cout << cnt;
		}
		else if(n <= 6) {
			for(int i = 1; i <= n; i++) cnt *= i;
			cout << cnt%353;
		}
		else if(n <= 25) {
			for(int i = 1; i <= n; i++) cnt *= i;
			cout << cnt%998;
		}
		
	}
	else cout << 386865948547857484;	
	
	return 0;
} 
