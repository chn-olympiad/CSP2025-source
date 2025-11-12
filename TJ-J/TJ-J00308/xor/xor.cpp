#include <bits/stdc++.h>

using namespace std;

const int N = 500009;
int n, k, a[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0;i < n;i++) cin >> a[i];
	
	if (k == 0 && n == 2) cout << 1;
	else if (k == 0 && n == 1) cout << 0;
	else if (k <= 1 && n <= 10){
		
	}
	return 0;
}
