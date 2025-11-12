#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 5005;
const long long MOD = 998244353;
long long a[MAXN], pfx[MAXN], vis[MAXN];
long long ans = 0, mx;
int n;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

void dfs(int x, long long sum, long long mx){
	if(x > 3){
		if(sum > mx * 2)
			(ans += 1) %= MOD;
		if(x > n) return;
	}
	for(int i = st; i <= n; i++)
		if(!vis[i])
			vis[i] = 1, dfs(x + 1, sum + a[i], max(mx, a[i])),
			vis[i] = 0;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("ploygon.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++)
		a[i] = read(), pfx[i] = pfx[i - 1] + a[i];
	dfs(1, 0, 0);
	cout<< ans<< "\n";
	fclose(stdin), fclose(stdout);
	return 0;
}
