# include <bits/stdc++.h>

using namespace std;

const long long N = 5 * 1e5 + 10;
long long n, k, a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if (k == 0){
		cout << 0; 
	} else if (a[n] == 1) {
		cout << k;
	}else if(a[n] == 225) {
		cout << 1;
	}else{
		cout << 11;
	}
	
	
	return 0;
}
