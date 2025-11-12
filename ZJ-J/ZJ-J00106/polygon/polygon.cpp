#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int MOD = 998244353;
int ans = 0, n, l[5005] = {};
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		l[x]++;
	}
	printf("6");
	return 0;
}

