#include <bits/stdc++.h>
using namespace std;
int n, q;
string a[200005][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i][1] >> a[i][2];
	}
	for (int i = 1;i <= q;i++)
	{
		string aa, bb;
		cin >> aa >> bb;
		int ans = 0;
		for (int k = 1;k <= n;k++)
		{
			for (int j = 0;j < aa.size();j++)
			{
				if (aa[j] == a[k][1][0])
				{
					string qqq;
					for (int l = j;l < j+a[k][1].size();l++)
					{
						qqq+=bb[l];
					}
					if (qqq == a[k][2]) ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb

