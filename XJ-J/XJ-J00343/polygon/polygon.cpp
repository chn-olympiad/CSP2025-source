//30 point
#include <bits/stdc++.h>

#define LL long long
 
using namespace std;

const int N = 1e4 + 10;
int n;
LL a, b, c;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	
	if(n > 3) {
		cout << n + 114;
		return 0;
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		cin >> a >> b >> c;
		if(a + b > c && b + c > a && a + c > b) cout << "1";
		else cout << "0";
	}
	return 0;
	
} 
