#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int read(){
	int x; scanf("%lld", &x); return x;
}
int n, k, res, j;
int a[N], sum[N];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(); k = read();
	for(int i = 1; i <= n; i++){
		a[i] = read();
	}
	for(int i = 1; i <= n; i++){
		int z = 0, z1 = 0;
		for(int j = i; j <= n; j++){
			z = z ^ a[j];
			if(a[i] == k) z1++;
			if(z == k){
				if(z1 > 1) res += z1;
				else res++;
				i = j;
				break;
			}
		}
	}
	printf("%lld", res);
	return 0;
}
