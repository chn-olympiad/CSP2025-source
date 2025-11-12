#include <random>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;
constexpr int MAXN = 2e5 + 5, MAXQ = 2e5 + 5, MAXL = 5e6 + 5;
constexpr ULL HMOD = 1e9L + 7, HJ = 131;
int n, q;

ULL qpow(ULL x, ULL y)
{
	ULL res = 1;
	while (y)
	{
		if (y & 1) (res *= x) %= HMOD;
		(x *= x) %= HMOD, y >>= 1;
	}
	return res;
}
inline ULL inv(ULL x) { return qpow(x, HMOD - 2); }

ULL rh['z' + 5];
ULL qwq[MAXL], awa[MAXL];

struct Michael{
	string str;
	vector<ULL> hs;
	void genHash()
	{
		hs.resize(str.length());
		for (int j = 0; j < (int)str.length(); j++)
			hs[j] = ((j ? hs[j - 1] : 0) + /*rh[(int)str[j]]*/str[j] * qwq[j]) % HMOD;
		return;
	}
	inline ULL getHash(int l, int r)
	{
		if (l == r + 1) return 0;
		return ((hs[r] - (l ? hs[l - 1] : 0)) * awa[l] % HMOD + HMOD) % HMOD;
	}
}s[MAXN], sn[MAXN], t[MAXQ], tn[MAXQ];

namespace BF{

void Solve()
{
	for (int i = 1; i <= q; i++)
	{
		cin >> t[i].str >> tn[i].str;
		t[i].genHash(), tn[i].genHash();
		
		int ans = 0;
		for (int j = 0; j < (int)t[i].str.length(); j++)
		{
			for (int k = 1; k <= n; k++)
			{
				int len = s[k].str.length();
				if (j - len + 1 >= 0
					&& t[i].getHash(j - len + 1, j) == s[k].getHash(0, len - 1)
					&& tn[i].getHash(j - len + 1, j) == sn[k].getHash(0, len - 1)
					&& t[i].getHash(0, j - len) == tn[i].getHash(0, j - len)
					&& t[i].getHash(j + 1, t[i].str.length() - 1) == tn[i].getHash(j + 1, t[i].str.length() - 1)
				) ans++;
			}
		}
		
		cout << ans << '\n';
	}
}

} //namespace BF

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
//	mt19937_64 engine(random_device{}());
//	for (char ch = 'a'; ch <= 'z'; ch++)
//		rh[(int)ch] = engine();
	qwq[0] = 1, awa[0] = 1;
	qwq[1] = HJ, awa[1] = inv(HJ);
	for (int i = 2; i < MAXL; i++)
	{
		qwq[i] = qwq[i - 1] * qwq[1] % HMOD;
		awa[i] = awa[i - 1] * awa[1] % HMOD;
	}
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].str >> sn[i].str;
		s[i].genHash(), sn[i].genHash();
	}
	
//	if (q == 1) SFA::Solve();
//	else BF::Solve();
	BF::Solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/