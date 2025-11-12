#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n = 0, q = 0;
pair<string, string> s[maxn];

inline void fastread(int& x)
{
	x = 0;
	char c = getchar();
	while(!isdigit(c))
		c = getchar();
	while(isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c - '0');
		c = getchar();
	}
}
inline void fastprint(int x)
{
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	fastread(n);
	fastread(q);
	for(int i = 1; i <= n; ++i)
		cin >> s[i].first >> s[i].second;
	for(int i = 1; i <= q; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		vector<string> answers;
		int cnt = 0;
		
		for(int i = 0; i < s1.length(); ++i)
			for(int l = 1; i + l - 1 < s1.length(); ++l)
			{
				string ss = s1.substr(i, l), pre = s1.substr(0, i), post = s1.substr(i + l);
				for(int j = 1; j <= n; ++j)
					if(ss == s[j].first && pre + s[j].second + post == s2)
						++cnt;
			}
		fastprint(cnt);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
