#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 1;
int n, a[maxn];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d%d", &n, &a[1], &a[2]);
	for (int i = 3; i <= n; i++){
		a[i] = a[i - 1] + a[i - 2];
		printf("%d ", a[i]);
	}
	return 0;
} 
