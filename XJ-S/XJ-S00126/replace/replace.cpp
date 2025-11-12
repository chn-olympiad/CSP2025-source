#include <bits/stdc++.h>
using namespace std;
struct Two
{
	string a1;
	string a2;
} Two s[200005], ques[200005];
int n, q;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i].a1 >> s[i].a2;
	for (int i = 1; i <= q; i++)
	{
		cin >> ques[i].a1 >> ques[i].a2;
		for (int j = 1; j <= n; j++)
		{
			if (!(ques[i].a1 == s[j].a1 && ques[i].a2 == s[j].a2))
			{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}
