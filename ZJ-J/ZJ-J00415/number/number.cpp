#include <bits/stdc++.h>
using namespace std; 
string s; 
long long n, a[(long long)1e6 + 10], top; 
int main () {
	ios :: sync_with_stdio(0); 
	cin.tie (0); cout.tie(0); 
	freopen("number.in", "r", stdin); 
	freopen("number.out", "w", stdout); 
	cin >> s; 
	n = s.size(); 
	for(int i = 0; i < n; ++ i) 
		if(s[i] >= '0' && s[i] <= '9') a[++ top] = s[i] - '0'; 
	sort(a + 1, a + top + 1); 
	for(int i = top; i >= 1; -- i) 
		cout << a[i]; 
	return 0; 
}
