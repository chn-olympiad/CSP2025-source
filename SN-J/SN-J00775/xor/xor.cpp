// xianshitieyizhongxue wangzhengqinghe 13891989834 chusan
#include<bits/stdc++.h>
#define fir first
#define sec second
#define ll long long
#define ull unsigned ll
#define ldb long double
#define inf 1000000000
#define infll 1000000000000000000ll
#define maxn 500000
#define maxa 1048576
using namespace std;
int aqx, n, k, A[maxn + 10], Q[maxn + 10], T[maxa + 10], F[maxn + 10];
void init()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	return;
}
void solve()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {cin >> A[i]; Q[i] = (Q[i - 1] ^ A[i]);}
	for (int i = 1;i <= maxa;i++) T[i] = -inf;
	for (int i = 1;i <= n;i++)
	{
		F[i] = max(F[i - 1], T[Q[i] ^ k] + 1);
		T[Q[i]] = max(T[Q[i]], F[i]);
	}
	cout << F[n] << "\n";
	return;
}
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	init();
	aqx = 1;
	while (aqx--) solve();
	return 0;
}
