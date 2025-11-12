#include <bits/stdc++.h>
using namespace std;
int n,q;
long long sum;
string a[10001],b[10004];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> b[i];
	}
	cin >> q;
	while (q--)
	{
		cin >> t1 >> t2;
		sum = 0;
		if (t1.length() != t2.length())
		{
			cout << 0 << endl;
		}
		for (int i = 1;i <= n;i++)
		{
			if (t1 == a[i] && t2 == b[i])
			{
				sum++;
			}
		}
		for (int i = 0;i < t1.length();i++)
		{
			if (t1[i] != t2[i])
			{
				for (int j = 1;j <= 2;j++)
				{
					if (t1.find(a[j]))sum++;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
