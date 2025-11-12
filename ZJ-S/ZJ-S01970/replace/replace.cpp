#include <bits/stdc++.h>
const int N = 5e4 + 5;
std::string s1[N], s2[N], s3, s4;
int nxt[N], n, q, ans[2][N], out;
void init(std::string s, int n)
{
	for (int p1 = 1, p2 = 0; p1 <= n; p1++, p2++)
	{
		while (p2 != 0 && s[p2] != s[p1]) p2 = nxt[p2];
		nxt[p1] = p2;
	}
}
void kmp(std::string s, std::string t, int n, int m, int l)
{
	for (int i = 1, j = 1; i <= n; i++, j++)
	{
		if (s[i] != t[j] || j == m)
		{
			if (j != m) i--, j--;
			else ans[l][i] = 1;
			i = i + std::max(1LL, 0LL + j - nxt[j]);
			j = nxt[j];
		}
	}
}
int main()
{
	std::cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> s1[i] >> s2[i];
		s1[i] = std::to_string(32) + s1[i], s2[i] = std::to_string(32) + s2[i];
	}
	for (int i = 1; i <= q; i++)
	{
		std::cin >> s3 >> s4;
		s3 = std::to_string(0) + s3, s4 = std::to_string(0) + s4, out = 0;
		for (int j = 1; j <= n; j++)
		{
			init(s1[j], s1[j].size() - 1);
			kmp(s3, s1[j], s3.size() - 1, s1[j].size() - 1, 0);
			init(s2[j], s2[j].size() - 1);
			kmp(s4, s2[j], s4.size() - 1, s2[j].size() - 1, 1);
			int tmp = 0;
			for (int k = 1; k < s4.size(); k++)
			{
				std::cerr << k << ' ' << ans[0][k] << ' ' << ans[1][k] << '\n';
				tmp += (ans[0][k] && ans[1][k]), ans[0][k] = ans[1][k] = 0;
			}
			out += (tmp == 1);
			std::cerr << '\n';
		}
		std::cout << i << ' ' << out << '\n';
		std::cerr << '\n';
		std::cerr << '\n';
	}
}
