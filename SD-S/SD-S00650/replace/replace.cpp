#include <iostream>

using std::cin;
using std::cout;
const int N = 2e6 + 10;

std::string s1[N];
std::string s2[N];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> s1[i] >> s2[i];
	while (q--)
	{
		if (n <= 200)
		{
			std::string t1;
			std::string t2;
			cin >> t1 >> t2;
			int size = t1.size();
			int ans = 0;
			for (int i = 0; i < (int)size; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					bool f = true;
					if (i + (int)s1[j].size() > (int)t1.size())
						continue;
					std::string nw = "";
					for (int k = i; k <= i + (int)s1[j].size() - 1; ++k)
					{
						if (t1[k] != s1[j][k - i])
						{
							f = false;
							break;
						}
					}
					if (!f)
						continue;
					for (int k = 0; k < i; ++k)
						nw += t1[k];
					nw += s2[j];
					for (int k = i + (int)s1[j].size(); k < (int)t1.size(); ++k)
						nw += t1[k];
					if (nw == t2)
						ans++;
				}
			}
			cout << ans << '\n';
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}
