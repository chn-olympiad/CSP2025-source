#include<bits/stdc++.h>
#define int long long
using namespace std; 

int n, m; 
string s; 
int c[500]; 

signed main(){
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	
	scanf("%lld%lld", &n, &m); 
	cin >> s; 
	for(int i = 1; i <= n; i++) scanf("%lld", &c[i]); 
	
	int ans = 1; 
	for(int i = 1; i <= n; i++) ans = ((ans * n) % 998244353); 
	printf("%lld", ans); 
	
	return 0; 
} 
