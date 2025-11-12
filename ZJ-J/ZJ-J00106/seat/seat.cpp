#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
int ans = 1, n, m, c, r, t;//m&c¡–, n&r–– 
int a[10] = {};
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 2; i <= m * n; i++){
		int x;
		scanf("%d", &x);
		if(x > t) ans++;
	}
	c = (ans - 1) / n + 1;
	r = ans - (c - 1) * n;
	if(c % 2 == 0) r = n + 1 - r;
	printf("%d %d", c, r);
	return 0;
}

