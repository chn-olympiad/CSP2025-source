#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
struct Node
{
	string a, b;
}c[N];
long long ans = 0;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> c[i].a >> c[i].b;
	for (int qq = 1; qq <= q; qq++)
	{
		ans = 0;
		string aa, bb;
		cin >> aa >> bb;
		if (aa.size() != bb.size())
		{
			cout << 0 << endl;
			continue;
		}
		int l = -1, r;
		for (int i = 0; i < aa.size(); i++)
		{
			if (aa[i] == bb[i] == 'b')
			{
				l = r = i;
				break;
			}
			if (aa[i] != bb[i] && l == -1)
				l = i;
			else if (aa[i] != bb[i] && l != -1)
			{
				r = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < c[i].a.size(); j++)
			{
				if (c[i].b[j] == 'b')
				{
					swap(c[i].a, c[i].b);
					break;
				}
				if (c[i].a[j] == 'b')
					break;
			}
			for (int j = 0; j < c[i].a.size(); j++)
			{
				if (c[i].a[j] == c[i].b[j + r - l] == 'b')
				{
					if (l >= j && aa.size() - r + 1 >= c[i].b.size() - j - r + l + 1)
						ans ++;
				}
				if (c[i].a[j] == 'b')
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
