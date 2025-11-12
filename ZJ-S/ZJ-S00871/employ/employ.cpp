#include<bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, m, a[510];
char s[510];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = n;
	for(int i = n - 1; i > n - m; i--)
		ans *= i;
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
