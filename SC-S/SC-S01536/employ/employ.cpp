#include "bits/stdc++.h"
using namespace std;

#define int long long
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
const int N = 500 + 5, K = 998244353;
int n, m;
string s;
int c[N];

int qmi(int a, int b, int c = K)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return res;
}

int frac[N], inv[N];
void init(int n = 500)
{
	frac[0] = 1;
	for (int i = 1; i <= n; ++ i) frac[i] = frac[i - 1] * i % K;
	inv[n] = qmi(frac[n], K - 2, K);
	for (int i = n - 1; i >= 0; -- i) inv[i] = inv[i + 1] * (i + 1) % K;
}

int A(int n, int m)
{
	return frac[n] * inv[n - m] % K;
}

int C(int n, int m)
{
	return frac[n] * inv[m] % K * inv[n - m] % K;
}

signed main()
{
	file(employ);
	init();
	cin >> n >> m;
	cin >> s;
	s = string(" ") + s;
	for (int i = 1; i <= n; ++ i) cin >> c[i];
	
	if (m == 1)
	{
		int pos = 0;
		for (int i = 1; i <= n; ++ i) 
		{
			pos = i;
			if (s[i] != '0') break;
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++ i)
			cnt += (c[i] >= pos);
		cout << C(cnt, 1) * A(n - 1, n - 1) % K << '\n';
	}
	
	else 
	{
		vector<int> seq;
		int allow = 0;
		for (int i = 1; i <= n; ++ i) seq.push_back(i);
		do {
			int deny = 0;
			for (int i = 1; i <= n; ++ i)
			{
				if (deny >= c[seq[i - 1]] || s[i] == '0') 
				{
					deny ++;
					continue;
				}
				if (i - deny == m) 
				{
					allow ++;
					break;
				}
			}
		} while(next_permutation(seq.begin(), seq.end()));
		
		cout << allow << '\n';
	}
	
	return 0;
}