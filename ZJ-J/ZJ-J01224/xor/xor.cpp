#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10, V = 256;
int n, k, a[N], f[N], g[N], h[N], b[N][V];

void get1()
{
	b[1][a[1]] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 0;j < 256;j++)
			b[i][j] = (j == a[i] ? i : b[i-1][j^a[i]]);
	for (int i = 1;i <= n;i++)
		g[i] = b[i][k];
}
void get2()
{
	for (int i = 1;i <= n;i++)
	{
		int x = a[i], y = i - 1;
		while (y >= 1 && x != k) x = x ^ a[y--];
		g[i] = (x == k ? y + 1 : 0);
	}
}

int main()
{
	// double tt = clock();
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> k; int ok = 1;
	for (int i = 1;i <= n;i++)
		cin >> a[i], ok = ok && (a[i] < 256);
	if (ok) get1();
	else get2();
	for (int i = 1;i <= n;i++)
		f[i] = (g[i] == 0 ? 0 : h[g[i]-1] + 1), h[i] = max(h[i-1], f[i]);
	cout << h[n] << "\n";
	/*
	for (int i = 1;i <= n;i++)
		cout << f[i] << " " << g[i] << " " << h[i] << "\n";
	*/
	// double ttt = clock();
	// cout << ttt - tt << "\n";
	// cout << "size = " << (sizeof(a) + sizeof(b) + sizeof(f) + sizeof(g) + sizeof(h)) / 1024.0 / 1024.0 << "\n";
	return 0;
}