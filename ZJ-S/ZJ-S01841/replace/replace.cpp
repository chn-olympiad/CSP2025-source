#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

const int N = 200010, M = 5000010, mod = 133337, mm = 137;

int n, m;
string s1[N], s2[N];
int l[N];
ull hash1[N], hash2[N], haash[N];
unordered_map<ull, int> mp;

ull qp(ull a, int b)
{
	ull res = 1;
	while (b)
	{
		if (b & 1) res = res * a;
		a *= a;
		b >>= 1;
	}
	return res;
}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= n; i ++ )
	{
		l[i] = s1[i].size();
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];
		for (int j = 1; j <= l[i]; j ++ )
			hash1[i] = hash1[i] * mod + s1[i][j];
		for (int j = 1; j <= l[i]; j ++ )
			hash2[i] = hash2[i] * mod + s2[i][j];
		haash[i] = hash2[i] * mm - hash1[i];
		mp[haash[i]] ++ ;
	}

	for (int i = 1; i <= m; i ++ )
	{
		string a, b;
		cin >> a >> b;
		int st = 0, ed = 0, L = a.size();
		a = " " + a, b = " " + b;
		for (int j = 1; j <= L; j ++ )
			if (a[j] != b[j])
			{
				st = j;
				break;
			}
		for (int j = L; j; j -- )
			if (a[j] != b[j])
			{
				ed = j;
				break;
			}
		ull hsh1 = 0, hsh2 = 0, hsh = 0;
		for (int j = st; j <= ed; j ++ )
			hsh1 = hsh1 * mod + a[j];
		for (int j = st; j <= ed; j ++ )
			hsh2 = hsh2 * mod + b[j];
		ull hsh1_ = hsh1, hsh2_ = hsh2;
		int res = 0, LL = 0, RR = 0;
		for (int j = st - 1; j; j -- ) 
		{
			hsh1_ = hsh1_ + qp(mod, ed - st + 2) * a[j];
			hsh2_ = hsh2_ + qp(mod, ed - st + 2) * b[j];
			hsh = hsh2_ * mm - hsh1_ * mm;
			if (!mp.count(hsh))
			{
				LL = j + 1;
				break;
			}
		}
		hsh1_ = hsh1, hsh2_ = hsh2;
		for (int j = ed + 1; j <= L; j ++ ) 
		{
			hsh1_ = hsh1_ * mod + a[j];
			hsh2_ = hsh2_ * mod + b[j];
			hsh = hsh2_ * mm - hsh1_ * mm;
			if (!mp.count(hsh))
			{
				RR = j - 1;
				break;
			}
		}
		hsh1_ = hsh1, hsh2_ = hsh2;
		for (int z = st; z; z -- )
		{
			if (z < st) hsh1_ = hsh1_ + qp(mod, ed - z) * a[z],
						hsh2_ = hsh2_ + qp(mod, ed - z) * b[z];
			hsh1 = hsh1_, hsh2 = hsh2_;
			for (int y = ed; y <= L; y ++ )
			{
				if (y > ed) hsh1 = hsh1 * mod + a[y], hsh2 = hsh2 * mod + b[y];
				hsh = hsh2 * mm - hsh1;
				if (mp.count(hsh)) res += mp[hsh];
			}
		}
		
		cout << res << '\n';
	}
	
	return 0;
}
