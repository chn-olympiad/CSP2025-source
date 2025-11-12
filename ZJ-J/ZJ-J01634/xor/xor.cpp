#include <bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0');ch = getchar();}
	return sum * p;
}
const int N = 5e5 + 10, M = 5e6 + 10;
int n, k, a[N], f[N], g[M], pre[N];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = re(), k = re();
	for(int i = 1; i <= n; i++) a[i] = re(), pre[i] = pre[i - 1] ^ a[i];
	
	int ans = 0;
	for(int i = 1; i <= 5e6; i++) g[i] = -1; 
	for(int i = 1; i <= n; i++)
	{
		f[i] = max(f[i - 1], g[(int)(pre[i] ^ k)] + 1);
		g[pre[i]] = max(f[i], g[pre[i]]);
		ans = max(ans, f[i]); 
	}
	cout << ans;
	return 0;
}
