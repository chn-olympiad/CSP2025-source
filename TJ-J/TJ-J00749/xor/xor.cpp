#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 5e5 + 10;
const int maxm = 1 << 21;
int n, k, a[maxn], sum[maxn], pos[maxm], f[maxn], g[maxn];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i-1] ^ a[i];
	}
	memset(pos, -1, sizeof(pos));
	pos[0] = 0;
	for(int i = 1; i <= n; i++) {
		int kk = k ^ sum[i];
		if(pos[kk] != -1) {
			f[i] = g[pos[kk]] + 1;
		}
		g[i] = max(g[i-1], f[i]);
		pos[sum[i]] = i;
	}
	cout << g[n] << endl;
	return 0;
}

