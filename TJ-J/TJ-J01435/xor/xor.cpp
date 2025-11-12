#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[1048580], s[500005], a[500005];
struct node
{
	int l, r;
}x[500005];
bool cmp(node x, node y)
{
	if (x.r != y.r) return x.r < y.r;
	return x.l > y.l;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int m = 0;
    cnt[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
    	cin >> a[i];
    	s[i] = (s[i - 1] ^ a[i]);
    	if (cnt[(s[i] ^ k)] > 0 || (s[i] ^ k) == 0)
    	{
    		x[++m].r = i;
    		x[m].l = cnt[(s[i] ^ k)] + 1;
		}
    	cnt[s[i]] = i;
	}
	sort(x + 1, x + m + 1, cmp);
	if (m == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int cn = 1, last = x[1].r;
	for (int i = 2; i <= m; ++i)
	{
		if (x[i].l > last)
		{
			++cn;
			last = x[i].r;
		}
	}
	cout << cn << endl;
    return 0;
}
